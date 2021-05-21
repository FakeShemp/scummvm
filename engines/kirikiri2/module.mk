MODULE := engines/kirikiri2
 
MODULE_OBJS := \
	metaengine.o \
	kirikiri2.o \
	lib/std/std.o \
	core/utils/md5.o \
	core/tjs2/tjsString.o
 
MODULE_DIRS += \
	engines/kirikiri2
 
# This module can be built as a plugin
ifeq ($(ENABLE_KIRIKIRI2), DYNAMIC_PLUGIN)
PLUGIN := 1
endif
 
# Include common rules 
include $(srcdir)/rules.mk

# Detection objects
DETECT_OBJS += $(MODULE)/detection.o