LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION := .cpp .cc

### Mod Filename
ifeq ($(TARGET_ARCH_ABI), armeabi-v7a)
	LOCAL_MODULE := GHap
else
	LOCAL_MODULE := GHap64
endif

### Compile Args
LOCAL_CFLAGS    += -O3 -mfloat-abi=softfp -mfpu=neon -DNDEBUG -std=c++17
LOCAL_CXXFLAGS  += -O3 -mfloat-abi=softfp -mfpu=neon -DNDEBUG -std=c++17

### Source Files
LOCAL_SRC_FILES := main.cpp mod/logger.cpp

### Libraries
LOCAL_LDLIBS += -llog

include $(BUILD_SHARED_LIBRARY)