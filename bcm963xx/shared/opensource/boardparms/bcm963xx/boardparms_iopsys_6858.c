
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
static bp_elem_t g_bcm968580xref_p400[] = {
  {bp_cpBoardId,                .u.cp = "968580XREF_P400"},
  {bp_usPcmSdin,                .u.us = BP_GPIO_0_AH},
  {bp_usPcmSdout,               .u.us = BP_GPIO_1_AH},
  {bp_usPcmClk,                 .u.us = BP_GPIO_2_AH},
  {bp_usPcmFs,                  .u.us = BP_GPIO_3_AH},
  {bp_usGpioUart2Sdin,          .u.us = BP_GPIO_16_AH},
  {bp_usGpioUart2Sdout,         .u.us = BP_GPIO_17_AH},
  {bp_usGpioUart2Cts,           .u.us = BP_GPIO_18_AH},
  {bp_usGpioUart2Rts,           .u.us = BP_GPIO_19_AH},
  {bp_usGpioI2c2Scl,            .u.us = BP_GPIO_23_AH},
  {bp_usGpioI2c2Sda,            .u.us = BP_GPIO_24_AH},
  {bp_usSerialLedData,          .u.us = BP_GPIO_29_AH},
  {bp_usSerialLedClk,           .u.us = BP_GPIO_30_AH},
  {bp_usSerialLedMask,          .u.us = BP_GPIO_31_AH},
  {bp_usGpioWanSignalDetected,  .u.us = BP_GPIO_49_AH},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_51_AH},
  {bp_usSpiSlaveSelectNum,      .u.us = 1},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 106},
  {bp_usSpiSlaveSelectNum,      .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 13},
#ifdef CONFIG_BCM_TIME_SYNC_MODULE
  {bp_usTsync1pps,              .u.us = BP_GPIO_11_AH | BP_NONGPIO_PIN},
  {bp_usGpioTsyncPonUnstable,   .u.us = BP_GPIO_12_AH},
  {bp_usUart1Sdin,              .u.us = BP_GPIO_27_AH},
  {bp_usUart1Sdout,             .u.us = BP_GPIO_28_AH},
#else
  {bp_usSpiSlaveSelectNum,      .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 12},
  {bp_usSpiSlaveSelectNum,      .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 11},
  {bp_usGpioI2CMux,             .u.us = BP_GPIO_27_AH},
#endif
  {bp_usExtIntrOpticalModulePresence, .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_BOTH_EDGE | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,              .u.us = BP_GPIO_32_AL},
  {bp_usGpioOpticalModuleTxPwrDown, .u.us = BP_GPIO_55_AH},
  {bp_usExtIntrSesBtnWireless,  .u.us = BP_EXT_INTR_4 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,              .u.us = BP_GPIO_53_AL},
  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_5 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,              .u.us = BP_GPIO_54_AL},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_56_AH},
  {bp_usI2sSdata,               .u.us = BP_GPIO_59_AH},
  {bp_usI2sSclk,                .u.us = BP_GPIO_60_AH},
  {bp_usI2sLrck,                .u.us = BP_GPIO_61_AH},
  {bp_ulInterfaceEnable,        .u.ul = BP_PINMUX_FNTYPE_LPORT},
  {bp_usUsbPwrOn0,              .u.us = BP_GPIO_113_AL},
  {bp_usUsbPwrFlt0,             .u.us = BP_GPIO_114_AL},
  {bp_usUsbPwrOn1,              .u.us = BP_GPIO_115_AL},
  {bp_usUsbPwrFlt1,             .u.us = BP_GPIO_116_AL},
  {bp_usGpioLedOpticalLinkFail, .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedGpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedEpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanData,         .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioVoip1Led,           .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioVoip2Led,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedUSB,             .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedUSB2,            .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_usGpioLedSesWireless,     .u.us = BP_SERIAL_GPIO_17_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_20_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_21_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_22_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_23_AL},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x0f},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId2,                 .u.ul = 0x03 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId3,                 .u.ul = 0x04 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ucDspType0,               .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,             .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_bcmxce572[] = {
  {bp_cpBoardId,               .u.cp = "XCE572"},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedEpon,           .u.us = BP_GPIO_30_AL},
  {bp_usGpioLedEponFail,       .u.us = BP_GPIO_31_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x11},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x07 | MAC_IF_XFI | PHY_EXTERNAL | PHY_INTEGRATED_VALID},     // ext Aquantia 10G phy
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_SWAP_PAIR},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref_p400},
  {bp_last}
};

static bp_elem_t g_bcmxce573[] = {
  {bp_cpBoardId,               .u.cp = "XCE573"},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_6_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_7_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedEponFail,       .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedEpon,           .u.us = BP_GPIO_10_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x13},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_GPIO_0_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_GPIO_1_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_GPIO_3_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_GPIO_4_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId4,                .u.ul = 0x1e | MAC_IF_XFI | PHY_EXTERNAL | PHY_INTEGRATED_VALID}, // ext 10G phy
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_SWAP_PAIR},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref_p400},
  {bp_last}
};

static bp_elem_t g_sphinx_1[] = {
  {bp_cpBoardId,               .u.cp = "SPHINX_1"},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_6_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_7_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedGpon,           .u.us = BP_GPIO_9_AL | BP_LED_USE_GPIO},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,	       .u.ul = 0x1C},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 0},
//  {bp_usNetLed0,               .u.us = BP_GPIO_0_AL},
//  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
//  {bp_usNetLed1,               .u.us = BP_GPIO_1_AL},
//  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 1},
//  {bp_usNetLed0,               .u.us = BP_GPIO_3_AL},
//  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
//  {bp_usNetLed1,               .u.us = BP_GPIO_4_AL},
//  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId4,                .u.ul = 0x1e | MAC_IF_XFI | PHY_EXTERNAL | PHY_INTEGRATED_VALID}, // ext 10G phy
  {bp_usOamIndex,              .u.us = 2},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_SWAP_PAIR},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref_p400},
  {bp_last}
};

/* SPHINX_XGA */
static bp_elem_t g_XGX[] = {
  {bp_cpBoardId,                .u.cp = "XGX"},
  {bp_usGpioI2c2Scl,            .u.us = BP_GPIO_23_AH},
  {bp_usGpioI2c2Sda,            .u.us = BP_GPIO_24_AH},
  {bp_usSerialLedData,          .u.us = BP_GPIO_29_AH},
  {bp_usSerialLedClk,           .u.us = BP_GPIO_30_AH},
  {bp_usSerialLedMask,          .u.us = BP_GPIO_31_AH},
  {bp_usGpioWanSignalDetected,  .u.us = BP_GPIO_49_AH},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_51_AH},
  {bp_usSpiSlaveSelectNum,      .u.us = 1},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 106},
  {bp_usSpiSlaveSelectNum,      .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 13},
#ifdef CONFIG_BCM_TIME_SYNC_MODULE
  {bp_usTsync1pps,              .u.us = BP_GPIO_11_AH | BP_NONGPIO_PIN},
  {bp_usGpioTsyncPonUnstable,   .u.us = BP_GPIO_12_AH},
  {bp_usUart1Sdin,              .u.us = BP_GPIO_27_AH},
  {bp_usUart1Sdout,             .u.us = BP_GPIO_28_AH},
#else
  {bp_usSpiSlaveSelectNum,      .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 12},
  {bp_usSpiSlaveSelectNum,      .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 11},
  {bp_usGpioI2CMux,             .u.us = BP_GPIO_27_AH},
#endif
  {bp_usExtIntrOpticalModulePresence, .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_BOTH_EDGE | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,              .u.us = BP_GPIO_32_AL},
  {bp_usGpioOpticalModuleTxPwrDown, .u.us = BP_GPIO_55_AH},
  {bp_usButtonIdx,             .u.us = 0},
  {bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_5 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_54_AL},  // button reset for Linux
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_56_AH},
  {bp_ulInterfaceEnable,        .u.ul = BP_PINMUX_FNTYPE_LPORT},
  {bp_usGpioLedBlPowerOn,       .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioLedBlStop,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedGpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedEpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanData,         .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedUSB,             .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x17},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usOamIndex,               .u.us = 0},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_1G},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usOamIndex,               .u.us = 1},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_1G},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_ulPhyId2,                 .u.ul = 0x03 | MAC_IF_GMII},
  {bp_usOamIndex,               .u.us = 2},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_1G},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_1G},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_FAE},
  {bp_ulPhyId4,                 .u.ul = 0x1e | MAC_IF_XFI | PHY_EXTERNAL | PHY_INTEGRATED_VALID},     // ext 10G phy
  {bp_usOamIndex,               .u.us = 3},
  {bp_ulPortFlags,              .u.ul = PORT_FLAG_SWAP_PAIR},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_10G},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_10G},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usGpioReserved,          .u.us = BP_GPIO_59_AL}, //CATV Control
  {bp_usGpioReserved,          .u.us = BP_GPIO_60_AL}, //Alarm 2
  {bp_last}
};



IOPSYSWRT_ADD_G_BOARDPARMS(g_bcmxce572);
IOPSYSWRT_ADD_G_BOARDPARMS(g_bcmxce573);
IOPSYSWRT_ADD_G_BOARDPARMS(g_sphinx_1);
IOPSYSWRT_ADD_G_BOARDPARMS(g_XGX);
