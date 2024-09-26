cmd_/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/96846.dtb := mkdir -p /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/ ; /opt/toolchains//crosstools-arm-gcc-5.5-linux-4.1-glibc-2.26-binutils-2.28.1/usr/bin/arm-buildroot-linux-gnueabi-gcc -E -Wp,-MD,/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/.96846.dtb.d.pre.tmp -nostdinc -I./arch/arm/boot/dts -I./arch/arm/boot/dts/include -I./drivers/of/testcase-data -I./include -undef -D__DTS__ -x assembler-with-cpp -o /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/.96846.dtb.dts.tmp /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/96846.dts ; ./scripts/dtc/dtc -O dtb -o /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/96846.dtb -b 0 -i /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/  -d /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/.96846.dtb.d.dtc.tmp /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/.96846.dtb.dts.tmp ; cat /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/.96846.dtb.d.pre.tmp /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/.96846.dtb.d.dtc.tmp > /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/.96846.dtb.d

source_/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/96846.dtb := /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/96846.dts

deps_/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/96846.dtb := \
    $(wildcard include/config/optee.h) \
    $(wildcard include/config/bcm/pcie/hcd.h) \
  arch/arm/boot/dts/include/dt-bindings/interrupt-controller/arm-gic.h \
  arch/arm/boot/dts/include/dt-bindings/interrupt-controller/irq.h \
  arch/arm/boot/dts/include/dt-bindings/soc/bcm963xx_dt_bindings.h \
    $(wildcard include/config/bcm/chip/number.h) \
    $(wildcard include/config/brcm/chip/rev.h) \
    $(wildcard include/config/bcm/rdpa.h) \
    $(wildcard include/config/bcm/glb/coherency.h) \
  /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/../../../shared/opensource/include/pmc/pmc_firmware_68460.h \
  /home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/../bcm_rsvdmem_32.dtsi \
    $(wildcard include/config/bcm/cma/rsvmem.h) \
    $(wildcard include/config/bcm/adsl.h) \
    $(wildcard include/config/bcm/dhd/runner.h) \
    $(wildcard include/config/bcm96846.h) \

/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/96846.dtb: $(deps_/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/96846.dtb)

$(deps_/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/kernel/dts/6846/96846.dtb):
