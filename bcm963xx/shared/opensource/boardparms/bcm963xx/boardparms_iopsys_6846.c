/* Keep Iopsys board params separated from Broadcoms'
 * for easy porting when they release a new SDK version. */

#include "bp_defs.h"
#include "boardparms.h"
#include "bcmSpiRes.h"
#include "boardparms_voice.h"
#include "boardparms_iopsys.h"


//=============================================================
// PINOUT BOARD PARAMS
//-------------------------------------------------------------
static bp_elem_t g_XG6846B[] = {
	{bp_cpBoardId,               .u.cp = "XG6846B"},
	{bp_usSerialLedData,		   .u.us = BP_GPIO_23_AH},
	{bp_usSerialLedClk, 		   .u.us = BP_GPIO_18_AH},
	{bp_usSerialLedMask,		   .u.us = BP_GPIO_25_AH},
	{bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
	{bp_ucPhyAddress,            .u.uc = 0x0},
	{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
	{bp_ulPortMap,               .u.ul = 0x1f},
	{bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
	{bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_7_AL},
	{bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_FAE},
	{bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_FAE},
	{bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_8_AL},
	{bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_1G},
	{bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_1G},
	{bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
	{bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_9_AL},
	{bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_FAE},
	{bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_FAE},
	{bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_10_AL},
	{bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_1G},
	{bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_1G},
	{bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
	{bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_11_AL},
	{bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_FAE},
	{bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_FAE},
	{bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_12_AL},
	{bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_1G},
	{bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_1G},
	{bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
	{bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_13_AL},
	{bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_FAE},
	{bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_FAE},
	{bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_14_AL},
	{bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_1G},
	{bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_1G},
	{bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
	{bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
	{bp_usMiiMdc,                .u.us = BP_GPIO_54_AH},
	{bp_usMiiMdio,               .u.us = BP_GPIO_55_AH},
	{bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT },
//	{bp_usGpioPonTxEn,           .u.us = BP_GPIO_40_AH},
	{bp_usGpioReserved,          .u.us = BP_GPIO_40_AL},
	{bp_usRogueOnuEn,            .u.us = BP_GPIO_14_AH},
//	{bp_usGpioWanSignalDetected, .u.us = BP_GPIO_15_AH},  // LOS doesnt work well together with copper wan
	{bp_usButtonIdx,             .u.us = 0},
	{bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
	{bp_usGpio_Intr,             .u.us = BP_GPIO_41_AL},  // button reset for Linux
	{bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
//  {bp_usPonLbe,                .u.us = BP_GPIO_67_AL},
	{bp_usGpioReserved,          .u.us = BP_GPIO_67_AL},
	{bp_usGpioI2cScl,            .u.us = BP_GPIO_68_AH},
	{bp_usGpioI2cSda,            .u.us = BP_GPIO_69_AH},
	{bp_usUsbPwrFlt0,            .u.us = BP_GPIO_74_AL},
	{bp_usUsbPwrOn0,             .u.us = BP_GPIO_75_AL},
	{bp_usUsbPwrFlt1,            .u.us = BP_GPIO_76_AL},
	{bp_usUsbPwrOn1,             .u.us = BP_GPIO_77_AL},
	// Not controlled by the SOC
	{bp_usGpioLedReserved,       .u.us = BP_GPIO_0_AL},
	{bp_usGpioLedReserved,       .u.us = BP_GPIO_1_AL},
	{bp_usGpioLedReserved,       .u.us = BP_GPIO_2_AL},
	{bp_usGpioLedReserved,       .u.us = BP_GPIO_3_AL},        // TX_DIS manual override
	{bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_0_AL}, // rgmii led pin0
	{bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_1_AL}, // rgmii led pin1
	{bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_2_AL}, // unused
	{bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL}, // WAN_LINK_LED_01
	{bp_usGpioSecLedAdsl,        .u.us = BP_SERIAL_GPIO_4_AL}, // WAN_LINK_LED_00
	{bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_5_AL}, // POWER_ON_LED
	{bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_6_AL}, // ALARM_LED
	{bp_usGpioDectLed,           .u.us = BP_SERIAL_GPIO_15_AL},// USB0_LED
	{bp_ucDspAddress,            .u.uc = 0},
	{bp_last}
};

#ifndef BP_DDR_PCB_2LAYER
#define BP_DDR_PCB_2LAYER 0
#endif

static bp_elem_t g_FT3401[] = {
  {bp_cpBoardId,               .u.cp = "FT-P3410B"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usSerialLedData,         .u.us = BP_GPIO_23_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_18_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_25_AH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_20_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_21_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_22_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_23_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_24_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_25_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_PCB_2LAYER},
  {bp_usButtonIdx,             .u.us = 0},
  {bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_41_AL},  // button reset for Linux
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_23_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_55_AL},

//  {bp_usPonLbe,                .u.us = BP_GPIO_67_AL},
  {bp_usGpioReserved,          .u.us = BP_GPIO_67_AL},
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_68_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_69_AH},
  {bp_usUsbPwrFlt0,            .u.us = BP_GPIO_74_AL},
  {bp_usUsbPwrOn0,             .u.us = BP_GPIO_75_AL},
  {bp_usUsbPwrFlt1,            .u.us = BP_GPIO_76_AL},
  {bp_usUsbPwrOn1,             .u.us = BP_GPIO_77_AL},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_4_AH},
  {bp_usRogueOnuEn,            .u.us = BP_GPIO_14_AH},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_4_AL},

//  {bp_usGpioPmdReset,          .u.us = BP_GPIO_40_AL},
  {bp_usGpioReserved,          .u.us = BP_GPIO_40_AL},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_REG_DISABLED | BP_PMD_APD_TYPE_BOOST},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_usGpioReserved,          .u.us = BP_GPIO_22_AL},
  {bp_usGpioReserved,          .u.us = BP_GPIO_48_AL},  // button dimming
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_26_AL}, // LED_ALARM_R
  {bp_usGpioSecLedAdsl,        .u.us = BP_SERIAL_GPIO_27_AL}, // LED_PWR_G
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_28_AL}, // LED_PON_G
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_29_AL}, // LED_CATV_G
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_last}
};



IOPSYSWRT_ADD_G_BOARDPARMS(g_XG6846B);
IOPSYSWRT_ADD_G_BOARDPARMS(g_FT3401);
