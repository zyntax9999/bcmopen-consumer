# Note: CONFIG_MIPS_BRCM is no longer defined with the new kernel...
# CONFIG_BCM_IN_KERNEL is not defined with the new...
# Ifs in Makefiles can�t do Ors...
# So cat strings together, and if one of them is 'y' ...
ifeq ($(CONFIG_MIPS_BRCM)$(CONFIG_BCM_IN_KERNEL),y)


# These definitions and the following rule facilitate two things
# * Put vars into their own sections so that the linker-script can see them
# * rename the Broadcom variables without patching the sources
#   (Thus avoiding 17 hunks very likely to cause conflicts in future rebases on newer SDKs)
#
# boardparams_voice.c cannot be patched this way, because it also contains code
# referring to g_VoiceBoardParms, and we want that code refer to the complete array
# with the iopsysWrt VoiceBoardParms.
CFLAGS_boardparms_$(BRCM_CHIP).o = -fdata-sections
CFLAGS_boardparms_chip.o = -fdata-sections
# In the following rule, everything but the next two lines should be in sync
# with the CFE Makefile bcm963xx/cfe/cfe/board/bcm63xx_ram/src/Makefile
$(obj)/%.renamed_brcm.o: $(obj)/%.o
	$(OBJCOPY)                                                            \
	            --redefine-sym         g_BoardParms=brcm_g_BoardParms     \
	            --rename-section .data.g_BoardParms=.brcm_g_BoardParms    \
	            --redefine-sym         wlanPaInfo=brcm_wlanPaInfo         \
	            --rename-section .data.wlanPaInfo=.brcm_wlanPaInfo        \
	            $< $@

# Linux
obj-y		+= bp_funcs.o
obj-y           += boardparms_chip.renamed_brcm.o
obj-y		+= pinmux_table_$(BRCM_CHIP).o
obj-y		+= boardparms_$(BRCM_CHIP).renamed_brcm.o
obj-y		+= boardparms_iopsys_$(BRCM_CHIP).o
obj-y		+= $(BCM_EXTRA_BOARDPARMS_OBJS)
obj-y		+= boardparms_iopsys_$(BRCM_CHIP).o
obj-y		+= boardparms_iopsys.o

obj-y		+= boardparms_voice.o
# This linker script will place all the different boardParms from different
# files next to another memory. This way, Broadcomm and external iopsysWrt
# boardparms can be treated as one big array.
# This has to come AFTER all the other object files having boardparms,
# for all boardparms in all files to be taken into account.
obj-y		+= boardparms_iopsyswrt.ld.S

EXTRA_CFLAGS += -DCONFIG_BOARDPARMS_VOICE

EXTRA_CFLAGS += -DCONFIG_BCM9$(BRCM_CHIP) -I$(INC_BRCMSHARED_PUB_PATH)/$(BRCM_BOARD) -I$(INC_BRCMDRIVER_PUB_PATH)/$(BRCM_BOARD)

ifeq ($(MOCA_LAN_DISCONN),y)
EXTRA_CFLAGS += -DCONFIG_NO_MOCA_LAN
endif

ifeq ($(MOCA_WAN_DISCONN),y)
EXTRA_CFLAGS += -DCONFIG_NO_MOCA_WAN
endif

ifneq ($(CONFIG_BCM_ARCHER),)
EXTRA_CFLAGS += -DCONFIG_BCM_SYSPORT
endif

-include $(TOPDIR)/Rules.make

endif
