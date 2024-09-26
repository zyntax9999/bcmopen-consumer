/*
* <:copyright-BRCM:2016:DUAL/GPL:standard
* 
*    Copyright (c) 2016 Broadcom 
*    All Rights Reserved
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License, version 2, as published by
* the Free Software Foundation (the "GPL").
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* 
* A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
* writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
* Boston, MA 02111-1307, USA.
* 
* :> 
*/


/***************************************************************************
 * File Name  : bcm63xx_led.c
 *
 * Description: 
 *    This file contains bcm963xx board led control API functions. 
 *
 ***************************************************************************/

/* Includes. */
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/capability.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/netdevice.h>
#include <asm/uaccess.h>
#include <linux/version.h>
#include <linux/leds.h>

#include <bcm_assert_locks.h>
#include <bcm_map_part.h>
#include <board.h>
#include <boardparms.h>
#include <shared_utils.h>
#include <bcm_led.h>
#include <bcmtypes.h>

extern spinlock_t bcm_gpio_spinlock;

#define kFastBlinkCount     0          // 125ms
#define kSlowBlinkCount     1          // 250ms

#define kLedOff             0
#define kLedOn              1

#define kLedGreen           0
#define kLedRed             1

// uncomment // for debug led
// #define DEBUG_LED

typedef int (*BP_LED_FUNC) (unsigned short *);

typedef struct {
    BOARD_LED_NAME ledName;
    BP_LED_FUNC bpFunc;
    BP_LED_FUNC bpFuncFail;
} BP_LED_INFO, *PBP_LED_INFO;

typedef struct {
    short ledGreenGpio;             // GPIO # for LED
    short ledRedGpio;               // GPIO # for Fail LED
    BOARD_LED_STATE ledState;       // current led state
    short blinkCountDown;           // Count for blink states
} LED_CTRL, *PLED_CTRL;

static BP_LED_INFO bpLedInfo[] =
{
    {kLedAdsl, BpGetAdslLedGpio, BpGetAdslFailLedGpio},
    {kLedSecAdsl, BpGetSecAdslLedGpio, BpGetSecAdslFailLedGpio},
    {kLedWanData, BpGetWanDataLedGpio, BpGetWanErrorLedGpio},
    {kLedSes, BpGetWirelessSesLedGpio, NULL},
    {kLedVoip, BpGetVoipLedGpio, NULL},
    {kLedVoip1, BpGetVoip1LedGpio, BpGetVoip1FailLedGpio},
    {kLedVoip2, BpGetVoip2LedGpio, BpGetVoip2FailLedGpio},
    {kLedPots, BpGetPotsLedGpio, NULL},
    {kLedDect, BpGetDectLedGpio, NULL},
    {kLedGpon, BpGetGponLedGpio, BpGetGponFailLedGpio},
    {kLedMoCA, BpGetMoCALedGpio, BpGetMoCAFailLedGpio},
    {kLedWL0, BpGetWL0ActLedGpio, NULL},
    {kLedWL1, BpGetWL1ActLedGpio, NULL},
#if defined(CONFIG_BCM_PON) || defined(CONFIG_BCM963158)
    {kLedOpticalLink,  NULL, BpGetOpticalLinkFailLedGpio},
    {kLedUSB, BpGetUSBLedGpio, NULL},
    {kLedSim, BpGetGpioLedSim, NULL},
    {kLedSimITMS, BpGetGpioLedSimITMS, NULL},
    {kLedEpon, BpGetEponLedGpio, BpGetEponFailLedGpio},
#endif
    {kLedEnd, NULL, NULL}
};

// global variables:
static struct timer_list gLedTimer;
static PLED_CTRL gLedCtrl = NULL;
static int gTimerOn = FALSE;
static int gTimerOnRequests = 0;
static unsigned int gLedRunningCounter = 0;  // only used by WLAN

int g_ledInitialized = 0;

void (*ethsw_led_control)(unsigned long ledMask, int value) = NULL;
EXPORT_SYMBOL(ethsw_led_control);

/** This spinlock protects all access to gLedCtrl, gTimerOn
 *  gTimerOnRequests, gLedRunningCounter, and ledTimerStart function.
 *  Use spin_lock_irqsave to lock the spinlock because ledTimerStart
 *  may be called from interrupt handler (WLAN?)
 */
static spinlock_t brcm_ledlock;
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 19, 0)
static void ledTimerExpire(void);
#else
static void ledTimerExpire(struct timer_list*);
#endif

//**************************************************************************************
// LED operations
//**************************************************************************************

// turn led on and set the ledState
static void setLed (PLED_CTRL pLed, unsigned short led_state, unsigned short led_type)
{
    short led_gpio;
    unsigned short gpio_state;
    unsigned long flags;


    if (led_type == kLedRed)
        led_gpio = pLed->ledRedGpio;
    else
        led_gpio = pLed->ledGreenGpio;

        dev_dbg(NULL,  "********************************************************\n");
        dev_dbg(NULL,  "setLed %d %x\n", led_gpio&0xff, led_gpio);
        dev_dbg(NULL,  "********************************************************\n");

    if (led_gpio == -1)
        return;

    if (((led_gpio & BP_ACTIVE_LOW) && (led_state == kLedOn)) || 
        (!(led_gpio & BP_ACTIVE_LOW) && (led_state == kLedOff)))
        gpio_state = 0;
    else
        gpio_state = 1;

    /* spinlock to protect access to GPIODir, GPIOio */
    spin_lock_irqsave(&bcm_gpio_spinlock, flags);

#if defined(CONFIG_BCM963268) 
    if (led_gpio & BP_LED_USE_GPIO) {
        /* This Led is a GPIO, set/unset led directly */
        /* Take over high GPIOs from WLAN block */
        if ((led_gpio & BP_GPIO_NUM_MASK) > 35)
            GPIO->GPIOCtrl |= GPIO_NUM_TO_MASK(led_gpio - 32);
        /* set led to output */
        GPIO->GPIODir |= GPIO_NUM_TO_MASK(led_gpio);
        /* set value */
        if( gpio_state )
            GPIO->GPIOio |= GPIO_NUM_TO_MASK(led_gpio);
        else
            GPIO->GPIOio &= ~GPIO_NUM_TO_MASK(led_gpio);
    } else {
        /* Enable LED controller to drive this GPIO */
        if (!(led_gpio & BP_GPIO_SERIAL))
            GPIO->LEDCtrl |= GPIO_NUM_TO_MASK(led_gpio);

        LED->ledMode &= ~(LED_MODE_MASK << GPIO_NUM_TO_LED_MODE_SHIFT(led_gpio));
        if( gpio_state )
            LED->ledMode |= (LED_MODE_OFF << GPIO_NUM_TO_LED_MODE_SHIFT(led_gpio));
        else
            LED->ledMode |= (LED_MODE_ON << GPIO_NUM_TO_LED_MODE_SHIFT(led_gpio));
    }
#elif defined(CONFIG_BCM96838)
    if ( (led_gpio&BP_LED_PIN) || (led_gpio&BP_GPIO_SERIAL) )
    {
        LED->ledMode &= ~(LED_MODE_MASK << GPIO_NUM_TO_LED_MODE_SHIFT(led_gpio));
        if( gpio_state )
            LED->ledMode |= (LED_MODE_OFF << GPIO_NUM_TO_LED_MODE_SHIFT(led_gpio));
        else
            LED->ledMode |= (LED_MODE_ON << GPIO_NUM_TO_LED_MODE_SHIFT(led_gpio));
    }
    else
    {
        led_gpio &= BP_GPIO_NUM_MASK;
        gpio_set_dir(led_gpio, 1);
        gpio_set_data(led_gpio, gpio_state);
    }
#else
    bcm_led_driver_set(led_gpio, led_state);
#endif

    spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);
}

// toggle the LED
static void ledToggle(PLED_CTRL pLed)
{
    short led_gpio;
    short green_led_gpio , red_led_gpio;

   green_led_gpio = pLed->ledGreenGpio ;
   red_led_gpio = pLed->ledRedGpio ;

    if ((-1== green_led_gpio) && (-1== red_led_gpio))
        return;

    /* Currently all the chips don't support blinking of RED LED */
    if (-1== green_led_gpio)
        return;
  
   led_gpio = green_led_gpio ;

#if defined(CONFIG_BCM963268)
    LED->ledMode ^= (LED_MODE_MASK << GPIO_NUM_TO_LED_MODE_SHIFT(led_gpio));
#elif defined(CONFIG_BCM96838)
    if ( (led_gpio&BP_LED_PIN) || (led_gpio&BP_GPIO_SERIAL) )
        LED->ledMode ^= (LED_MODE_MASK << GPIO_NUM_TO_LED_MODE_SHIFT(led_gpio));
    else
    {
        unsigned long flags;
		led_gpio &= BP_GPIO_NUM_MASK;
        spin_lock_irqsave(&bcm_gpio_spinlock, flags);
        gpio_set_data(led_gpio, 1^gpio_get_data(led_gpio));
        spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);
    }
#elif defined(CONFIG_BCM960333)
    {
        unsigned long flags;
        led_gpio &= BP_GPIO_NUM_MASK;
        spin_lock_irqsave(&bcm_gpio_spinlock, flags);
        bcm_led_driver_toggle(led_gpio);
        spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);
    }
#else
    bcm_led_driver_toggle(led_gpio);
#endif
}   

static unsigned short getLed (PLED_CTRL pLed, unsigned short led_type)
{
    short led_gpio;
    unsigned short led_state = 0;
    unsigned long flags;


    if (led_type == kLedRed)
        led_gpio = pLed->ledRedGpio;
    else
        led_gpio = pLed->ledGreenGpio;

        dev_dbg(NULL,  "********************************************************\n");
        dev_dbg(NULL,  "getLed %d %x\n", led_gpio&0xff, led_gpio);
        dev_dbg(NULL,  "********************************************************\n");

    if (led_gpio == -1)
        return 0;

    /* spinlock to protect access to GPIODir, GPIOio */
    spin_lock_irqsave(&bcm_gpio_spinlock, flags);

#if defined(CONFIG_BCM963268)
    if (led_gpio & BP_LED_USE_GPIO) {
        /* This Led is a GPIO, set/unset led directly */
        /* Take over high GPIOs from WLAN block */
        if ((led_gpio & BP_GPIO_NUM_MASK) > 35)
            GPIO->GPIOCtrl |= GPIO_NUM_TO_MASK(led_gpio - 32);
        /* set led to output */
        GPIO->GPIODir |= GPIO_NUM_TO_MASK(led_gpio);
	led_state = (GPIO->GPIOio & GPIO_NUM_TO_MASK(led_gpio));
    } else {
        /* Enable LED controller to drive this GPIO */
        if (!(led_gpio & BP_GPIO_SERIAL))
            GPIO->LEDCtrl |= GPIO_NUM_TO_MASK(led_gpio);

	led_state = (LED->ledMode & (LED_MODE_MASK << GPIO_NUM_TO_LED_MODE_SHIFT(led_gpio)));
    }
#elif defined(CONFIG_BCM96838)
    if ( (led_gpio&BP_LED_PIN) || (led_gpio&BP_GPIO_SERIAL) )
    {
	led_state = (LED->ledMode & (LED_MODE_MASK << GPIO_NUM_TO_LED_MODE_SHIFT(led_gpio)));
    }
    else
    {
        led_gpio &= BP_GPIO_NUM_MASK;
        gpio_set_dir(led_gpio, 1);
        led_state = gpio_get_data(led_gpio);
    }
#elif defined(CONFIG_BCM963178)
	/* FIXME: need to initialize led_state variable here */ 
#else
    led_state = bcm_led_driver_get(led_gpio);
#endif

    spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);
    return led_state;
}

static void setBrightness (PLED_CTRL pLed,  unsigned short led_type, enum led_brightness brightness)
{
    short led_gpio;

    if (led_type == kLedRed)
        led_gpio = pLed->ledRedGpio;
    else
        led_gpio = pLed->ledGreenGpio;

#if !defined(CONFIG_BCM963178)
    /* FIXME: bcm_led_driver_brightness() function should be imnplemented in bcm_led_impl4.c */
    bcm_led_driver_brightness(led_gpio, (unsigned char)brightness);
#endif
    return;
}

/** Start the LED timer
 *
 * Must be called with brcm_ledlock held
 */
static void ledTimerStart(void)
{
#if defined(DEBUG_LED)
    printk("led: add_timer\n");
#endif

    BCM_ASSERT_HAS_SPINLOCK_C(&brcm_ledlock);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 19, 0)
    init_timer(&gLedTimer);
    gLedTimer.function = (void*)ledTimerExpire;
#else
    timer_setup(&gLedTimer, ledTimerExpire, 0);
#endif
    gLedTimer.expires = jiffies + msecs_to_jiffies(125);        // timer expires in ~125ms
    add_timer (&gLedTimer);
} 


// led timer expire kicks in about ~100ms and perform the led operation according to the ledState and
// restart the timer according to ledState
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 19, 0)
static void ledTimerExpire(void)
#else
static void ledTimerExpire(struct timer_list *tl)
#endif
{
    int i;
    PLED_CTRL pCurLed;
    unsigned long flags;

    BCM_ASSERT_NOT_HAS_SPINLOCK_V(&brcm_ledlock);

    for (i = 0, pCurLed = gLedCtrl; i < kLedEnd; i++, pCurLed++)
    {
#if defined(DEBUG_LED)
        printk("led[%d]: Mask=0x%04x, State = %d, blcd=%d\n", i, pCurLed->ledGreenGpio, pCurLed->ledState, pCurLed->blinkCountDown);
#endif
        spin_lock_irqsave(&brcm_ledlock, flags);        // LEDs can be changed from ISR
        switch (pCurLed->ledState)
        {
        case kLedStateOn:
        case kLedStateOff:
        case kLedStateFail:
            pCurLed->blinkCountDown = 0;            // reset the blink count down
            spin_unlock_irqrestore(&brcm_ledlock, flags);
            break;

        case kLedStateSlowBlinkContinues:
            if (pCurLed->blinkCountDown-- == 0)
            {
                pCurLed->blinkCountDown = kSlowBlinkCount;
                ledToggle(pCurLed);
            }
            gTimerOnRequests++;
            spin_unlock_irqrestore(&brcm_ledlock, flags);
            break;

        case kLedStateFastBlinkContinues:
            if (pCurLed->blinkCountDown-- == 0)
            {
                pCurLed->blinkCountDown = kFastBlinkCount;
                ledToggle(pCurLed);
            }
            gTimerOnRequests++;
            spin_unlock_irqrestore(&brcm_ledlock, flags);
            break;

        case kLedStateUserWpsInProgress:          /* 200ms on, 100ms off */
            if (pCurLed->blinkCountDown-- == 0)
            {
                pCurLed->blinkCountDown = (((gLedRunningCounter++)&1)? kFastBlinkCount: kSlowBlinkCount);
                ledToggle(pCurLed);
            }
            gTimerOnRequests++;
            spin_unlock_irqrestore(&brcm_ledlock, flags);
            break;             

        case kLedStateUserWpsError:               /* 100ms on, 100ms off */
            if (pCurLed->blinkCountDown-- == 0)
            {
                pCurLed->blinkCountDown = kFastBlinkCount;
                ledToggle(pCurLed);
            }
            gTimerOnRequests++;
            spin_unlock_irqrestore(&brcm_ledlock, flags);
            break;        

        case kLedStateUserWpsSessionOverLap:      /* 100ms on, 100ms off, 5 times, off for 500ms */        
            if (pCurLed->blinkCountDown-- == 0)
            {
                if(((++gLedRunningCounter)%10) == 0) {
                    pCurLed->blinkCountDown = 4;
                    setLed(pCurLed, kLedOff, kLedGreen);
                    pCurLed->ledState = kLedStateUserWpsSessionOverLap;
                }
                else
                {
                    pCurLed->blinkCountDown = kFastBlinkCount;
                    ledToggle(pCurLed);
                }
            }
            gTimerOnRequests++;
            spin_unlock_irqrestore(&brcm_ledlock, flags);
            break;        

        default:
            spin_unlock_irqrestore(&brcm_ledlock, flags);
            printk("Invalid state = %d\n", pCurLed->ledState);
        }
    }

    // Restart the timer if any of our previous LED operations required
    // us to restart the timer, or if any other threads requested a timer
    // restart.  Note that throughout this function, gTimerOn == TRUE, so
    // any other thread which want to restart the timer would only
    // increment the gTimerOnRequests and not call ledTimerStart.
    spin_lock_irqsave(&brcm_ledlock, flags);
    if (gTimerOnRequests > 0)
    {
        ledTimerStart();
        gTimerOnRequests = 0;
    }
    else
    {
        gTimerOn = FALSE;
    }
    spin_unlock_irqrestore(&brcm_ledlock, flags);
}

void __init boardLedInit(void)
{
    PBP_LED_INFO pInfo;
    unsigned short i;
    short gpio;

    spin_lock_init(&brcm_ledlock);

    gLedCtrl = (PLED_CTRL) kmalloc((kLedEnd * sizeof(LED_CTRL)), GFP_KERNEL);

    if( gLedCtrl == NULL ) {
        printk( "LED memory allocation error.\n" );
        return;
    }

    /* Initialize LED control */
    for (i = 0; i < kLedEnd; i++) {
        gLedCtrl[i].ledGreenGpio = -1;
        gLedCtrl[i].ledRedGpio = -1;
        gLedCtrl[i].ledState = kLedStateOff;
        gLedCtrl[i].blinkCountDown = 0;            // reset the blink count down
    }

    for( pInfo = bpLedInfo; pInfo->ledName != kLedEnd; pInfo++ ) {
        if( pInfo->bpFunc && (*pInfo->bpFunc) (&gpio) == BP_SUCCESS )
        {
            gLedCtrl[pInfo->ledName].ledGreenGpio = gpio;
        }
        if( pInfo->bpFuncFail && (*pInfo->bpFuncFail)(&gpio)==BP_SUCCESS )
        {
            gLedCtrl[pInfo->ledName].ledRedGpio = gpio;
        }
        setLed(&gLedCtrl[pInfo->ledName], kLedOff, kLedGreen);
        setLed(&gLedCtrl[pInfo->ledName], kLedOff, kLedRed);
    }

#if defined(DEBUG_LED)
    for (i=0; i < kLedEnd; i++)
        printk("initLed: led[%d]: Gpio=0x%04x, FailGpio=0x%04x\n", i, gLedCtrl[i].ledGreenGpio, gLedCtrl[i].ledRedGpio);
#endif
    g_ledInitialized = 1;
}

// led ctrl.  Maps the ledName to the corresponding ledInfoPtr and perform the led operation
void boardLedCtrl(BOARD_LED_NAME ledName, BOARD_LED_STATE ledState)
{
    unsigned long flags;
    PLED_CTRL pLed;

    BCM_ASSERT_NOT_HAS_SPINLOCK_V(&brcm_ledlock);

    spin_lock_irqsave(&brcm_ledlock, flags);     // LED can be changed from ISR

    if( (int) ledName < kLedEnd ) {

        pLed = &gLedCtrl[ledName];

        // If the state is kLedStateFail and there is not a failure LED defined
        // in the board parameters, change the state to kLedStateSlowBlinkContinues.
        if( ledState == kLedStateFail && pLed->ledRedGpio == -1 )
            ledState = kLedStateSlowBlinkContinues;

        // Save current LED state
        pLed->ledState = ledState;

        // Start from LED Off and turn it on later as needed
        setLed (pLed, kLedOff, kLedGreen);
        setLed (pLed, kLedOff, kLedRed);

        // Disable HW control for WAN Data LED. 
        // It will be enabled only if LED state is On
#if defined(CONFIG_BCM963268) || defined(CONFIG_BCM96838)
        if (ledName == kLedWanData)
            LED->ledHWDis |= GPIO_NUM_TO_MASK(pLed->ledGreenGpio);
#endif

        switch (ledState) {
        case kLedStateOn:
            // Enable SAR to control INET LED
#if defined(CONFIG_BCM963268) || defined(CONFIG_BCM96838)
            if (ledName == kLedWanData)
                LED->ledHWDis &= ~GPIO_NUM_TO_MASK(pLed->ledGreenGpio);
#endif
            setLed (pLed, kLedOn, kLedGreen);
            break;

        case kLedStateOff:
            break;

        case kLedStateFail:
            setLed (pLed, kLedOn, kLedRed);
            break;

        case kLedStateSlowBlinkContinues:
            pLed->blinkCountDown = kSlowBlinkCount;
            gTimerOnRequests++;
            break;

        case kLedStateFastBlinkContinues:
            pLed->blinkCountDown = kFastBlinkCount;
            gTimerOnRequests++;
            break;

        case kLedStateUserWpsInProgress:          /* 200ms on, 100ms off */
            pLed->blinkCountDown = kFastBlinkCount;
            gLedRunningCounter = 0;
            gTimerOnRequests++;
            break;             

        case kLedStateUserWpsError:               /* 100ms on, 100ms off */
            pLed->blinkCountDown = kFastBlinkCount;
            gLedRunningCounter = 0;
            gTimerOnRequests++;
            break;        

        case kLedStateUserWpsSessionOverLap:      /* 100ms on, 100ms off, 5 times, off for 500ms */
            pLed->blinkCountDown = kFastBlinkCount;
            gTimerOnRequests++;
            break;        

        default:
            printk("Invalid led state\n");
        }
    }

    // If gTimerOn is false, that means ledTimerExpire has already finished
    // running and has not restarted the timer.  Then we can start it here.
    // Otherwise, we only leave the gTimerOnRequests > 0 which will be
    // noticed at the end of the ledTimerExpire function.
    if (!gTimerOn && gTimerOnRequests > 0)
    {
        ledTimerStart();
        gTimerOn = TRUE;
        gTimerOnRequests = 0;
    }
    spin_unlock_irqrestore(&brcm_ledlock, flags);
}

#if defined(CONFIG_NEW_LEDS)
#define LED_AUTONAME_MAX_SIZE    25
#define MAX_LEDS 64


struct sysfsled {
    struct led_classdev cdev;
    int bcm_led_pin; /* This also means pins connected on a shift
    register controlled by the LED controller (see BP_GPIO_SERIAL).*/
    char name[LED_AUTONAME_MAX_SIZE];
    unsigned char led_is_hw;
};

struct sysfsled_ctx {
    int    num_leds;
    struct sysfsled leds[MAX_LEDS];
};

static struct sysfsled_ctx bcmctx = {0, {}};

#ifdef CONFIG_LEDS_TRIGGERS
#include <drivers/leds/leds.h>
struct testmode_trig_data {
	int active;
};

static enum led_brightness brightness_get(struct led_classdev *cdev);
static void brightness_set(struct led_classdev *cdev, enum led_brightness value);
static ssize_t testmode_active_show(struct device *dev, struct device_attribute *attr, char *buf);
static ssize_t testmode_active_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size);
static void testmode_trig_activate(struct led_classdev *cdev);
static void testmode_trig_deactivate(struct led_classdev *cdev);

static DEVICE_ATTR(active, 0644, testmode_active_show, testmode_active_store);

static ssize_t testmode_active_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct testmode_trig_data *testmode_data = cdev->trigger_data;

	if(testmode_data == NULL)
		return 0;
	else
		return sprintf(buf, "%d\n", testmode_data->active);
}

static ssize_t testmode_active_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct sysfsled *led = container_of(cdev,
                    struct sysfsled, cdev);
	struct testmode_trig_data *testmode_data = cdev->trigger_data;
	unsigned long active = 0;
	ssize_t ret = 0;

	ret = kstrtoul(buf, 10, &active);
	if(ret != 0)
		return ret;

	if(testmode_data != NULL)
		testmode_data->active = active;

	if(active == 0){
		cdev->activated = false;
		if(led->led_is_hw) {
			bcm_led_enable_hw(led->bcm_led_pin);
		}
		device_remove_file_self(cdev->dev, &dev_attr_active);
		if(testmode_data != NULL) {
			cdev->trigger_data = NULL;
			kfree(testmode_data);
		}
		led_trigger_remove(cdev);
	}

	return size;
}

static void testmode_trig_activate(struct led_classdev *cdev)
{
	struct sysfsled *led = container_of(cdev,
                    struct sysfsled, cdev);
	struct testmode_trig_data *tdata = NULL;
	LED_CTRL ledctrl = {.ledGreenGpio=led->bcm_led_pin};

	tdata = kzalloc(sizeof(struct testmode_trig_data), GFP_KERNEL);
	if(tdata == NULL) {
		dev_err(cdev->dev, "unable to allocate test-mode trigger\n");
		return;
	}
	tdata->active = 1;
	cdev->trigger_data = tdata;

	if(device_create_file(cdev->dev, &dev_attr_active) != 0) {
		dev_err(cdev->dev, "unable to register test-mode trigger\n");
		cdev->trigger_data = NULL;
		kfree(tdata);
		return;
	}

	led->led_is_hw = bcm_led_is_hw(led->bcm_led_pin);
	bcm_led_disable_hw(led->bcm_led_pin);
	setLed(&ledctrl, kLedOn, kLedGreen);

	cdev->activated = true;
	return;
}

static void testmode_trig_deactivate(struct led_classdev *cdev)
{

	struct sysfsled *led = container_of(cdev,
                    struct sysfsled, cdev);
	struct testmode_trig_data *testmode_data = cdev->trigger_data;

	if((testmode_data != NULL) && (testmode_data->active != 0))
		return;

	if(cdev->activated == true) {
		cdev->activated = false;
		if(led->led_is_hw) {
			bcm_led_enable_hw(led->bcm_led_pin);
		}
		device_remove_file(cdev->dev, &dev_attr_active);
		if(testmode_data != NULL) {
			cdev->trigger_data = NULL;
			kfree(testmode_data);
		}
	}
	return;
}

static struct led_trigger testmode_led_trigger = {
	.name		= "test-mode",
	.activate	= testmode_trig_activate,
	.deactivate	= testmode_trig_deactivate,
};
#endif

static int blink_set(struct led_classdev *cdev, unsigned long *delay_on, unsigned long *delay_off)
{
    /*struct sysfsled *led = container_of(cdev,
                    struct sysfsled, cdev);
    unsigned long delay, flags;*/
    int rc = -EINVAL;

    return rc;
}

static enum led_brightness brightness_get(struct led_classdev *cdev)
{
    struct sysfsled *led = container_of(cdev,
                    struct sysfsled, cdev);

    enum led_brightness value = LED_OFF;

    /* On Broadcom chips, LEDs connected to any kind of pin can be
     controlled via getLed. getLed only needs the pin ("GPIO") from
     the LED_CTRL argument. Fake a LED_CTRL to pass the pin to setLed.
     The color obviously doesn't matter here. */
    LED_CTRL ledctrl = {.ledGreenGpio=led->bcm_led_pin};
    value = getLed(&ledctrl, kLedGreen);
    return value;
}

static void brightness_set(struct led_classdev *cdev, enum led_brightness value)
{
    struct sysfsled *led = container_of(cdev,
                    struct sysfsled, cdev);

    /* On Broadcom chips, LEDs connected to any kind of pin can be
     controlled via setLed. setLed only needs the pin ("GPIO") from
     the LED_CTRL argument. Fake a LED_CTRL to pass the pin to setLed.
     The color obviously doesn't matter here. */
    LED_CTRL ledctrl = {.ledGreenGpio=led->bcm_led_pin};
    setLed(&ledctrl, (value != LED_OFF)?kLedOn:kLedOff, kLedGreen);
    setBrightness(&ledctrl, kLedGreen, value);
}

static void __exit bcmsysfsleds_unregister(void *opaque)
{
    struct sysfsled_ctx *ctx = opaque;
    int i;

#ifdef CONFIG_LEDS_TRIGGERS
    led_trigger_unregister(&testmode_led_trigger);
#endif

    for (i = 0; i < MAX_LEDS; i++) {
        led_classdev_unregister(&ctx->leds[i].cdev);
        if (ctx->leds[i].cdev.brightness_set) {
            ctx->leds[i].cdev.brightness_set = NULL;
        }
	if (ctx->leds[i].cdev.brightness_get) {
            ctx->leds[i].cdev.brightness_get = NULL;
	}
	if (bcmctx.leds[i].cdev.blink_set) {
            bcmctx.leds[i].cdev.blink_set = NULL;
	}
    }
}

static int __init bcmsysfsleds_register(int bcm_led_pin, char *led_name)
{
    int i;

    if (bcmctx.num_leds >= MAX_LEDS) {
        printk(KERN_ERR "Too many BCM LEDs registered.\n");
        return -ENOMEM;
    }

    if(led_name != NULL) {
        i = bcmctx.num_leds;
        snprintf(bcmctx.leds[i].name, LED_AUTONAME_MAX_SIZE-1,
            "%s_%d%c", led_name, bcm_led_pin&BP_GPIO_NUM_MASK, (bcm_led_pin&BP_GPIO_SERIAL)?'s':'\0');
        bcmctx.leds[i].cdev.name = bcmctx.leds[i].name;
        bcmctx.leds[i].cdev.brightness  = LED_OFF;
	bcmctx.leds[i].cdev.blink_set = blink_set;
	bcmctx.leds[i].cdev.brightness_get = brightness_get;
        bcmctx.leds[i].cdev.brightness_set = brightness_set;
        bcmctx.leds[i].bcm_led_pin = bcm_led_pin;
        bcmctx.leds[i].led_is_hw = 0;
        if (led_classdev_register(NULL, &bcmctx.leds[i].cdev)) {
            printk(KERN_ERR "BCM LEDs registration failed. %d\n", bcm_led_pin&BP_GPIO_NUM_MASK);
	    bcmctx.leds[i].cdev.blink_set = NULL;
	    bcmctx.leds[i].cdev.brightness_get = NULL;
            bcmctx.leds[i].cdev.brightness_set = NULL;
            return -1;
        }
        led_update_brightness(&bcmctx.leds[i].cdev);
        bcmctx.num_leds++;
    }

    i = bcmctx.num_leds;
    snprintf(bcmctx.leds[i].name, LED_AUTONAME_MAX_SIZE-1,
        "%d%c", bcm_led_pin&BP_GPIO_NUM_MASK, (bcm_led_pin&BP_GPIO_SERIAL)?'s':'\0');
    bcmctx.leds[i].cdev.name = bcmctx.leds[i].name;
    bcmctx.leds[i].cdev.brightness  = LED_OFF;
    bcmctx.leds[i].cdev.blink_set = blink_set;
    bcmctx.leds[i].cdev.brightness_get = brightness_get;
    bcmctx.leds[i].cdev.brightness_set = brightness_set;
    bcmctx.leds[i].bcm_led_pin = bcm_led_pin;
    bcmctx.leds[i].led_is_hw = 0;
    if (led_classdev_register(NULL, &bcmctx.leds[i].cdev)) {
        printk(KERN_ERR "BCM LEDs registration failed. %d\n", bcm_led_pin&BP_GPIO_NUM_MASK);
	bcmctx.leds[i].cdev.blink_set = NULL;
	bcmctx.leds[i].cdev.brightness_get = NULL;
        bcmctx.leds[i].cdev.brightness_set = NULL;
        return -1;
    }
    led_update_brightness(&bcmctx.leds[i].cdev);
    bcmctx.num_leds++;

    return 0;
}
#endif

int __init bcmsysfsleds_init(void)
{
#if defined(CONFIG_NEW_LEDS)
        unsigned short bcmledgpioid;
	int index=0, rc;
	void* token=NULL;
        char *ledName=NULL;
#ifdef CONFIG_LEDS_TRIGGERS
	led_trigger_register(&testmode_led_trigger);
#endif
        for(;;) {
                ledName=NULL;
                rc = BpGetLedName(index, &token,  &bcmledgpioid, &ledName);
                if (rc == BP_MAX_ITEM_EXCEEDED) {
                    break;
                }
                if(rc == BP_SUCCESS) {
                        bcmsysfsleds_register(bcmledgpioid, ledName);
                }
                else {
                        index++;
                        token=NULL;
                }
        }
#endif
        return 0;
}

void __exit bcmsysfsleds_exit(void)
{
#if defined(CONFIG_NEW_LEDS)
    int i;

#ifdef CONFIG_LEDS_TRIGGERS
    led_trigger_unregister(&testmode_led_trigger);
#endif

    for (i = 0; i < MAX_LEDS; i++) {
        led_classdev_unregister(&bcmctx.leds[i].cdev);
        if (bcmctx.leds[i].cdev.brightness_set) {
            bcmctx.leds[i].cdev.brightness_set = NULL;
        }
	if (bcmctx.leds[i].cdev.brightness_get) {
            bcmctx.leds[i].cdev.brightness_get = NULL;
        }
	if (bcmctx.leds[i].cdev.blink_set) {
            bcmctx.leds[i].cdev.blink_set = NULL;
	}
    }
#endif
}

module_init(bcmsysfsleds_init);
