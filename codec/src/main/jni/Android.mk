LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := Codec
LOCAL_SRC_FILES := Base64.cpp

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)