LIB = libeponsdk.so
default: dynamic


libeponsdk.so:
	cp libeponsdk.so_$(PROFILE).save libeponsdk.so

dynamic: generic_private_lib_install

clean:
	rm -f libeponsdk.so

CURR_DIR := $(shell pwd)
BUILD_DIR := $(subst /userspace, /userspace,$(CURR_DIR))
BUILD_DIR := $(word 1, $(BUILD_DIR))
include $(BUILD_DIR)/make.common
