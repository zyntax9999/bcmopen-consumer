# By default, let make spawn 1 job per core.
# To set max jobs, specify on command line, BRCM_MAX_JOBS=8
# To also specify a max load, BRCM_MAX_JOBS="6 --max-load=3.0"
# To specify max load without max jobs, BRCM_MAX_JOBS=" --max-load=3.5"
ifneq ($(strip $(BRCM_MAX_JOBS)),)
ACTUAL_MAX_JOBS := $(BRCM_MAX_JOBS)
else
NUM_CORES := $(shell grep processor /proc/cpuinfo | wc -l)
ACTUAL_MAX_JOBS := $(NUM_CORES)
endif

# Since tms driver is called with -j1 and will call its sub-make with -j, 
# We want it to use this value. Although the jobserver is disabled for tms,
# at least tms is compiled with no more than this variable value jobs.
export ACTUAL_MAX_JOBS

# Define KERNEL_DIR, make sure it points to the correct kernel source directory
KERNEL_DIR := /path/to/your/kernel/source

# Default target
default:
	$(MAKE) -f build/Makefile -j$(ACTUAL_MAX_JOBS) $(MAKEOVERRIDES) $(MAKECMDGOALS)

# Custom goals
$(MAKECMDGOALS):
	$(MAKE) -f build/Makefile -j$(ACTUAL_MAX_JOBS) $(MAKEOVERRIDES) $(MAKECMDGOALS)

# Kernel menuconfig target
.PHONY: menuconfig
menuconfig:
	@$(MAKE) -C $(KERNEL_DIR) menuconfig

.PHONY: $(MAKECMDGOALS)

