#!/bin/sh
#
#  Copyright 2011-2012, Broadcom Corporation
#

echo "======Version Info======"

echo "######image version######"
cat /etc/image_version

if [ -e /etc/patch.version ]; then
    echo "######patch version######"
    cat /etc/patch.version
fi

echo "######kernel version######"
cat /proc/version

if [ -e /bin/wlctl ]; then
    echo "######wl version######"
    /bin/wlctl ver
    /bin/wlctl revinfo
    echo "######ASPM Configuration######"
    cat /sys/module/pcie_aspm/parameters/policy 
    /bin/wlctl -i wl0 aspm
    /bin/wlctl -i wl1 aspm
 
    echo "######WLAN power save settings######"
    /bin/wlctl -i wl0 rxchain_pwrsave_enable
    /bin/wlctl -i wl1 rxchain_pwrsave_enable

    if [ -e /bin/WlGetDriverCfg.sh ]; then
       echo "######WLAN WlGetDriverCfg - wl0 2.4GHz NIC ######"
       /bin/WlGetDriverCfg.sh wl0 2 nic
       echo "######WLAN WlGetDriverCfg - wl1 2.4GHz NIC ######"
       /bin/WlGetDriverCfg.sh wl1 2 nic
       echo "######WLAN WlGetDriverCfg - wl0 5GHz NIC ######"
       /bin/WlGetDriverCfg.sh wl0 5 nic
       echo "######WLAN WlGetDriverCfg - wl1 5GHz NIC ######"
       /bin/WlGetDriverCfg.sh wl1 5 nic
       echo "######WLAN WlGetDriverCfg - wl0 2.4GHz DHD ######"
       /bin/WlGetDriverCfg.sh wl0 2 dhd
       echo "######WLAN WlGetDriverCfg - wl1 2.4GHz DHD ######"
       /bin/WlGetDriverCfg.sh wl1 2 dhd
       echo "######WLAN WlGetDriverCfg - wl0 5GHz DHD ######"
       /bin/WlGetDriverCfg.sh wl0 5 dhd
       echo "######WLAN WlGetDriverCfg - wl1 5GHz DHD ######"
       /bin/WlGetDriverCfg.sh wl1 5 dhd
    fi

fi

if [ -e /bin/xdslctl ]; then
    echo "######xdsl version######"
    /bin/xdslctl --version
fi

if [ -e /bin/voice ]; then
    echo "######DSP version######"
    cat /proc/voice/dsp_version
fi

if [ -e /bin/dectd ]; then
    echo "######DECT version######"
    cat /proc/dect/version
fi

if [ -e /bin/pwrctl ]; then
    echo "######Power Management Configuration######"
    /bin/pwrctl show
fi

echo
echo
echo "======System Info======"

sys_info_list="/proc/uptime
               /proc/cpuinfo
               /proc/brcm/kernel_config
               /proc/interrupts
               /proc/meminfo
               /proc/iomem
               /proc/slabinfo
               /proc/modules
               /proc/timer_list
               /proc/bus/pci/devices
               /proc/sys/kernel/sched_compat_yield
               /proc/sys/kernel/sched_rt_period_us
               /proc/sys/kernel/sched_rt_runtime_us"

# busybox msh does not support passing lists to functions
# so must repeat the function here
for f in $sys_info_list
do
    echo "######${f}######"
    if [ -e $f ]; then
        cat $f
    else
        echo "$f does not exist on this system."
    fi
done

# Current Processes Information
echo "###### ps ######"
ps
#TODO log more details about important processes(ex;priority, cpu affinity etc..)


echo
echo

echo "======Networking Info======"

#Networking Information
echo "######ifconfig -a######"
ifconfig -a

echo
echo
#virtual interface info
echo "###### dump all vlanctl rules ######"
sleep 1
vlanctl --rule-dump-all

echo "######brctl show######"
brctl show

echo "######route -n######"
route -n

#echo "######/proc/net/tcp######"
#cat /proc/net/tcp

#echo "######/proc/net/udp######"
#cat /proc/net/udp

echo "###### iptables -w -t nat -L ######"
iptables -w -t nat -L

echo "###### iptables -w -t filter -L ######"
iptables -w -t filter -L

echo "###### iptables -w -t mangle -L ######"
iptables -w -t mangle -L

net_info_list="/proc/net/arp
               /proc/sys/net/core/netdev_budget
               /proc/sys/net/core/netdev_max_backlog
               /proc/sys/net/core/dev_weight
               /proc/net/ip_tables_names
               /proc/net/ip_tables_matches
               /proc/net/ip_tables_targets
               /proc/net/netfilter/nf_log
               /proc/net/netfilter/nf_queue
               /proc/net/netfilter/nfnetlink_queue
               /proc/net/stat/nf_conntrack
               /proc/net/nf_conntrack
               /proc/net/nf_conntrack_expect"

# busybox msh does not support passing lists to functions
# so must repeat the function here
for f in $net_info_list
do
    echo "######${f}######"
    if [ -e $f ]; then
        cat $f
    else
        echo "$f does not exist on this system."
    fi
done

net_info_list="nf_conntrack_acct
               nf_conntrack_checksum
               nf_conntrack_generic_timeout
               nf_conntrack_icmp_timeout
               nf_conntrack_log_invalid
               nf_conntrack_tcp_be_liberal
               nf_conntrack_tcp_loose
               nf_conntrack_tcp_max_retrans
               nf_conntrack_tcp_timeout_close
               nf_conntrack_tcp_timeout_close_wait
               nf_conntrack_tcp_timeout_established
               nf_conntrack_tcp_timeout_fin_wait
               nf_conntrack_tcp_timeout_last_ack
               nf_conntrack_tcp_timeout_max_retrans
               nf_conntrack_tcp_timeout_syn_recv
               nf_conntrack_tcp_timeout_syn_sent
               nf_conntrack_tcp_timeout_time_wait
               nf_conntrack_tcp_timeout_unacknowledged
               nf_conntrack_udp_timeout
               nf_conntrack_udp_timeout_stream
               nf_conntrack_buckets
               nf_conntrack_max
               nf_conntrack_count
               nf_conntrack_expect_max"

# busybox msh does not support passing lists to functions
# so must repeat the function here.  Also it does not like long
# lists, so the netfilter list is broken into two parts
for f in $net_info_list
do
    lf=/proc/sys/net/netfilter/$f
    echo "######${lf}######"
    if [ -e $lf ]; then
        cat $lf
    else
        echo "$lf does not exist on this system."
    fi
done


echo
echo
echo "======Multicast Info======"
echo "###### /var/mcpd.conf ######"
cat /var/mcpd.conf

mcast_info_list="/proc/net/igmp 
                 /proc/net/igmp_snooping 
                 /proc/net/ip_mr_cache
                 /proc/net/ip_mr_vif
                 /proc/net/dev_mcast
                 /proc/net/igmp6 
                 /proc/net/mld_snooping 
                 /proc/net/ip6_mr_cache
                 /proc/net/ip6_mr_vif"

# busybox msh does not support passing lists to functions
# so must repeat the function here
for f in $mcast_info_list
do
    echo "######${f}######"
    if [ -e $f ]; then
        cat $f
    else
        echo "$f does not exist on this system."
    fi
done


if [ -e /sbin/ipsec ]; then
echo
echo
echo "======IPSec Info======"
ipsec_info_list="/var/ipsec/ipsec.conf
                 /var/ipsec/ipsec.secrets
                 /var/ipsec/setkey.sh"

# busybox msh does not support passing lists to functions
# so must repeat the function here
for f in $ipsec_info_list
do
    echo "######${f}######"
    if [ -e $f ]; then
        cat $f
    else
        echo "$f does not exist on this system."
    fi
done
fi


echo
echo
echo "======Accelerators======"

if [ -e /proc/fcache ]; then
    echo "###### /proc/fcache/* ######"
    cat /proc/fcache/*
fi

if [ -e /proc/pktcmf ]; then
    echo "###### /proc/pktcmf/* ######"
    cat /proc/pktcmf/*
fi

if [ -e /bin/fap ]; then
    echo "###### fap print ######"
    /bin/fap print
fi

# Archer
if [ -e /bin/archerctl ]; then
    echo "###### archerctl status ######"
    archerctl status
    echo "###### archerctl stats ######"
    archerctl stats
    echo "###### archerctl sysport_tm stats ######"
    archerctl sysport_tm stats
fi

if [ -e /bin/ethswctl ]; then
    echo "###### ethswctl -c arldump ######"
    /bin/ethswctl -c arldump 
fi

if [ -e /bin/spuctl ]; then
    echo "###### spuctl showstats ######"
    spuctl showstats
fi

# RDPA configuration

if [ -e /bin/bs ]; then
    echo "######RDPA configuration######"
    /bin/bs /bdmf/examine system children:yes class:config max_prints:-1
fi


echo
echo
echo "======Console Bootup Messages======"
cat /var/tmp/bootupmessages

