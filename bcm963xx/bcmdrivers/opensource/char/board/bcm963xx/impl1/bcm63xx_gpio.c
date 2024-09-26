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
* File Name  : bcm63xx_gpio.c
*
* Description: This file contains functions related to GPIO access.
*     See GPIO register defs in shared/broadcom/include/bcm963xx/xxx_common.h
*
*
***************************************************************************/

/*
 * Access to _SHARED_ GPIO registers should go through common functions
 * defined in board.h.  These common functions will use a spinlock with
 * irq's disabled to prevent concurrent access.
 * Functions which don't want to call the common gpio access functions must
 * acquire the bcm_gpio_spinlock with irq's disabled before accessing the
 * shared GPIO registers.
 * The GPIO registers that must be protected are:
 * GPIO->GPIODir
 * GPIO->GPIOio
 * GPIO->GPIOMode
 *
 * Note that many GPIO registers are dedicated to some driver or sub-system.
 * In those cases, the driver/sub-system can use its own locking scheme to
 * ensure serial access to its GPIO registers.
 *
 * DEFINE_SPINLOCK is the new, recommended way to declaring a spinlock.
 * See spinlock_types.h
 *
 * I am using a spin_lock_irqsave/spin_lock_irqrestore to lock and unlock
 * so that GPIO's can be accessed in interrupt context.
 */
#include <linux/version.h>
#include <linux/errno.h>
#include <linux/smp.h>
#include <linux/gpio.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,2,0)
#include <linux/module.h>
#include <linux/cache.h>
#endif

#include "bcm_map_part.h"
#include "bcm_assert_locks.h"
#include "board.h"
#include "shared_utils.h"
#include "bcm_gpio.h"
#include "boardparms.h"


DEFINE_SPINLOCK(bcm_gpio_spinlock);
EXPORT_SYMBOL(bcm_gpio_spinlock);


void kerSysSetGpioStateLocked(unsigned short bpGpio, GPIO_STATE_t state)
{
    BCM_ASSERT_V(bpGpio != BP_NOT_DEFINED);
    BCM_ASSERT_V((bpGpio & BP_GPIO_NUM_MASK) < GPIO_NUM_MAX);
    BCM_ASSERT_HAS_SPINLOCK_V(&bcm_gpio_spinlock);

    kerSysSetGpioDirLocked(bpGpio);

#if defined(CONFIG_BCM963268) 
    /* Take over high GPIOs from WLAN block */
    if ((bpGpio & BP_GPIO_NUM_MASK) > 35)
        GPIO->GPIOCtrl |= GPIO_NUM_TO_MASK(bpGpio - 32);
#endif

    if((state == kGpioActive && !(bpGpio & BP_ACTIVE_LOW)) ||
        (state == kGpioInactive && (bpGpio & BP_ACTIVE_LOW))) {
#if defined(CONFIG_BCM96838) 
        gpio_set_data((bpGpio & BP_GPIO_NUM_MASK), 1);
#elif defined(CONFIG_BCM963268)
        GPIO->GPIOio |= GPIO_NUM_TO_MASK(bpGpio);
#else
        bcm_gpio_set_data((bpGpio & BP_GPIO_NUM_MASK), 1);
#endif
    }
    else {
#if defined(CONFIG_BCM96838) 
        gpio_set_data((bpGpio & BP_GPIO_NUM_MASK), 0);
#elif defined(CONFIG_BCM963268)
        GPIO->GPIOio &= ~GPIO_NUM_TO_MASK(bpGpio);
#else
        bcm_gpio_set_data((bpGpio & BP_GPIO_NUM_MASK), 0);
#endif
    }
}

void kerSysSetGpioState(unsigned short bpGpio, GPIO_STATE_t state)
{
    unsigned long flags;

    spin_lock_irqsave(&bcm_gpio_spinlock, flags);
    kerSysSetGpioStateLocked(bpGpio, state);
    spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);
}



void kerSysSetGpioDirLocked(unsigned short bpGpio)
{
    BCM_ASSERT_V(bpGpio != BP_NOT_DEFINED);
    BCM_ASSERT_V((bpGpio & BP_GPIO_NUM_MASK) < GPIO_NUM_MAX);
    BCM_ASSERT_HAS_SPINLOCK_V(&bcm_gpio_spinlock);

#if   defined(CONFIG_BCM96838) 
    gpio_set_dir(bpGpio & BP_GPIO_NUM_MASK, 1);
#elif defined(CONFIG_BCM963268)
    GPIO->GPIODir |= GPIO_NUM_TO_MASK(bpGpio);
#else
    bcm_gpio_set_dir(bpGpio, 1);
#endif
}

void kerSysSetGpioDir(unsigned short bpGpio)
{
    unsigned long flags;

    spin_lock_irqsave(&bcm_gpio_spinlock, flags);
    kerSysSetGpioDirLocked(bpGpio);
    spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);
}


/* Set gpio direction to input. Parameter gpio is in boardparms.h format. */
int kerSysSetGpioDirInput(unsigned short bpGpio)
{
    unsigned long flags;

    spin_lock_irqsave(&bcm_gpio_spinlock, flags);
  //  GPIO_TAKE_CONTROL(bpGpio & BP_GPIO_NUM_MASK);

#if defined(CONFIG_BCM963268) 
    /* Take over high GPIOs from WLAN block */
    if ((bpGpio & BP_GPIO_NUM_MASK) > 35)
        GPIO->GPIOCtrl |= GPIO_NUM_TO_MASK(bpGpio - 32);
#endif

#if defined(CONFIG_BCM96838) 
    gpio_set_dir(bpGpio & BP_GPIO_NUM_MASK, 0);
#elif defined(CONFIG_BCM963268)
    GPIO->GPIODir &= ~GPIO_NUM_TO_MASK(bpGpio);
#else
    bcm_gpio_set_dir(bpGpio, 0);
#endif
    spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);

    return(0);
}

/* Return a gpio's value, 0 or 1. Parameter gpio is in boardparms.h format. */
int kerSysGetGpioValue(unsigned short bpGpio)
{
#if defined(CONFIG_BCM96838) 
    return gpio_get_data(bpGpio & BP_GPIO_NUM_MASK);
#elif defined(CONFIG_BCM963268)
    return((int) ((GPIO->GPIOio & GPIO_NUM_TO_MASK(bpGpio)) >>
        (bpGpio & BP_GPIO_NUM_MASK)));
#else
    return bcm_gpio_get_data(bpGpio);
#endif
}

#if defined(CONFIG_GPIOLIB)
/* GPIO bit functions to support drivers/i2c/busses/i2c-gpio.c */

#define GPIO_TAKE_CONTROL(G) 

/* noop */
static int bcm_gpio_request(unsigned bpGpio, const char *label)
{
    return(0); /* success */
}

/* noop */
static void bcm_gpio_free(unsigned bpGpio)
{
}

/* Assign a gpio's value. Parameter gpio is in boardparms.h format. */
static void bcm963xx_gpio_set_value(struct gpio_chip *chip, unsigned bpGpio, int value)
{
    unsigned long flags;

    /* value should be either 0 or 1 */
    spin_lock_irqsave(&bcm_gpio_spinlock, flags);

#if   defined(CONFIG_BCM96838) 
    gpio_set_data(bpGpio & BP_GPIO_NUM_MASK, value);
#elif defined(CONFIG_BCM963268)
    GPIO_TAKE_CONTROL(bpGpio & BP_GPIO_NUM_MASK);
    if( value == 0 )
        GPIO->GPIOio &= ~GPIO_NUM_TO_MASK(bpGpio);
    else
        if( value == 1 )
            GPIO->GPIOio |= GPIO_NUM_TO_MASK(bpGpio);
#else
    bcm_gpio_set_data(bpGpio, value);
#endif

    spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);
}

/* Set gpio direction to input. Parameter gpio is in boardparms.h format. */
static int bcm963xx_gpio_direction_input(struct gpio_chip *chip, unsigned bpGpio)
{
    unsigned long flags;

    spin_lock_irqsave(&bcm_gpio_spinlock, flags);

#if   defined(CONFIG_BCM96838) 
    gpio_set_dir(bpGpio & BP_GPIO_NUM_MASK, 0);
#elif defined(CONFIG_BCM963268)
    GPIO_TAKE_CONTROL(bpGpio & BP_GPIO_NUM_MASK);
    GPIO->GPIODir &= ~GPIO_NUM_TO_MASK(bpGpio);
#else
    bcm_gpio_set_dir(bpGpio, 0);
#endif

    spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);
    return(0);
}

/* Set gpio direction to output. Parameter gpio is in boardparms.h format. */
static int bcm963xx_gpio_direction_output(struct gpio_chip *chip, unsigned bpGpio, int value)
{
    unsigned long flags;

    spin_lock_irqsave(&bcm_gpio_spinlock, flags);

#if   defined(CONFIG_BCM96838) 
    gpio_set_dir(bpGpio & BP_GPIO_NUM_MASK, 1);
#elif defined(CONFIG_BCM963268)
    GPIO_TAKE_CONTROL(bpGpio & BP_GPIO_NUM_MASK);
    GPIO->GPIODir |= GPIO_NUM_TO_MASK(bpGpio);
#else
    bcm_gpio_set_dir(bpGpio, 1);
#endif

    spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);

    gpio_set_value(bpGpio, value);

    return(0);
}

/* Return a gpio's value, 0 or 1. Parameter gpio is in boardparms.h format. */
static int bcm963xx_gpio_get_value(struct gpio_chip *chip, unsigned bpGpio)
{
#if defined(CONFIG_BCM963268) || defined(CONFIG_BCM947189) 
    unsigned long flags;

    spin_lock_irqsave(&bcm_gpio_spinlock, flags);
    GPIO_TAKE_CONTROL(bpGpio & BP_GPIO_NUM_MASK);
    spin_unlock_irqrestore(&bcm_gpio_spinlock, flags);
#endif

#if   defined(CONFIG_BCM96838) 
    return gpio_get_data(bpGpio & BP_GPIO_NUM_MASK);
#elif defined(CONFIG_BCM963268)
    return((int) ((GPIO->GPIOio & GPIO_NUM_TO_MASK(bpGpio)) >>
        (bpGpio & BP_GPIO_NUM_MASK)));
#else
    return(bcm_gpio_get_data(bpGpio));
#endif

}

static struct gpio_chip bcm963xx_gpio_chip = {
	.label                  = "bcm963xx-gpio",
	.direction_input        = bcm963xx_gpio_direction_input,
	.direction_output       = bcm963xx_gpio_direction_output,
	.get                    = bcm963xx_gpio_get_value,
	.set                    = bcm963xx_gpio_set_value,
	.ngpio                  = 140,
	.base                   = 0,
};

static int gpio_init( void );
static int gpio_init( void )
{
	gpiochip_add(&bcm963xx_gpio_chip);
	return 0;
}

module_init(gpio_init);

static int bcm_gpio_to_irq(unsigned gpio);
static int bcm_gpio_to_irq(unsigned gpio)
{
	/* GPIO can never have been requested or set as input */
	WARN_ON(1);
	return -EINVAL;
}


//int gpio_to_irq(unsigned gpio)
//{
//	return __gpio_to_irq(gpio);
//}

void my_dummy(void );
void my_dummy()
{
	int a = 0;
	const char b[10];
	bcm_gpio_request(a,b);
	bcm_gpio_free(a);
	bcm_gpio_to_irq(a);
}
#endif /* defined(CONFIG_GPIOLIB) */



EXPORT_SYMBOL(kerSysSetGpioState);
EXPORT_SYMBOL(kerSysSetGpioStateLocked);
EXPORT_SYMBOL(kerSysSetGpioDir);
EXPORT_SYMBOL(kerSysSetGpioDirLocked);
EXPORT_SYMBOL(kerSysSetGpioDirInput);
EXPORT_SYMBOL(kerSysGetGpioValue);

