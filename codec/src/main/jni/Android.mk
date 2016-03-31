LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := Codec
LOCAL_SRC_FILES := Codec.cpp

include $(BUILD_SHARED_LIBRARY)