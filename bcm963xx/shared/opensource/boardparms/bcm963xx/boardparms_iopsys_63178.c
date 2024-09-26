#include "bp_defs.h"
#include "boardparms.h"
#include "bcmSpiRes.h"
#include "boardparms_iopsys.h"

extern BpCmdElem moca6802InitSeq[];

#define BCM963178_PHY_BASE             0x8
#define BP_DDR_63178_DEFAULT           BP_DDR_VTT_DIS_NOTERM

static bp_elem_t g_bcm96752ref1[] = {
  {bp_cpBoardId,               .u.cp = "96752REF1"},
  {bp_usButtonIdx,             .u.us = 0},
  {bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0|BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE|BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_0_AL},
  {bp_usButtonAction,          .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {bp_ulButtonActionParm,      .u.ptr = (void*)"Button Press -- Hold for 5s to do restore to default" },
  {bp_usButtonAction,          .u.us = BP_BTN_ACTION_RESET | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {bp_usButtonAction,          .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S},
  {bp_usButtonIdx,             .u.us = 1},
  {bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_1|BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE|BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_5_AL},
  {bp_usButtonAction,          .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_PRESS  },
#if !defined(_CFE_)
  {bp_usVregSync,              .u.us = BP_GPIO_2_AH},
#endif
  {bp_usGphyBaseAddress,       .u.us = BCM963178_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x03},
  {bp_ulPhyId0,                .u.ul = (BCM963178_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulPhyId1,                .u.ul = (BCM963178_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},

  {bp_usIntfId,                .u.us = 0},
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_GPHY},
  {bp_usPortNum,               .u.us = 0},
  {bp_usNetLed3,               .u.us = BP_GPIO_4_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_ACTIVITY_ALL},
  {bp_usIntfEnd},
  {bp_usIntfId,                .u.us = 1},
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_GPHY},
  {bp_usPortNum,               .u.us = 1},
  {bp_usNetLed3,               .u.us = BP_GPIO_8_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_ACTIVITY_ALL},
  {bp_usIntfEnd},
  {bp_usIntfId,                .u.us = 2}, /* HS_UART for BT */
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_UART},
  {bp_usPortNum,               .u.us = 1},
  {bp_usUartSdin,              .u.us = BP_GPIO_21_AH},
  {bp_usUartSdout,             .u.us = BP_GPIO_20_AH},
  {bp_usUartRts,               .u.us = BP_GPIO_12_AH},
  {bp_usUartCts,               .u.us = BP_GPIO_22_AH},
  {bp_usIntfEnd},

  /* wlan fem_ctrl reserved signals*/
  {bp_usGpioInitState,       .u.us = BP_GPIO_25_AH}, /* color led */
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_34_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_35_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_36_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_37_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_38_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_39_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_40_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_41_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_42_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_43_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_44_AH},
  {bp_usGpioWlanReserved,      .u.us = BP_GPIO_45_AH},

  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_27_AL},


  {bp_usI2sSclk,               .u.us = BP_GPIO_29_AH},
  {bp_usI2sLrck,               .u.us = BP_GPIO_30_AH},
  {bp_usI2sRxSdata,            .u.us = BP_GPIO_31_AH},
  {bp_usI2sTxSdata,            .u.us = BP_GPIO_32_AH},
  {bp_usI2sMclk,               .u.us = BP_GPIO_33_AH},
  {bp_usPcmSdin,               .u.us = BP_GPIO_13_AH},
  {bp_usPcmSdout,              .u.us = BP_GPIO_14_AH},
  {bp_usPcmClk,                .u.us = BP_GPIO_15_AH},
  {bp_usPcmFs,                 .u.us = BP_GPIO_16_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = BP_GPIO_80_AL},
  {bp_usUsbPwrOn1,             .u.us = BP_GPIO_86_AL},
  {bp_usUsbPwrFlt1,            .u.us = BP_GPIO_85_AL},
  {bp_usUsbPwrOn0,             .u.us = BP_GPIO_84_AL},
  {bp_usUsbPwrFlt0,            .u.us = BP_GPIO_83_AL},

  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_63178_DEFAULT},
  {bp_last}
};


IOPSYSWRT_ADD_G_BOARDPARMS(g_bcm96752ref1);
