cmd_/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/phys/bus_drv_6846.o := /opt/toolchains//crosstools-arm-gcc-5.5-linux-4.1-glibc-2.26-binutils-2.28.1/usr/bin/arm-buildroot-linux-gnueabi-gcc -Wp,-MD,/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/phys/.bus_drv_6846.o.d -nostdinc -isystem /opt/toolchains/crosstools-arm-gcc-5.5-linux-4.1-glibc-2.26-binutils-2.28.1/lib/gcc/arm-buildroot-linux-gnueabi/5.5.0/include -I./arch/arm/include -Iarch/arm/include/generated/uapi -Iarch/arm/include/generated  -Iinclude -I./arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I./include/uapi -Iinclude/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-bcm963xx/include -Iarch/arm/plat-bcm63xx/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-dwarf2-cfi-asm -fno-ipa-sra -mabi=aapcs-linux -mno-thumb-interwork -mfpu=vfp -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -fno-delete-null-pointer-checks -fno-PIE -O2 --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -fno-var-tracking-assignments -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -DPHY_CROSSBAR -DMAC_UNIMAC -DPHY_6846_EGPHY -DPHY_EXT1 -I/framework -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/drv/phys -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/drv/mdio -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/drv/unimac -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/pmc -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/lport -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/lport/ag -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/bcmdrivers/opensource/net/enet/shared -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/bcmdrivers/opensource/include/bcm963xx -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/bcm963xx @/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/linux-4.1/rdp_flags.txt    -D"KBUILD_STR(s)=#s" -D"KBUILD_BASENAME=KBUILD_STR(bus_drv_6846)"  -D"KBUILD_MODNAME=KBUILD_STR(bus_drv_6846)" -c -o /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/phys/bus_drv_6846.o /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/phys/bus_drv_6846.c

source_/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/phys/bus_drv_6846.o := /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/phys/bus_drv_6846.c

deps_/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/phys/bus_drv_6846.o := \
  /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/drv/phys/bus_drv.h \
  /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/drv/phys/os_dep.h \
  arch/arm/include/asm/delay.h \
  arch/arm/include/asm/memory.h \
    $(wildcard include/config/need/mach/memory/h.h) \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/have/tcm.h) \
    $(wildcard include/config/arm/lpae.h) \
    $(wildcard include/config/arm/patch/phys/virt.h) \
    $(wildcard include/config/phys/offset.h) \
    $(wildcard include/config/virt/to/bus.h) \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/bcm/kf/buzzz.h) \
    $(wildcard include/config/buzzz/func.h) \
    $(wildcard include/config/kprobes.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  include/uapi/linux/types.h \
  arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  arch/arm/include/generated/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  include/uapi/asm-generic/bitsperlong.h \
  include/uapi/linux/posix_types.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
  arch/arm/include/uapi/asm/posix_types.h \
  include/uapi/asm-generic/posix_types.h \
  include/uapi/linux/const.h \
  include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/bcm/kf/unaligned/exception.h) \
    $(wildcard include/config/mips/bcm963xx.h) \
  include/linux/sizes.h \
  arch/arm/include/asm/cache.h \
    $(wildcard include/config/arm/l1/cache/shift.h) \
    $(wildcard include/config/aeabi.h) \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  arch/arm/include/generated/asm/param.h \
  include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  include/uapi/asm-generic/param.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /opt/toolchains/crosstools-arm-gcc-5.5-linux-4.1-glibc-2.26-binutils-2.28.1/lib/gcc/arm-buildroot-linux-gnueabi/5.5.0/include/stdarg.h \
  include/uapi/linux/string.h \
  arch/arm/include/asm/string.h \
  include/linux/printk.h \
    $(wildcard include/config/message/loglevel/default.h) \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/init.h \
    $(wildcard include/config/broken/rodata.h) \
    $(wildcard include/config/lto.h) \
    $(wildcard include/config/modules.h) \
  include/linux/kern_levels.h \
  include/linux/linkage.h \
  include/linux/stringify.h \
  include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
  arch/arm/include/asm/linkage.h \
  include/linux/cache.h \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  include/uapi/linux/kernel.h \
  include/uapi/linux/sysinfo.h \
  include/linux/dynamic_debug.h \
  include/linux/errno.h \
  include/uapi/linux/errno.h \
  arch/arm/include/generated/asm/errno.h \
  include/uapi/asm-generic/errno.h \
  include/uapi/asm-generic/errno-base.h \
  /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/drv/mdio/mdio_drv_impl5.h \
  /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/drv/mdio/mdio_drv_common.h \
  /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/drv/phys/os_dep.h \

/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/phys/bus_drv_6846.o: $(deps_/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/phys/bus_drv_6846.o)

$(deps_/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/drv/phys/bus_drv_6846.o):
