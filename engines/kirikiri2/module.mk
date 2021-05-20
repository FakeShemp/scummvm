MODULE := engines/kirikiri2
 
MODULE_OBJS := \
	metaengine.o \
	kirikiri2.o \
	core/utils/md5.o
 
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