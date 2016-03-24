LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := Base64
LOCAL_SRC_FILES := Base64.cpp


include $(BUILD_SHARED_LIBRARY)

