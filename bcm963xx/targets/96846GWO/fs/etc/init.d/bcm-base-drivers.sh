#!/bin/sh

trap "" 2


case "$1" in
	start)
		echo "Loading drivers and kernel modules... "
		echo

# Syntax
# line
# conditon
# condition
# for
# -BUILD_FEATURE_A
# will
# -!BUILD_FEATURE_B
# will
 
# bcmlibs
insmod /lib/modules/4.1.52/extra/bcmlibs.ko  
 
# UBUS
 
insmod /lib/modules/4.1.52/extra/bdmf.ko  
 
#I2C 
 
# PON
insmod /lib/modules/4.1.52/extra/bcm_pondrv.ko  
 
# BPM
 
# VLAN
insmod /lib/modules/4.1.52/extra/bcmvlan.ko  
 
# RDPA
insmod /lib/modules/4.1.52/extra/rdpa_gpl.ko  
insmod /lib/modules/4.1.52/extra/rdpa_gpl_ext.ko  
insmod /lib/modules/4.1.52/extra/rdpa.ko  
 
# RDPA_User
insmod /lib/modules/4.1.52/extra/rdpa_usr.ko  
 
insmod /lib/modules/4.1.52/extra/rdpa_mw.ko  
insmod /lib/modules/4.1.52/extra/bcmbrfp.ko  
 
# General
insmod /lib/modules/4.1.52/extra/chipinfo.ko  
 
# Ingress
# Must
insmod /lib/modules/4.1.52/extra/bcm_ingqos.ko  
 
# RDPA
insmod /lib/modules/4.1.52/extra/rdpa_cmd.ko  
 
insmod /lib/modules/4.1.52/extra/pktflow.ko  
 
# enet
 
 
insmod /lib/modules/4.1.52/extra/bcm_enet.ko  
# moving
insmod /lib/modules/4.1.52/extra/pktrunner.ko  
insmod /lib/modules/4.1.52/extra/bcmmcast.ko  
 
# EAPFWD:
 
#load SATA/AHCI
 
# PCIe
insmod /lib/modules/4.1.52/extra/bcm_pcie_hcd.ko  
 
# pcie
 
# WLAN
 
# WLAN
insmod /lib/modules/4.1.52/extra/wlcsm.ko  
 
# NetXL
 
#Voice 
 
 
#load usb
insmod /lib/modules/4.1.52/kernel/drivers/usb/host/ehci-hcd.ko  
insmod /lib/modules/4.1.52/kernel/drivers/usb/host/ehci-platform.ko  
insmod /lib/modules/4.1.52/kernel/drivers/usb/host/ehci-pci.ko  
insmod /lib/modules/4.1.52/kernel/drivers/usb/host/ohci-hcd.ko  
insmod /lib/modules/4.1.52/kernel/drivers/usb/host/ohci-platform.ko  
insmod /lib/modules/4.1.52/kernel/drivers/usb/host/ohci-pci.ko  
insmod /lib/modules/4.1.52/extra/bcm_usb.ko  
insmod /lib/modules/4.1.52/kernel/drivers/usb/class/usblp.ko  
insmod /lib/modules/4.1.52/kernel/drivers/usb/storage/usb-storage.ko  
 
# other
 
insmod /lib/modules/4.1.52/extra/pwrmngtd.ko  
 
 
# presecure
insmod /lib/modules/4.1.52/extra/otp.ko  
 
# LTE
 

 test -e /etc/rdpa_init.sh && /etc/rdpa_init.sh

# Enable the PKA driver.
 test -e /sys/devices/platform/bcm_pka/enable && echo 1 > /sys/devices/platform/bcm_pka/enable

exit 0
		;;

	stop)
		echo "removing bcm base drivers not implemented yet..."
		exit 1
		;;

	*)
		echo "bcmbasedrivers: unrecognized option $1"
		exit 1
		;;

esac


