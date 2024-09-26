# Remove variables from OpenWRT which disturb Broadcom SDK
override CC :=
override GCC :=
override LD :=
override AS :=
override AR :=
override NM :=
override CXX :=
override RANLIB :=
override STRIP :=
override OBJCOPY :=
override OBJDUMP :=
override SIZE :=
override MAKEFLAGS :=
override PATH := $(shell env -i /bin/bash -lc 'echo $$PATH')
unexport CFLAGS
unexport CXXFLAGS
unexport LDFLAGS
unexport CFLAGS_NOARCH
unexport CONFIG_SITE
unexport MFLAGS
unexport STAGING_PREFIX
unexport STAGING_DIR
unexport V
unexport TOPDIR
unexport PKG_CONFIG
unexport PKG_CONFIG_LIBDIR
unexport PKG_CONFIG_PATH
unexport M4
unexport BISON_PKGDATADIR

# debug. Printout all variables
#$(foreach v, $(.VARIABLES), $(info $(v) = $($(v))))

# Some sane default options if not otherwise declared by user
bcmTop ?= bcm963xx
CONFIG_BCM_CHIP_ID ?= 63268
CONFIG_BCM_KERNEL_PROFILE ?= 963268GWV
ARCH ?= mips
CONFIG_ARCH ?= $(ARCH)
cfeTop := $(bcmTop)/cfe/build/broadcom
HOSTTOOLS_DIR=$(CURDIR)/$(bcmTop)/hostTools

profileGen := $(CURDIR)/$(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)/bcmcreator.conf
profileBcm := $(CURDIR)/$(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)/$(CONFIG_BCM_KERNEL_PROFILE)
PROFILE_FILE = $(if $(wildcard $(profileGen)),$(profileGen),$(profileBcm))
-include $(profileGen)

# Seach path for Perl includes
PERL5LIB += :$(CURDIR)/$(bcmTop)/data-model:$(CURDIR)/$(bcmTop)/hostTools/PerlLib
export PERL5LIB

# Check that parent path doesn't contain any whitespace or install will fail.
ifneq ($(word 2,$(CURDIR)),)
    $(error The path to Bcmcreator must not contain any whitespace!)
endif

# Check endianess
ifeq ($(CONFIG_BIG_ENDIAN),y)
    ENDIAN=big
else
    ENDIAN=little
endif

# Size of NAND flash erase blocks in image as argument from OpenWRT.
# Use 128 kB, which is the most common value, as fallback.
nandBlocksize += $(if $(BUILD_NAND_IMG_BLKSIZE_128KB), 131072)
nandBlocksize += $(if $(BUILD_NAND_IMG_BLKSIZE_256KB), 262144)
nandBlocksize += $(if $(BUILD_NAND_IMG_BLKSIZE_512KB), 524288)
nandBlocksize += $(if $(BUILD_NAND_IMG_BLKSIZE_1024KB), 1048576)
nandBlocksize := $(if $(strip $(nandBlocksize)), $(nandBlocksize), 131072)



# Force fakeroot to not use host native libcap-dev or build will fail.
export ac_cv_header_sys_capability_h := 0

export SHELL := /bin/bash
export LANG := C
export LC_ALL := C
export MAKE
export BRCM_MAX_JOBS
export ARCH
export CONFIG_BCM_CFE_PASSWORD
export BRCM_CHIP := $(CONFIG_BCM_CHIP_ID)
export BLD_NAND := 1
export BLD_SPI_NAND := 0
export INC_SPI_NAND_DRIVER := 0
export BLD_BTRM_BOOT := 0
export CFG_COPY_PSRAM := 0
export MY_DEFAULT_ANY_FIRST_RUN := 0
export MY_MKENV_FIRST_RECURSION := 0
export TOOLCHAIN_TOP ?= $(CONFIG_BCM_TOOLCHAIN)
export DEFAULT_TOOLCHAIN_LINUX_4_1_0_ARM ?= $(CONFIG_BCM_TOOLCHAIN)
export CROSS_COMPILE ?= "$(TOOLS)$(TOOLPREFIX)"


#-----------------------------
.DELETE_ON_ERROR:
.SUFFIXES:																		# Disable suffix implicit rules


#-----------------------------
# Parallell build with GNU Make jobserver? OpenWRT does not
# pass neccessary arguments in MAKEFLAGS as is usually the case.
# It does however provide them on the commandline and through
# another custom variable. Here we fixup for the Broadcom SDK
# which needs some special environment variables for jobserver
# to work.
ifeq ($(BRCM_MAX_JOBS),)
    JOBSERVER := $(MAKE_J)
    ifeq ($(JOBSERVER),)
        BRCM_MAX_JOBS := 1
    else
        MAKEFLAGS += $(JOBSERVER)
        JOBSERVER += BRCM_MAX_JOBS= ACTUAL_MAX_JOBS=
        BRCM_MAX_JOBS :=
        export ACTUAL_MAX_JOBS :=
    endif
endif


#-----------------------------
# Lib func for makeing Git not to track any modifications to a file. Note
# that this is different from adding it to .gitignore. The file remains
# in the repo.
git_ignore = $(strip															\
	if test -n "$(strip $(1))"; then											\
		for tmp2 in $(strip $(1)); do											\
			if test -e "$$tmp2"; then											\
				if test ! -f .git_assume_unchanged ||							\
						! grep -qE "^$${tmp2}$$" .git_assume_unchanged; then	\
					git update-index --assume-unchanged "$$tmp2";				\
					echo "$$tmp2" >>.git_assume_unchanged;						\
				fi;																\
			fi;																	\
		done;																	\
	fi)


# Lib func for deleteing a file and make Git not to track any modifications.
delete_and_ignore = $(strip														\
	if test -n "$(strip $(1))"; then											\
		for tmp1 in $(strip $(1)); do											\
			if test -f $$tmp1; then												\
				$(call git_ignore, $$tmp1);										\
				rm -f $$tmp1;													\
			fi;																	\
		done;																	\
	fi)


# Lib funcs for installing a file conditionally by checking the
# profile config. Install the file if it's expected to exist.
check_config = $(strip															\
	grep -qE "^$(strip $(1))=$(strip $(2))$$" "$(profileGen)")

install_brcm = $(strip															\
	if grep -qE "^$(strip $(1))=[ym]$$" "$(profileGen)"; then					\
		$(CP) $(if $(BRCM_VERBOSE),-v) $(strip $(2)) $(strip $(3));				\
	fi)

install_wifi = $(call install_brcm, BRCM_DRIVER_WIRELESS, $(1), $(2))

# Pad file with 0xff to boundary
pad_to_boundary = cat /dev/zero | tr "\000" "\377" | 							\
	head --bytes=$$(( ($(strip $(2))) - ($$(stat -c%s							\
	$(strip $(1))) % ($(strip $(2)))) )) >> $(strip $(1))

create_padding = cat /dev/zero | tr "\000" "\377" | 							\
	head --bytes=$(strip $(2)) > $(strip $(1))

# Lib func for querying Broadcom NAND flash layout.
check_flashlayout = $(strip														\
	grep -E "define $(strip $(1))[[:space:]]+"									\
	"$(bcmTop)/shared/opensource/include/bcm963xx/iopsys_pureUBI.h"	|			\
	grep -Eo "[[:digit:]]+")

#-----------------------------													# Standard targets
.PHONY: all
all: .images

boardparms_dir = $(bcmTop)/shared/opensource/boardparms/bcm963xx
export BCM_EXTRA_BOARDPARMS_OBJS = $(notdir $(BCM_EXTRA_BOARDPARMS:.c=.xbp.o))

.extra_boardparms: $(BCM_EXTRA_BOARDPARMS)
	$(foreach EXTRA_BOARDPARM_C, $(BCM_EXTRA_BOARDPARMS),             \
		cp -vf $(EXTRA_BOARDPARM_C) $(boardparms_dir)/$(notdir $(EXTRA_BOARDPARM_C:.c=.xbp.c)) &&                            \
	) true
	touch $@

.images: .cfe_common
	touch "$(bcmTop)/build/iopsys-do-kernel"									# Workaround for Broadcom broken dependencies.
	$(MAKE) -C "$(bcmTop)" -f "build/Makefile" SHELL=$(SHELL) $(JOBSERVER)		\
		PROFILE_FILE=$(PROFILE_FILE) PROFILE_PATH=$(PROFILE_FILE)				\
		PROFILE=$(CONFIG_BCM_KERNEL_PROFILE)									\
		V=$(BRCM_VERBOSE) $(if $(BRCM_VERBOSE),Q=) buildimage

	# Re-timestamp everything due to buildimage fiddle around everywhere
	touch .kernel .userspace_tools .cfe_$(CONFIG_ARCH) .cfe_common $@


.cfe_common: $(if $(CONFIG_BCM_OPEN),,.cfe_$(CONFIG_ARCH))
	$(call pad_to_boundary,\
		"$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)_nand.v", $(nandBlocksize))

	# Create a default nvram mirror populated with sane defaults.
	$(HOSTTOOLS_DIR)/createimg.pl --set 										\
		boardid="" voiceboardid=""												\
		numbermac=$(BRCM_NUM_MAC_ADDRESSES) macaddr=$(BRCM_BASE_MAC_ADDRESS)	\
		tp=$(BRCM_MAIN_TP_NUM) psisize=$(BRCM_PSI_SIZE)							\
		logsize=$(BRCM_LOG_SECTION_SIZE) auxfsprcnt=$(BRCM_AUXFS_PERCENT)		\
		gponsn=$(BRCM_GPON_SERIAL_NUMBER) gponpw=$(BRCM_GPON_PASSWORD)			\
		--nvramfile $(HOSTTOOLS_DIR)/nvram.h                       				\
		--nvramdefsfile $(HOSTTOOLS_DIR)/nvram_defaults.h --replace_nvram		\
		--nvram_magic --output_nvram_bin_only									\
		--config=$(wildcard $(HOSTTOOLS_DIR)/local_install/conf/$(ARCH)-*.conf)	\
		--outputfile="$(cfeTop)/bcm63xx_rom/nvram_mirror"
	$(call pad_to_boundary, "$(cfeTop)/bcm63xx_rom/nvram_mirror", 1024)

	# Join nvram mirror and cfe rom mirror for the Broadcom gen3 bootrom bootloader.
	cat "$(cfeTop)/bcm63xx_rom/nvram_mirror"									\
		"$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)rom_mirror.bin"			\
		>"$(cfeTop)/bcm63xx_rom/mirror.bin"
	$(call pad_to_boundary,														\
		"$(cfeTop)/bcm63xx_rom/mirror.bin", $(nandBlocksize))

	# Calculate how many times we can fit the mirror image into the
	# CFE partition. Leave half empty for potentially bad blocks.
	nr_mirrors=$$(( ( $$(( $(nandBlocksize) *									\
		$$($(call check_flashlayout, CFE_BLKS)) / 2)) - $$(stat -c%s			\
		"$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)_nand.v") ) /			\
		$$(stat -c%s "$(cfeTop)/bcm63xx_rom/mirror.bin")));						\
		for i in $$(seq 1 $$nr_mirrors); do										\
			cat "$(cfeTop)/bcm63xx_rom/mirror.bin"								\
				>>"$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)_nand.v";		\
		done
	touch $@


.PHONY: .cfe_mips32
.cfe_mips32: .cfe_mips
.cfe_mips: .userspace_tools
.cfe_mips: .extra_boardparms
.cfe_mips: $(shell find -P "$(bcmTop)/cfe/cfe"									\
			"$(bcmTop)/cfe/build/broadcom/bcm63xx_ram/Makefile"					\
			"$(bcmTop)/cfe/build/broadcom/bcm63xx_rom/Makefile"					\
			-cnewer ".cfe_$(CONFIG_ARCH)" -type f								\
			! -name ".*" -a ! -name "*.o" -a  ! -name "*auto*" -a ! -perm /111)
	mkdir -p "$(bcmTop)/targets/cfe"
	$(MAKE) -C "$(cfeTop)/bcm63xx_rom" SHELL=$(SHELL) $(JOBSERVER)				\
		INC_NVRAM_MIRRORING=1 CFG_OPTIONS="INC_NVRAM_MIRRORING:"				\
		cfe$(CONFIG_BCM_CHIP_ID)

	# NAND flash layout for MIPS bootrom gen1 (example 963268)
	# Block   Address          Description
	# ------------------------------------------
	# 0       0x000000         CFE rom (cpu boots here)
	# 1       0x020000         nvram mirror
	# 1       0x020800         unused CFE rom mirror, for compatibillity with ARM bootrom gen3
	# 2       0x040000         nvram mirror
	# 2       0x040800         unused CFE rom mirror, for compatibillity with ARM bootrom gen3
	# 3       0x060000         nvram mirror
	# 3       0x060800         unused CFE rom mirror, for compatibillity with ARM bootrom gen3
	# 8       0x100000         CFE ram rescue (inside a mini UBI)
	# 16      0x200000         UBI (with normal CFE ram, kernel and rootfs)
	# total-4                  MTD bad block table in the last four blocks

	# For bootrom Gen1 CFE mirror is identical to XIP.
	cp -vf "$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)rom.bin"				\
		"$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)_nand.v"
	cp -vf "$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)rom.bin"				\
		"$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)rom_mirror.bin"
	touch $@


.cfe_arm: .userspace_tools
.cfe_arm: .extra_boardparms
.cfe_arm: $(shell find -P "$(bcmTop)/cfe/cfe"									\
			"$(bcmTop)/cfe/build/broadcom/bcm63xx_ram/Makefile"					\
			"$(bcmTop)/cfe/build/broadcom/bcm63xx_rom/Makefile"					\
			-cnewer ".cfe_$(CONFIG_ARCH)" -type f								\
			! -name ".*" -a ! -name "*.o" -a  ! -name "*auto*" -a ! -perm /111)
	mkdir -p "$(bcmTop)/targets/cfe"
	[ -d "$(bcmTop)/cfe/cfe/api" ]												# Must exist.
	$(MAKE) -C "$(cfeTop)/bcm63xx_rom" SHELL=$(SHELL) $(JOBSERVER)
	[ -s "$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)rom.bin" ]				# Deleted by Broadcom if size to large for flash.

	# NAND flash layout for ARM XIP bootrom gen2 (example 963138)
	# Block   Address          Description
	# ------------------------------------------
	# 0       0x000000         empty
	# 0       0x010000         CFE rom (cpu boots here)
	# 0       0x010580         nvram (inside CFE rom)
	# 1       0x020000         nvram mirror
	# 1       0x020800         unused CFE rom mirror, for compatibillity with ARM bootrom gen3
	# 2       0x040000         nvram mirror
	# 2       0x040800         unused CFE rom mirror, for compatibillity with ARM bootrom gen3
	# 3       0x060000         nvram mirror
	# 3       0x060800         unused CFE rom mirror, for compatibillity with ARM bootrom gen3
	# 8       0x100000         CFE ram rescue (inside a mini UBI)
	# 16      0x200000         unused space
	# 32      0x400000         UBI (with normal CFE ram, kernel and rootfs)
	# total-4                  MTD bad block table in the last four blocks

	# NAND flash layout for ARM bootrom gen3 (example 96846)
	# Block   Address          Description
	# ------------------------------------------
	# 0       0x000000         empty
	# 0       0x010580         nvram
	# 1       0x020000         nvram mirror
	# 1       0x020800         CFE rom mirror
	# 2       0x040000         nvram mirror
	# 2       0x040800         CFE rom mirror
	# 3       0x060000         nvram mirror
	# 3       0x060800         CFE rom mirror
	# 8       0x100000         CFE ram rescue (inside a mini UBI)
	# 16      0x200000         unused space
	# 32      0x400000         UBI (with normal CFE ram, kernel and rootfs)
	# total-4                  MTD bad block table in the last four blocks

	# Add tag to CFE ram for the Broadcom Gen3 bootrom bootloader.
	$(HOSTTOOLS_DIR)/scripts/rom_tag.pl --chip=$(CONFIG_BCM_CHIP_ID)			\
		--sec_arch=$(SECURE_BOOT_ARCH) --byteorder=$(ENDIAN)					\
		--in="$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)rom.bin"			\
		--out="$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)rom_mirror.bin"

	$(call create_padding,														\
		"$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)_nand.v", 65536);

	# Add CFE rom after padding for XIP boards. XIP boot loader starts
	# at 64k offset. Accoding to the Broadcom documentation, the Gen3
	# bootrom boot loader should start at at 4k but the SDK defaults
	# to writing nvram at an 64k offset, corrupting the boot
	# loader. Until this is fixed, leave block 0 untouched in for
	# BTRM_BOOT_ONLY boards.
	if ! $(call check_config, BTRM_BOOT_ONLY, y); then							\
		cat "$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)rom.bin" 			\
		>>"$(cfeTop)/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)_nand.v";				\
	fi
	touch $@


.userspace_tools: .kernel
.userspace_tools: $(shell find -P "$(bcmTop)"									\
			-cnewer ".userspace_tools" -type f									\
			! -wholename "$(bcmTop)/kernel*" -a									\
			! -wholename "$(bcmTop)/cfe*" -a									\
			! -wholename "$(bcmTop)/targets/cfe*" -a							\
			! -wholename "$(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)*" -a	\
			! -name ".*" -a ! -name "*.o" -a  ! -name "*auto*" -a ! -perm /111)
	# Patch to build Broadcom Mini Driver Kit in parallell
	f="$(bcmTop)/userspace/private/libs/mdk/Makefile";							\
	if ! grep -qE "intenoparallell" "$$f"; then									\
		echo "all: intenoparallell" >>"$$f";									\
		echo ".PHONY: intenoparallell" >>"$$f";									\
		echo "intenoparallell: untar" >>"$$f";									\
		echo -en "\t\$$(MAKE) -C \$$(MDK_BLD_DIR)" >>"$$f";						\
		echo " SHELL=$(SHELL) $(JOBSERVER)" >>"$$f";							\
		$(call git_ignore, "$$f");												\
	fi

	install -d $(wildcard $(bcmTop)/kernel/linux-*)/include/config
	echo "EXTRA_CFLAGS += -DCONFIG_BCM9$(CONFIG_BCM_CHIP_ID)"					\
		>>$(wildcard $(bcmTop)/kernel/linux-*)/include/config/auto.conf
	$(MAKE) -C "$(bcmTop)" -f "build/Makefile" SHELL=$(SHELL) $(JOBSERVER)		\
		PROFILE_FILE=$(PROFILE_FILE) PROFILE_PATH=$(PROFILE_FILE)				\
		PROFILE=$(CONFIG_BCM_KERNEL_PROFILE)									\
		PERL5LIB=$(PERL5LIB) V=$(BRCM_VERBOSE) $(if $(BRCM_VERBOSE),Q=)			\
		userspace hosttools

	# Factory production tools, used in iopsys-production-scripts
	$(MAKE) -f "$(bcmTop)/hostTools/Makefile-production" SHELL=$(SHELL)				\
		$(JOBSERVER) PROFILE_FILE=$(PROFILE_FILE) PROFILE_PATH=$(PROFILE_FILE)	\
		PROFILE=$(CONFIG_BCM_KERNEL_PROFILE) PERL5LIB=$(PERL5LIB)				\
		V=$(BRCM_VERBOSE) $(if $(BRCM_VERBOSE),Q=)								\
		BUILD_DIR="$(bcmTop)" createnfimg editnvram
	touch $@


.kernel: .extra_boardparms
.kernel: .prep_bcm_sdk $(wildcard $(bcmTop)/make.*) $(profileGen)
.kernel: $(bcmTop)/hostTools/scripts/defconfig-bcm.template
.kernel: $(wildcard $(bcmTop)/hostTools/scripts/gendefconfig.d/*.conf)
.kernel: $(shell find -P "$(bcmTop)/kernel" "$(bcmTop)/bcmdrivers"				\
			"$(bcmTop)/shared" -cnewer ".kernel" -type f						\
			! -wholename "$(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)*" -a	\
			! -name ".*" -a ! -name "*.o" ! -name "*auto*" -a ! -perm /111)
.kernel: $(shell find -P "$(bcmTop)/kernel" "$(bcmTop)/bcmdrivers"				\
			"$(bcmTop)/shared" -cnewer ".kernel" -type f -name "*.[hc]")
	touch "$(bcmTop)/build/iopsys-do-kernel"									# Workaround for Broadcom broken dependencies.
	$(MAKE) -C "$(bcmTop)" -f "build/Makefile" SHELL=$(SHELL) $(JOBSERVER)		\
		PROFILE_FILE=$(PROFILE_FILE) PROFILE_PATH=$(PROFILE_FILE)				\
		PROFILE=$(CONFIG_BCM_KERNEL_PROFILE) 									\
		BUILD_WL_PARALLEL=y V=$(BRCM_VERBOSE) $(if $(BRCM_VERBOSE),Q=)			\
		INSTALL_MOD_PATH=$(CURDIR)/$(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)/modules \
		kernelbuild
	$(MAKE) -C "$(bcmTop)" -f "build/Makefile" SHELL=$(SHELL) $(JOBSERVER)		\
		PROFILE_FILE=$(PROFILE_FILE) PROFILE_PATH=$(PROFILE_FILE)				\
		PROFILE=$(CONFIG_BCM_KERNEL_PROFILE)									\
		BUILD_WL_PARALLEL=y V=$(BRCM_VERBOSE) $(if $(BRCM_VERBOSE),Q=)			\
		INSTALL_MOD_PATH=$(CURDIR)/$(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)/modules \
		modbuild
	touch $@


$(profileGen): .prep_bcm_sdk Makefile
$(profileGen): $(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)/$(CONFIG_BCM_KERNEL_PROFILE)
$(profileGen): $(wildcard $(bcmTop)/targets/common/bcmcreator-[0-9]*.conf)
$(profileGen): $(wildcard $(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)/bcmcreator-[0-9]*.conf)
$(profileGen): $(wildcard .configured_*) $(wildcard .prepared_*)
	# Generate a profile dynamically by extending Broadcoms default. Works pretty
	# much as "gendefconfig.d" but for the SDK. Note that all Broadcocm "BUILD_xxx"
	# macros are removed by default due to we want as little as possible.
	grep -vE "^(# )?BUILD_" \
		"$(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)/$(CONFIG_BCM_KERNEL_PROFILE)"	\
		>"$(profileGen)"
	for f in $(bcmTop)/targets/common/bcmcreator-[0-9]*.conf							\
			$(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)/bcmcreator-[0-9]*.conf; do	\
		if [ -r "$$f" ]; then															\
			cat "$$f" >>"$(profileGen)";												\
		fi;																				\
	done


	echo "# BUILD_PHY_MULTIMODE is not set" >>"$(profileGen)"
	echo "# BUILD_DSL is not set" >>"$(profileGen)"
	echo "# BUILD_DSLDIAGD is not set" >>"$(profileGen)"
	echo "# BUILD_DSL_LOOP_DIAG is not set" >>"$(profileGen)"
	echo "# BUILD_DSL_SELT_TEST is not set" >>"$(profileGen)"
	echo "# BUILD_XTMCTL is not set" >>"$(profileGen)"
	echo "# BUILD_ATMWAN is not set" >>"$(profileGen)"
	echo "# BUILD_PTMWAN is not set" >>"$(profileGen)"
	echo "# BUILD_ATMLOOPBACK is not set" >>"$(profileGen)"
	echo "# BRCM_DRIVER_ADSL is not set" >>"$(profileGen)"
	echo "# BRCM_VOICE_SUPPORT is not set" >>"$(profileGen)"

	echo "BUILD_NAND_IMG_BLKSIZE_$$(($(strip $(nandBlocksize)) / 1024))KB=y"	\
		>>"$(profileGen)"

	# Verify generated config is valid
    ifneq ($(CONFIG_BCM_OPEN),y)
		$(bcmTop)/hostTools/scripts/Configure -c $(bcmTop)/targets/config.in -f $(profileGen)
		touch $@
    endif


.prep_bcm_sdk:
	# Live patching of the SDK. By not having these as static patches in Git
	# we can escape lots of cherry-picking next time Broadcom releases an SDK
	# upgrade (it's likely the live patches will work for next SDK as well).

	# Skip building of some userspace apps we know we don't need but
	# they are broken so they can't be disabled by the profile.
	$(call delete_and_ignore, $(bcmTop)/userspace/private/apps/tr69c/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/public/apps/radvd/autodetect)			# cant be disabled if we want IPv6 for others
	$(call delete_and_ignore, $(bcmTop)/userspace/public/apps/memaccess/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/public/apps/send_cms_msg/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/public/apps/bcm_boot_launcher/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/public/apps/bcm_bootstate)
	$(call delete_and_ignore, $(bcmTop)/userspace/public/apps/bcm_flasher/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/public/libs/bcm_sslconf/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/public/libs/expat/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/gpl/apps/mmc-utils/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/private/apps/telnetd/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/private/libs/mdm/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/private/apps/ssk/autodetect)
	$(call delete_and_ignore, $(bcmTop)/userspace/private/apps/dectd/autodetect)

ifneq ($(CONFIG_BCM_OPEN),y)
		# Generate version headers
		$(MAKE) -C "$(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/dhd/src/include/" SHELL=$(SHELL)
		$(MAKE) -C "$(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/include/" SHELL=$(SHELL)
endif

	# Ignore changes to some files the SDK modifies
	# during build (make git status look nice).
	$(call git_ignore, $(wildcard $(bcmTop)/hostTools/make_ext4fs/zlib/*.h))
	$(call git_ignore, $(wildcard $(bcmTop)/hostTools/scripts/lxdialog/lxdialog))
	$(call git_ignore, $(wildcard $(bcmTop)/hostTools/xz-*/config.h.in))
	$(call git_ignore, $(wildcard $(bcmTop)/hostTools/xz-*/configure))
	$(call git_ignore, $(wildcard $(bcmTop)/userspace/gpl/apps/iperf/iperf-*/configure))
	$(call git_ignore, $(wildcard $(bcmTop)/userspace/public/apps/tcpdump/tcpdump/README))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/components/apps/visualization/datacollector/aclocal.m4))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/components/apps/visualization/datacollector/configure))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/components/apps/visualization/datacollector/visdata))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/components/apps/visualization/datacollector/Makefile.in))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/components/apps/visualization/dataconcentrator/aclocal.m4))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/components/apps/visualization/dataconcentrator/configure))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/components/apps/wbd2/prebuilt/*))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/components/opensource/libpcap_winpcap/*))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/router/config/.defconfig-2.6-vista-dhdap-router-atlas))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/router/config/defconfig-2.6-vista-dhdap-router-atlas))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/router/shared/.bcmconfig.h))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/router/shared/bcmconfig.h))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/router/*/*-arma9))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/router/*/*-mips32))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/router/*/*/*-arma9))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/router/*/*/*-mips32))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/router/*/*.so))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/emf/*_arma9.o_save))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/emf/*_mips32.o_save))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/wps/*-arma9))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/wps/*-mips32))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/*-arma9.o_save))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/*-mips32.o_save))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/epivers))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/include/epivers.h))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/rver))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/dhd/src/dhdobj-dhdconfig*.o_save))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/dhd/src/epivers))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/dhd/src/include/epivers.h))
	$(call git_ignore, $(wildcard $(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/dhd/src/rver))
	$(call git_ignore, $(wildcard $(bcmTop)/kernel/linux-*/arch/*/boot/dts/include/dt-bindings))
	$(call git_ignore, $(wildcard $(bcmTop)/kernel/linux-*/tools/testing/selftests/powerpc/copyloops/*.S))
	$(call git_ignore, $(wildcard $(bcmTop)/kernel/linux-*/tools/testing/selftests/powerpc/primitives/asm/*.h))
	$(call git_ignore, $(wildcard $(bcmTop)/kernel/linux-*/tools/testing/selftests/powerpc/primitives/*.h))
	$(call git_ignore, $(wildcard $(bcmTop)/kernel/linux-*/tools/testing/selftests/powerpc/stringloops/*.S))
	$(call git_ignore, $(wildcard $(bcmTop)/kernel/linux-*/tools/testing/selftests/powerpc/vphn/vphn.*))

	# Fix a missing path for hostTools/libcreduction
	#mkdir -p $(bcmTop)/targets/$(CONFIG_BCM_KERNEL_PROFILE)/fs.install/usr/lib

	# Make Broadcom kernel features selectable by kernel gendefconfig.d .config
	sed -i -r -e "s|[[:space:]]bool$$|\tbool \"\"|g"							\
		$(wildcard $(bcmTop)/kernel/linux-*/Kconfig.bcm_kf)						\
		$(wildcard $(bcmTop)/kernel/linux-*/Kconfig.bcm)
	$(call git_ignore, $(wildcard $(bcmTop)/kernel/linux-*/Kconfig.bcm_kf))
	$(call git_ignore, $(wildcard $(bcmTop)/kernel/linux-*/Kconfig.bcm))

	touch $@


#----------------------------													# Cleaning	
.PHONY: clean
clean:
	-$(MAKE) -C "$(bcmTop)" -f "build/Makefile" SHELL=$(SHELL) $(JOBSERVER)		\
		PROFILE_FILE=$(PROFILE_FILE) PROFILE_PATH=$(PROFILE_FILE)		\
		PROFILE=$(CONFIG_BCM_KERNEL_PROFILE) cleanall
	$(MAKE) -C "$(bcmTop)" -f "bcmdrivers/Makefile" clean
	$(MAKE) -C "$(bcmTop)/bcmdrivers/broadcom/net/wl/impl32" -f Makefile.clean	\
		SHELL=$(SHELL) $(JOBSERVER) clean
	$(MAKE) -f "$(bcmTop)/hostTools/Makefile-production" SHELL=$(SHELL)			\
		$(JOBSERVER) PROFILE_FILE=$(PROFILE_FILE) PROFILE_PATH=$(PROFILE_FILE)	\
		PROFILE=$(CONFIG_BCM_KERNEL_PROFILE) BUILD_DIR="$(bcmTop)" clean
	-for d in $$(find "$(bcmTop)/bcmdrivers/broadcom/net/wl/"				\
			-name Makefile -printf "%h\n"); do									\
		$(MAKE) -C $$d SHELL=$(SHELL) $(JOBSERVER) PROFILE_FILE=$(PROFILE_FILE)	\
			PROFILE_PATH=$(PROFILE_FILE) PROFILE=$(CONFIG_BCM_KERNEL_PROFILE)	\
			WIRELESS_DRIVER_PATH="$$PWD/$(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/dhd/src/wl/exe" \
			clean;																\
	done
	$(MAKE) -C "$(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/dhd/src/include"	\
		SHELL=$(SHELL) $(JOBSERVER) clean
	rm -rf "$(bcmTop)/images/"* ipkg-iopsys-brcm63xx-*
	for d in "$(bcmTop)"/targets/96*; do										\
		rm -rf $$d/bootfs $$d/fs $$d/fs.build $$d/fs.install $$d/modules;		\
		rm -rf $$d/*.w $$d/*.img $$d/*.bin $$d/vmlinux* $$d/bcmcreator.conf;	\
	done
	find "$(bcmTop)/bcmdrivers" -depth -name "*.d.*" -o -name "*.d" -delete
	find "$(bcmTop)" -name "*.o.cmd" -type f -delete
	find "$(bcmTop)" -name "*.o" -type f -delete
	-find "$(bcmTop)" -type f -newer .prep_bcm_sdk -name "*.d" -delete
	rm -f "$(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/src/router/.config.plt"
	find "$(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main" -name "*.depend" -delete
	$(MAKE) -C "$(wildcard $(bcmTop)/kernel/linux-*)" SHELL=$(SHELL) ARCH=arm mrproper
	$(MAKE) -C "$(wildcard $(bcmTop)/kernel/linux-*)" SHELL=$(SHELL) ARCH=mips mrproper
	find "$(bcmTop)" -type l -name "bcm9*" -delete
	$(MAKE) -C "$(cfeTop)/bcm63xx_ram" SHELL=$(SHELL) $(JOBSERVER)				\
		BRCM_CHIP=$(CONFIG_BCM_CHIP_ID) clean
	$(MAKE) -C "$(cfeTop)/bcm63xx_rom" SHELL=$(SHELL) $(JOBSERVER)				\
		BRCM_CHIP=$(CONFIG_BCM_CHIP_ID) clean
	rm -f "$(cfeTop)/bcm63xx_rom/"*.tmp
	rm -f "$(bcmTop)/bcmdrivers/broadcom/char/dect/impl1/.last_build"
	rm -f "$(bcmTop)/userspace/public/include/cms_version.h"
	-cd "$(bcmTop)/bcmdrivers/broadcom/net/wl/impl32/main/components/apps/visualization/datacollector" && \
		xargs -r <".gitignore" rm -rf
	find "$(bcmTop)/targets" -type d -name fs.install -o -name fs.build | xargs -r rm -rf
	find "$(bcmTop)/targets" -type d -path "*/modules/lib/modules/*" | xargs -r rm -rf
	find "$(bcmTop)/userspace" -type f -name "*.so" | xargs -r rm -rf
	find "$(bcmTop)/userspace/private/libs/mdk" -name "installed-chips" -delete
	rm -f "$(bcmTop)/hostTools/scripts/lxdialog/lxdialog"						\
		"$(bcmTop)/.check_clean" "$(bcmTop)/hostTools/xz-*/" "$(profileGen)"
	find "$(bcmTop)" -name ".last_profile"
	find "$(bcmTop)" -name ".host_perlarch" -delete
	find "$(bcmTop)" -type l -delete
	rm -f "$(bcmTop)/build/iopsys-do-kernel" "$(bcmTop)/build/olddefconfig"		\
		"$(bcmTop)/build/bcm_vmlinux" "$(bcmTop)/build/modules"					\
		"$(bcmTop)/build/modules_install" "$(bcmTop)/build/dtbs"				\
		"$(bcmTop)/build/version_info"								\
		"$(bcmTop)/kernel"/linux-*/.version										\
		"$(bcmTop)/kernel"/linux-*/.pre_kernelbuild								\
		"$(bcmTop)/kernel"/linux-*/include/linux/bcm_swversion.h				\
		"$(bcmTop)/kernel"/linux-*/vmlinux.map									\
		"$(bcmTop)/targets/"*/bcmcreator.conf.old
	rm -f "$(boardparms_dir)"/*.xbp.c
	rm -f .cfe_common .cfe_mips .cfe_arm .kernel .userspace_tools .prep_bcm_sdk	\
		.images .install .configured_* .extra_boardparms


#-----------------------------
.PHONY: install
install: .install
.install: .images
	$(INSTALL_DIR) $(INSTALLDIR)/lib
	$(INSTALL_DIR) $(INSTALLDIR)/usr/sbin
	$(INSTALL_DIR) $(INSTALLDIR)/usr/lib
	$(INSTALL_DIR) $(INSTALLDIR)/usr/bin
	$(INSTALL_DIR) $(INSTALLDIR)/etc/wlan
	$(INSTALL_DIR) $(INSTALLDIR)/etc/cms_entity_info.d
	$(INSTALL_DIR) $(INSTALLDIR)/etc/modules.d

#	# Install header files
	$(INSTALL_DIR) $(STAGING_DIR)/usr/include/bcm963xx/bcmdrivers/broadcom/include/bcm963xx
	$(INSTALL_DIR) $(STAGING_DIR)/usr/include/bcm963xx/bcmdrivers/opensource/include/bcm963xx
	$(INSTALL_DIR) $(STAGING_DIR)/usr/include/bcm963xx/shared/opensource/include/bcm963xx
	$(INSTALL_DIR) $(STAGING_DIR)/usr/include/bcm963xx/xchg/bos/LinuxUser
	$(INSTALL_DIR) $(STAGING_DIR)/usr/include/bcm963xx/xchg/bos/publicInc
	$(INSTALL_DIR) $(STAGING_DIR)/usr/lib

	$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/kernel/linux-4.1/include/* $(STAGING_DIR)/usr/include/
	$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/kernel/linux-4.1/arch/$(CONFIG_ARCH)/include/* $(STAGING_DIR)/usr/include/
	if [ -d $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/kernel/linux-4.1/arch/$(CONFIG_ARCH)/include/asm/mach-bcm63xx ]; then								\
		$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/kernel/linux-4.1/arch/$(CONFIG_ARCH)/include/asm/mach-bcm63xx/* $(STAGING_DIR)/usr/include/asm;	\
	fi
	$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/shared/opensource/include/bcm963xx/* $(STAGING_DIR)/usr/include/bcm963xx/shared/opensource/include/bcm963xx
	$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/bcmdrivers/opensource/include/bcm963xx/* $(STAGING_DIR)/usr/include/bcm963xx/bcmdrivers/opensource/include/bcm963xx/

	echo "#define BCM_SDK_VERSION $(BRCM_SDK_VERSION)" > $(STAGING_DIR)/usr/include/bcm_sdk_version.h

# create symlink to kernel build directory
	if [ -d "$(BUILD_DIR)/$(PKG_SOURCE_SUBDIR)" ]; then							\
		rm -f $(BUILD_DIR)/bcmkernel;											\
		ln -sfn $(PKG_SOURCE_SUBDIR) $(BUILD_DIR)/bcmkernel;					\
	fi
# Install binaries

# auto channel selection
ifeq ($(BUILD_BRCM_CPEROUTER),)
	$(call install_wifi, $(BCM_FS_DIR)/bin/acs_cli, $(INSTALLDIR)/usr/sbin/)
	$(call install_wifi, $(BCM_FS_DIR)/bin/acsd, $(INSTALLDIR)/usr/sbin/)
else
	# adding both for now
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/acs_cli, $(INSTALLDIR)/usr/sbin/)
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/acsd, $(INSTALLDIR)/usr/sbin/)
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/acs_cli2, $(INSTALLDIR)/usr/sbin/)
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/acsd2, $(INSTALLDIR)/usr/sbin/)
endif

# fiber related utils
	$(CP) $(BCM_FS_DIR)/bin/scratchpadctl $(INSTALLDIR)/usr/sbin/
	$(CP) $(BCM_FS_DIR)/bin/pspctl $(INSTALLDIR)/usr/sbin/
	$(call install_brcm, BRCM_PON_WAN_TYPE_AUTO_DETECT,							\
		$(BCM_FS_DIR)/bin/wanconf $(INSTALLDIR)/usr/sbin/)

# tmctl - traffic manager
	$(CP) $(BCM_FS_DIR)/bin/tmctl $(INSTALLDIR)/usr/sbin/

# bcm bridge control
	$(CP) $(BCM_FS_DIR)/bin/brctl $(INSTALLDIR)/usr/sbin/

# band steering daemon
# switch between 2.4 and 5 GHz wifi
ifeq ($(BUILD_BRCM_CPEROUTER),)
	$(call install_wifi, $(BCM_FS_DIR)/bin/bsd, $(INSTALLDIR)/usr/sbin/)
else
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/bsd, $(INSTALLDIR)/usr/sbin/)
endif

# wireless control util for AC cards using dhd (offloading) module
# dhd -> dhdctl
	$(call install_wifi, $(BCM_FS_DIR)/bin/dhdctl, $(INSTALLDIR)/usr/sbin/)
ifneq ($(BUILD_BRCM_CPEROUTER),)
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/dhd, $(INSTALLDIR)/usr/sbin/)
endif

# daemon used to check bcm nvram wifi parameters
	$(call install_wifi, $(BCM_FS_DIR)/bin/eapd, $(INSTALLDIR)/usr/sbin/)

# layer 2 packet filtering (could we use openwrt?)
	$(CP) $(BCM_FS_DIR)/bin/ebtables $(INSTALLDIR)/usr/sbin/

# ethernet control utility extended with brcm ioctl:s
	$(CP) $(BCM_FS_DIR)/bin/ethctl $(INSTALLDIR)/usr/sbin/

# ethernet switch control utility extended with brcm ioctl:s
	$(CP) $(BCM_FS_DIR)/bin/ethswctl $(INSTALLDIR)/usr/sbin/

#	# bcm fast packet accelerator utility
	if [ -f "$(BCM_FS_DIR)/bin/fapctl" ]; then									\
		$(CP) $(BCM_FS_DIR)/bin/fapctl $(INSTALLDIR)/usr/sbin/;					\
	fi

# bcm flow cache utility
# fc -> fcctl
#	$(CP) $(BCM_FS_DIR)/bin/fc $(INSTALLDIR)/usr/sbin/
	$(CP) $(BCM_FS_DIR)/bin/fcctl $(INSTALLDIR)/usr/sbin/

# brcm multicast daemon
	$(CP) $(BCM_FS_DIR)/bin/mcpd $(INSTALLDIR)/usr/sbin/

# brcm multicast utility
	$(CP) $(BCM_FS_DIR)/bin/bcmmcastctl $(INSTALLDIR)/usr/sbin/

#	# brcm switch related utility
	if [ -f "$(BCM_FS_DIR)/bin/mdkcmd" ]; then									\
		$(CP) $(BCM_FS_DIR)/bin/mdkcmd $(INSTALLDIR)/usr/sbin/;					\
	fi
#	$(call install_brcm, BUILD_MDK_SHELL, $(BCM_FS_DIR)/bin/mdkshell, $(INSTALLDIR)/usr/sbin/)

# wifi authentication daemon
ifeq ($(BUILD_BRCM_CPEROUTER),)
	$(call install_wifi, $(BCM_FS_DIR)/bin/nas, $(INSTALLDIR)/usr/sbin/)
else
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/nas, $(INSTALLDIR)/usr/sbin/)
endif

# brcm nvram utility
	$(call install_wifi, $(BCM_FS_DIR)/bin/nvram, $(INSTALLDIR)/usr/sbin/)

# update nvram from a file
	$(call install_wifi, $(BCM_FS_DIR)/bin/nvramUpdate, $(INSTALLDIR)/usr/sbin/)

# brcm power control utility
# pwr -> pwrctl
#	$(CP) $(BCM_FS_DIR)/bin/pwr $(INSTALLDIR)/usr/sbin/
	$(CP) $(BCM_FS_DIR)/bin/pwrctl $(INSTALLDIR)/usr/sbin/

# brcm system daemon
	$(CP) $(BCM_FS_DIR)/bin/smd $(INSTALLDIR)/usr/sbin/

# brcm switch daemon
#	$(call install_brcm, BUILD_SWMDK, $(BCM_FS_DIR)/bin/swmdk, $(INSTALLDIR)/usr/sbin/)

# unknown
	$(call install_brcm, BUILD_TMS, $(BCM_FS_DIR)/bin/tmsctl, $(INSTALLDIR)/usr/sbin/)

# brcm vlan controller
	$(CP) $(BCM_FS_DIR)/bin/vlanctl $(INSTALLDIR)/usr/sbin/

#	# brcm BPM control and ingress QoS control utility
	if [ -f "$(BCM_FS_DIR)/bin/bpmctl" ]; then									\
		$(CP) $(BCM_FS_DIR)/bin/bpmctl $(INSTALLDIR)/usr/sbin/					&& \
		$(CP) $(BCM_FS_DIR)/bin/bpm $(INSTALLDIR)/usr/sbin/						&& \
		$(CP) $(BCM_FS_DIR)/bin/iqctl $(INSTALLDIR)/usr/sbin/					&& \
		$(CP) $(BCM_FS_DIR)/bin/iq $(INSTALLDIR)/usr/sbin/;						\
	fi

# brcm wireless configuration tool
# reads from nvram and configures wifi with wlctl commands
ifeq ($(BUILD_BRCM_CPEROUTER),)
	$(call install_wifi, $(BCM_FS_DIR)/bin/wlconf, $(INSTALLDIR)/usr/sbin/)
else
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/wlconf, $(INSTALLDIR)/usr/sbin/)
ifeq ($(BUILD_BRCM_HOSTAPD),y)
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/iw, $(INSTALLDIR)/usr/sbin/)
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/hostapd, $(INSTALLDIR)/usr/sbin/)
endif
endif

# brcm wireless configuration utility
	$(call install_wifi, $(BCM_FS_DIR)/bin/wlctl, $(INSTALLDIR)/usr/sbin/)
ifneq ($(BUILD_BRCM_CPEROUTER),)
	$(call install_wifi, $(BCM_FS_DIR)/usr/sbin/wl, $(INSTALLDIR)/usr/sbin/)
endif

# brcm wps tools
	$(call install_wifi, $(BCM_FS_DIR)/bin/wps_monitor, $(INSTALLDIR)/usr/sbin/)
	$(warning WPS only in closed source?)
ifeq ($(BUILD_BRCM_CPEROUTER),)
	$(call install_wifi, $(BCM_FS_DIR)/bin/wps_cmd, $(INSTALLDIR)/usr/sbin/)
endif

# crypto acceleration 
#	if [ -f "$(BCM_FS_DIR)/bin/spuctl" ]; then									\
#		$(CP) $(BCM_FS_DIR)/bin/spuctl $(INSTALLDIR)/usr/sbin/;					\
#		$(CP) $(BCM_FS_DIR)/lib/libspuctl.so $(INSTALLDIR)/usr/lib/				\
#	fi
#	$(warning TODO: Use ipsec-tools from Iopsys instead of Broadcom?)

#	#$(CP) $(BCM_FS_DIR)/bin/setkey $(INSTALLDIR)/usr/sbin/

	$(CP) $(BCM_FS_DIR)/etc/cms_entity_info.d/eid_bcm_kthreads.txt $(INSTALLDIR)/etc/cms_entity_info.d/
	$(CP) $(BCM_FS_DIR)/etc/cms_entity_info.d/symbol_table.txt $(INSTALLDIR)/etc/cms_entity_info.d/

	# rdpa (Runner Data Path API) and bdmf_shell (Broadlight Device Management Framework)
	if [ -f $(BCM_FS_DIR)/etc/rdpa_init.sh ]; then								\
		$(CP) "$(BCM_FS_DIR)/etc/rdpa_init.sh" "$(INSTALLDIR)/etc/"				&& \
		$(CP) "$(BCM_FS_DIR)/bin/bs" "$(BCM_FS_DIR)/bin/bsi"					\
			"$(BCM_FS_DIR)/bin/bdmf_shell" "$(INSTALLDIR)/usr/sbin/"			&& \
		$(call install_brcm, BUILD_RDPA,										\
			"$(BCM_FS_DIR)/lib/libbdmf.so", "$(INSTALLDIR)/usr/lib");			\
	fi

	# Control of Broadcoms L2 and L3 tracing modifications
	$(CP) "$(BCM_FS_DIR)/bin/blogctl" "$(INSTALLDIR)/usr/sbin/"
	$(CP) "$(BCM_FS_DIR)/lib/libblogctl.so" "$(INSTALLDIR)/usr/lib/"

# Install libraries
	cd $(BCM_FS_DIR)/lib &&														\
		$(CP) -t $(INSTALLDIR)/usr/lib/											\
		libcms_cli.so libcms_core.so libcms_dal.so libcms_msg.so				\
		libcms_qdm.so  libfcctl.so libnanoxml.so libpwrctl.so					\
		libtmctl.so libvlanctl.so libcms_util.so libbcm_flashutil.so			\
		libethswctl.so libbridgeutil.so libethctl.so							\
		libbcm_boardctl.so libbcmmcast.so libiqctl.so libbcm_util.so			\
		libsys_util.so libgen_util.so

# Libs needed for wanconf utility
	$(call install_brcm, BRCM_PON_WAN_TYPE_AUTO_DETECT,							\
		$(BCM_FS_DIR)/lib/libpmd.so, $(INSTALLDIR)/usr/lib/)
	$(call install_brcm, BRCM_PON_WAN_TYPE_AUTO_DETECT, 						\
		$(BCM_FS_DIR)/lib/libjson-c.so.*, $(INSTALLDIR)/usr/lib/)

# tmctl uses this lib if we build with epon
	$(call install_brcm, BUILD_EPONCTL,											\
		$(BCM_FS_DIR)/lib/libeponctl.so, $(INSTALLDIR)/usr/lib/)

# ebtable is compiled as 64-bit for aarch64 kernel
	if $(call check_config, KERNEL_ARCH, aarch64); then							\
		cp -r $(BCM_FS_DIR)/lib64 $(INSTALLDIR)/;								\
		ln -s /lib64/gpl $(INSTALLDIR)/lib/gpl;									\
		cp $(BCM_FS_DIR)/lib/ld-linux-aarch64.so.* $(INSTALLDIR)/lib;			\
	else																		\
		cd $(BCM_FS_DIR)/lib;													\
		 $(CP) -t $(INSTALLDIR)/usr/lib/										\
			libebtable_broute.so libebtable_filter.so							\
			libebtable_nat.so libebtc.so libebt_ftos.so libebt_ip6.so			\
			libebt_ip.so libebt_mark_m.so libebt_mark.so libebt_skiplog.so		\
			libebt_standard.so libebt_time.so libebt_vlan.so 					\
			libebt_skbvlan.so libebt_blog.so libebt_qos_map.so					\
			libebt_ip_extend.so libebt_ip6_extend.so libebt_u32.so				\
			libebt_reject.so;													\
	fi

# ebtable is compiled as 64-bit for aarch64 kernel
	if $(call check_config, KERNEL_ARCH, aarch64); then										\
	$(call install_wifi, $(BCM_FS_DIR)/lib64/gpl/libebt_wmm_mark.so, $(INSTALLDIR)/usr/lib)	\
	else																					\
	$(call install_wifi, $(BCM_FS_DIR)/lib/libebt_wmm_mark.so, $(INSTALLDIR)/usr/lib)		\
	fi

	$(call install_wifi, $(BCM_FS_DIR)/lib/libwlcsm.so, $(INSTALLDIR)/usr/lib)
	$(call install_wifi, $(BCM_FS_DIR)/lib/libnvram.so, $(INSTALLDIR)/usr/lib)
ifeq ($(BUILD_BRCM_CPEROUTER),)
	$(call install_wifi, $(BCM_FS_DIR)/lib/libwlctl.so, $(INSTALLDIR)/usr/lib)
	$(call install_wifi, $(BCM_FS_DIR)/lib/libwlupnp.so, $(INSTALLDIR)/usr/lib)
	$(call install_wifi, $(BCM_FS_DIR)/lib/libwps.so, $(INSTALLDIR)/usr/lib)
	$(call install_wifi, $(BCM_FS_DIR)/lib/libwlbcmcrypto.so, $(INSTALLDIR)/usr/lib)
	$(call install_wifi, $(BCM_FS_DIR)/lib/libwlbcmshared.so, $(INSTALLDIR)/usr/lib)
	$(call install_wifi, $(BCM_FS_DIR)/lib/libbshared.so, $(INSTALLDIR)/usr/lib)
else
	$(call install_wifi, $(BCM_FS_DIR)/usr/lib/libbshared.so, $(INSTALLDIR)/usr/lib)
	$(call install_wifi, $(BCM_FS_DIR)/usr/lib/libshared.so, $(INSTALLDIR)/usr/lib)
	$(call install_wifi, $(BCM_FS_DIR)/usr/lib/libbcmcrypto.so, $(INSTALLDIR)/usr/lib)
endif

	# Copy toolchain C-lib from Broadcom as we need it for the brcm
	# utilities. ARM use glibc and MIPS use uClibc. Rest of Iopsys
	# use musl.
	F=$$(find $(BCM_FS_DIR)/lib/ld-uClibc.so.*);								\
		if [ -n "$$F" ]; then													\
			$(CP) $(BCM_FS_DIR)/lib/ld-uClibc.so.* $(INSTALLDIR)/lib/;			\
		fi
	F=$$(find $(BCM_FS_DIR)/lib/ld-linux.so.*);									\
		if [ -n "$$F" ]; then													\
			$(CP) $(BCM_FS_DIR)/lib/ld-linux.so.* $(INSTALLDIR)/lib/;			\
		fi
	$(CP) $(BCM_FS_DIR)/lib/libc.so.* $(INSTALLDIR)/lib/
	$(CP) $(BCM_FS_DIR)/lib/libcrypt.so.* $(INSTALLDIR)/lib/
	$(CP) $(BCM_FS_DIR)/lib/libdl.so.* $(INSTALLDIR)/lib/
	$(CP) $(BCM_FS_DIR)/lib/libm.so.* $(INSTALLDIR)/lib/
	$(CP) $(BCM_FS_DIR)/lib/libpthread.so.* $(INSTALLDIR)/lib/
	$(CP) $(BCM_FS_DIR)/lib/librt.so.* $(INSTALLDIR)/lib/

	if [ -f "$(BCM_FS_DIR)/lib/libfapctl.so" ]; then							\
		$(CP) $(BCM_FS_DIR)/lib/libfapctl.so									\
			$(BCM_FS_DIR)/lib/libiqctl.so $(INSTALLDIR)/usr/lib/;				\
	fi

	if [ -f "$(BCM_FS_DIR)/lib/libbcmtm.so" ]; then								\
		$(CP) $(BCM_FS_DIR)/lib/libbcmtm.so $(INSTALLDIR)/usr/lib/;				\
	fi

	# Iopsys brcm_fw_tool need libs from mtd-utils which has
	# been built with the same toolchain as the Broadcom SDK.
	$(CP) $(wildcard $(bcmTop)/userspace/gpl/apps/mtd/mtd-utils-*/libubi.a)		\
		$(STAGING_DIR)/usr/lib

#	# needed by tmctl on dg400
	if [ -f "$(BCM_FS_DIR)/lib/librdpactl.so" ]; then							\
		$(CP) $(BCM_FS_DIR)/lib/librdpactl.so $(INSTALLDIR)/usr/lib/;			\
	fi

	# GMAC
	if [ -f "$(BCM_FS_DIR)/lib/libgmacctl.so" ]; then							\
		$(CP) "$(BCM_FS_DIR)/lib/libgmacctl.so" "$(INSTALLDIR)/usr/lib/" &&		\
		$(CP) "$(BCM_FS_DIR)/bin/gmacctl" "$(INSTALLDIR)/usr/sbin/";			\
	fi

#	# Install kernel modules
	rm -rf $(INSTALLDIR)/lib/modules/$(BCM_KERNEL_VERSION)
	$(INSTALL_DIR) $(INSTALLDIR)/lib/modules
#	(cd $(BCM_FS_DIR)/lib/modules/$(BCM_KERNEL_VERSION) && find kernel -type f -name "*.ko" -exec ln -sfv {} . \;)
	$(CP) $(BCM_FS_DIR)/lib/modules/$(BCM_KERNEL_VERSION) $(INSTALLDIR)/lib/modules/
	(cd $(INSTALLDIR)/lib/modules/$(BCM_KERNEL_VERSION) && \
		find . -type f -name "*.ko" -exec ln -sfv {} . \; && \
		rm -f modules.*)

	# create config file to load modules
	mkdir -p $(INSTALLDIR)/etc/modules.d
	cat $(BCM_FS_DIR)/etc/init.d/bcm-base-drivers.sh | grep insmod | sed 's|.*/\(.*.ko.*\)|\1|' >$(INSTALLDIR)/etc/modules.d/49-brcm
	# the bcm_usb driver is needed for working usb on the 63138 arm platforms on mips one usb port stops working
	if [ $(ARCH) == mips ]; then												\
		sed -i '/bcm_usb_dev\.ko/d' $(INSTALLDIR)/etc/modules.d/49-brcm;		\
	fi
	sed -i 's|\.ko||' $(INSTALLDIR)/etc/modules.d/49-brcm

	$(call install_wifi, $(BCM_FS_DIR)/etc/wlan/*, $(INSTALLDIR)/etc/wlan)

#	rm -rf $(INSTALLDIR)/lib/modules/$(BCM_KERNEL_VERSION)/bcm_usb.ko

#	# Alternative DECT modules taken from the Natalie package and if that is not selected, no DECT modules should be loaded
	rm -f $(INSTALLDIR)/lib/modules/$(BCM_KERNEL_VERSION)/extra/dect.ko
	rm -f $(INSTALLDIR)/lib/modules/$(BCM_KERNEL_VERSION)/dect.ko

	$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/kernel/linux-*/vmlinux $(KDIR)/vmlinux.bcm.elf
	if $(call check_config, KERNEL_ARCH, aarch64); then																						\
		$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/targets/$(CONFIG_BCM_KERNEL_PROFILE)/vmlinux.bin $(KDIR)/vmlinux.bcm;						\
	else																																	\
		$(CROSS_COMPILE)strip --remove-section=.note --remove-section=.comment $(KDIR)/vmlinux.bcm.elf;										\
		$(CROSS_COMPILE)objcopy $(OBJCOPY_STRIP) -O binary $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/kernel/linux-*/vmlinux $(KDIR)/vmlinux.bcm;	\
	fi
	$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/kernel/dts/$(CONFIG_BCM_CHIP_ID)/9$(CONFIG_BCM_CHIP_ID).dtb $(KDIR)

#	# bootloader nor
#	cp -R $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/cfe/build/broadcom/bcm63xx_rom/bcm9$(CONFIG_BCM_CHIP_ID)_cfe.w $(KDIR)/bcm_bootloader_cfe.w

#	# ram part of the bootloader for nand boot
	if [ -f $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/cfe/build/broadcom/bcm63xx_ram/cfe$(CONFIG_BCM_CHIP_ID)ram.bin ]; then					\
		$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/cfe/build/broadcom/bcm63xx_ram/cfe$(CONFIG_BCM_CHIP_ID)ram.bin $(KDIR)/cferam.000;	\
	elif [ -f $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/cfe/build/broadcom/bcm63xx_ram/cfe$(CONFIG_BCM_CHIP_ID).bin ]; then					\
		$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/cfe/build/broadcom/bcm63xx_ram/cfe$(CONFIG_BCM_CHIP_ID).bin $(KDIR)/cferam.000;		\
	fi;
	$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/cfe/build/broadcom/bcm63xx_rom/cfe$(CONFIG_BCM_CHIP_ID)_nand*.v $(KDIR)
#	$(CP) $(PKG_BUILD_DIR)/$(BCM_SDK_VERSION)/targets/cfe $(KDIR)
#	dd if=$(KDIR)/vmlinux.bcm.elf of=$(KDIR)/vmlinux.bcm bs=4096 count=1
#	$(CROSS_COMPILE)objcopy $(OBJCOPY_STRIP) -S $(LINUX_DIR)/vmlinux $(KERNEL_BUILD_DIR)/vmlinux.elf

###############################################################################
# for emacs. this file uses tabs that at 4 instead of the default 8.
#
# Local Variables:
# tab-width: 4
# End:
