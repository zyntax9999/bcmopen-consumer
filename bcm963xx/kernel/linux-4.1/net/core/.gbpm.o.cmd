cmd_net/core/gbpm.o := /opt/toolchains//crosstools-arm-gcc-5.5-linux-4.1-glibc-2.26-binutils-2.28.1/usr/bin/arm-buildroot-linux-gnueabi-gcc -Wp,-MD,net/core/.gbpm.o.d -nostdinc -isystem /opt/toolchains/crosstools-arm-gcc-5.5-linux-4.1-glibc-2.26-binutils-2.28.1/lib/gcc/arm-buildroot-linux-gnueabi/5.5.0/include -I./arch/arm/include -Iarch/arm/include/generated/uapi -Iarch/arm/include/generated  -Iinclude -I./arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I./include/uapi -Iinclude/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-bcm963xx/include -Iarch/arm/plat-bcm63xx/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-dwarf2-cfi-asm -fno-ipa-sra -mabi=aapcs-linux -mno-thumb-interwork -mfpu=vfp -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -fno-delete-null-pointer-checks -fno-PIE -O2 --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -fno-var-tracking-assignments -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -g -Werror -Wfatal-errors -Wno-date-time -Wno-declaration-after-statement -Wno-switch-bool -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/bcmdrivers/opensource/include/bcm963xx -I/home/zyntax/firmwarehacks/devel/bcmopen-consumerworks/bcm963xx/shared/opensource/include/bcm963xx    -D"KBUILD_STR(s)=#s" -D"KBUILD_BASENAME=KBUILD_STR(gbpm)"  -D"KBUILD_MODNAME=KBUILD_STR(gbpm)" -c -o net/core/gbpm.o net/core/gbpm.c

source_net/core/gbpm.o := net/core/gbpm.c

deps_net/core/gbpm.o := \
    $(wildcard include/config/bcm/kf/nbuff.h) \
    $(wildcard include/config/bcm/bpm.h) \
    $(wildcard include/config/bcm/bpm/buf/tracking.h) \

net/core/gbpm.o: $(deps_net/core/gbpm.o)

$(deps_net/core/gbpm.o):
