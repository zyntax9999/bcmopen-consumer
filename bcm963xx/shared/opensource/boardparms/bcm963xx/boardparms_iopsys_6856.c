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
static bp_elem_t g_xug534[] = {
	{bp_cpBoardId,							 .u.cp = "XUG534"},
	{bp_ulOpticalWan,      			 .u.ul = BP_OPTICAL_WAN_GPON},
	{bp_usI2sSdata,			  			 .u.us = BP_GPIO_0_AH},
	{bp_usI2sSclk, 			  			 .u.us = BP_GPIO_1_AH},
	{bp_usI2sLrck, 			  			 .u.us = BP_GPIO_2_AH},
	{bp_usGpioWanSignalDetected, .u.us = BP_GPIO_8_AH},
	//{bp_usGpioPmdReset,		  	   .u.us = BP_GPIO_9_AL},
	//{bp_usExtIntrPmdAlarm, 	  	 .u.us = BP_EXT_INTR_2 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
	//{bp_usGpio_Intr,			  		 .u.us = BP_GPIO_10_AH},
	{bp_usGpioPonTxEn, 		  		 .u.us = BP_GPIO_12_AH},
	{bp_usGpioPonRxEn,           .u.us = BP_GPIO_12_AH},
	{bp_usGpioI2cSda,			  		 .u.us = BP_GPIO_19_AL},
	{bp_usGpioI2cScl,			  		 .u.us = BP_GPIO_20_AL},
	{bp_usPonLbe,				  			 .u.us = BP_GPIO_22_AH},
	//{bp_usExtIntrOpticalModulePresence, .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_BOTH_EDGE | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
	//{bp_usGpio_Intr,			       .u.us = BP_GPIO_23_AH},
	//{bp_InvSerdesTxPol,		       .u.us = pmd_polarity_invert},
	//{bp_usPmdMACEwakeEn,		     .u.us = BP_GPIO_24_AH},
	{bp_usSerialLedData,		  	 .u.us = BP_GPIO_26_AH},
	{bp_usSerialLedClk,		  		 .u.us = BP_GPIO_27_AH},
	{bp_usSerialLedMask,		  	 .u.us = BP_GPIO_28_AH},
	{bp_usMiiMdc,				  			 .u.us = BP_GPIO_60_AH},
	{bp_usMiiMdio, 			  			 .u.us = BP_GPIO_61_AH},
	{bp_usPcmSdin, 			  			 .u.us = BP_GPIO_45_AH},
	{bp_usPcmSdout,			         .u.us = BP_GPIO_46_AH},
	{bp_usPcmClk,				  			 .u.us = BP_GPIO_47_AH},
	{bp_usPcmFs,				         .u.us = BP_GPIO_75_AH},
	{bp_usUsbPwrOn1,			       .u.us = BP_GPIO_79_AL},
	{bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
	{bp_usGpio_Intr,			       .u.us = BP_GPIO_83_AL},
	{bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
	{bp_usGpio_Intr,			       .u.us = BP_GPIO_82_AL},
	{bp_ucPhyType0,			         .u.uc = BP_ENET_INTERNAL_PHY},
	{bp_ucPhyAddress,			       .u.uc = 0x0},
	{bp_usConfigType,			       .u.us = BP_ENET_CONFIG_MMAP},
	{bp_ulPortMap, 			         .u.ul = 0x0f},
	{bp_ulPhyId0,				         .u.ul = 0x01 | MAC_IF_GMII},
	{bp_usNetLed0, 			         .u.us = BP_SERIAL_GPIO_3_AL},
	{bp_ulNetLedLink,			       .u.ul = BP_NET_LED_SPEED_GBE},
	{bp_usNetLed1, 			         .u.us = BP_SERIAL_GPIO_4_AL},
	{bp_ulNetLedActivity,		     .u.ul = BP_NET_LED_SPEED_GBE},
	{bp_ulPhyId1,				  			 .u.ul = 0x02 | MAC_IF_GMII},
	{bp_usNetLed0, 			  			 .u.us = BP_SERIAL_GPIO_5_AL},
	{bp_ulNetLedLink,			  		 .u.ul = BP_NET_LED_SPEED_GBE},
	{bp_usNetLed1, 			  			 .u.us = BP_SERIAL_GPIO_6_AL},
	{bp_ulNetLedActivity,		  	 .u.ul = BP_NET_LED_SPEED_GBE},
	{bp_ulPhyId2,				  			 .u.ul = 0x03 | MAC_IF_GMII},
	{bp_usNetLed0, 			  			 .u.us = BP_SERIAL_GPIO_7_AL},
	{bp_ulNetLedLink,			  		 .u.ul = BP_NET_LED_SPEED_GBE},
	{bp_usNetLed1, 			  			 .u.us = BP_SERIAL_GPIO_8_AL},
	{bp_ulNetLedActivity,		  	 .u.ul = BP_NET_LED_SPEED_GBE},
	{bp_ulPhyId3,				  			 .u.ul = 0x04 | MAC_IF_GMII},
	{bp_usNetLed0, 			  			 .u.us = BP_SERIAL_GPIO_9_AL},
	{bp_ulNetLedLink,			  		 .u.ul = BP_NET_LED_SPEED_GBE},
	{bp_usNetLed1, 			  		   .u.us = BP_SERIAL_GPIO_10_AL},
	{bp_ulNetLedActivity,		  	 .u.ul = BP_NET_LED_SPEED_GBE},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_0_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_1_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_2_AL},
	{bp_usGpioLedReserved,		 .u.us = BP_SERIAL_GPIO_11_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_12_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_13_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_14_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_15_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_16_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_17_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_18_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_19_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_20_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_21_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_22_AL},
	{bp_usGpioLedReserved, 	  	 .u.us = BP_SERIAL_GPIO_23_AL},
	{bp_usUsbPwrFlt0,			  		 .u.us = BP_GPIO_76_AL},
	{bp_usUsbPwrOn0,			     	 .u.us = BP_GPIO_77_AL},
	{bp_usUsbPwrFlt1,			  		 .u.us = BP_GPIO_78_AL},
	{bp_usUsbPwrOn1,			  		 .u.us = BP_GPIO_79_AL},
	{bp_usGpioUart2Sdin,		  	 .u.us = BP_GPIO_7_AH},
	{bp_usGpioUart2Sdout,		  	 .u.us = BP_GPIO_25_AH},
	{bp_pmdFunc,				  			 .u.us = BP_PMD_APD_REG_DISABLED | BP_PMD_APD_TYPE_BOOST},
	{bp_ulMemoryConfig,		  		 .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1},
	{bp_usSpiSlaveSelectNum,	   .u.us = 1},
	{bp_usSpiSlaveSelectGpioNum, .u.us = BP_GPIO_81_AH},
	{bp_ucDspType0,			  		   .u.uc = BP_VOIP_DSP},
	{bp_ucDspAddress,			  		 .u.uc = 0},
	{bp_ulPciFlags,              .u.ul = BP_PCI0_DUAL_LANE},        //xavi
	{bp_last}
};

static bp_elem_t g_xue534[] = {
	{bp_cpBoardId,							 .u.cp = "XUE534"},
	{bp_ucPhyType0,			         .u.uc = BP_ENET_INTERNAL_PHY},
	{bp_ucPhyAddress,			       .u.uc = 0x0},
	{bp_usConfigType,			       .u.us = BP_ENET_CONFIG_MMAP},
	{bp_ulPortMap, 			         .u.ul = 0x1f},
	{bp_ulPhyId0,				         .u.ul = 0x01 | MAC_IF_GMII},
	{bp_ulPhyId1,				  			 .u.ul = 0x02 | MAC_IF_GMII},
	{bp_ulPhyId2,				  			 .u.ul = 0x03 | MAC_IF_GMII},
	{bp_ulPhyId3,				  			 .u.ul = 0x04 | MAC_IF_GMII},
	{bp_ulPhyId4,				  			 .u.ul = 0x19 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
	{bp_ulPortFlags,			  		 .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_WAN_ONLY},
	{bp_ulOpticalWan,      			 .u.ul = BP_NOT_DEFINED},
	{bp_elemTemplate,            .u.bp_elemp = g_xug534},
	{bp_last}
};



IOPSYSWRT_ADD_G_BOARDPARMS(g_xue534);
