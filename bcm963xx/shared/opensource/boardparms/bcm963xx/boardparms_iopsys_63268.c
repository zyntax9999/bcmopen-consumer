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
static bp_elem_t g_dg301r0[] = {
	{bp_cpBoardId,               .u.cp = "DG301R0"},
	{bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
	{bp_usGpioOverlay,           .u.ul = (BP_OVERLAY_PHY | BP_OVERLAY_INET_LED | BP_OVERLAY_DG301 | BP_OVERLAY_USB_DEVICE)},
	//  {bp_usGpioSerialLedClock,    .u.us = BP_GPIO_0_AL},
	//  {bp_usGpioSerialLedData,     .u.us = BP_GPIO_1_AL},
	//  {bp_usGpioSerialLedLoad,     .u.us = BP_GPIO_23_AL},
	//  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
	//  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
	//  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
	//  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
	//  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
	//  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
	{bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
	{bp_usButtonIdx,             .u.us = 0},
	{  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
	{bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
	//  {bp_usGpioWirelessPowerDown, .u.us = BP_GPIO_36_AL},
	//  {bp_usGpioWpsButton,         .u.us = BP_GPIO_22_AL},
	//  {bp_usGpioDectButton,        .u.us = BP_GPIO_20_AL},
	//  {bp_usGpioInfoButton,        .u.us = BP_GPIO_37_AL},
	{bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
	{bp_usWirelessFlags,         .u.us = 0},
	// {bp_usEphyBaseAddress,       .u.us = 0x10},
	{bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
		{bp_ucPhyAddress,        .u.uc = 0x0},
		{bp_usConfigType,        .u.us = BP_ENET_CONFIG_MMAP},
		{bp_ulPortMap,           .u.ul = 0xF8},
		{bp_ulPhyId0,            .u.ul = BP_PHY_ID_17 | PHY_INTERNAL | PHY_INTEGRATED_VALID},
		{bp_ulPhyId3,            .u.ul = BP_PHY_ID_4 | PHY_INTERNAL | PHY_INTEGRATED_VALID},
		{bp_ulPhyId4,            .u.ul = BP_PHY_ID_0 |  MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
		{bp_ulPhyId5,            .u.ul = BP_PHY_ID_1 |  MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
		{bp_ulPhyId6,            .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII},
		{bp_ulPhyId7,            .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
	{bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
	{bp_ucDspAddress,            .u.uc = 0},
	{bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
	{bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
	{bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
	{bp_usSpiSlaveSelectNum,     .u.us = 4},
	{bp_usSpiSlaveSelectGpioNum, .u.us = 16},
	{bp_last}
};



IOPSYSWRT_ADD_G_BOARDPARMS(g_dg301r0);