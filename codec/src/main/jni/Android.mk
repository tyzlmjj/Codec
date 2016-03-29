LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPP_FEATURES := exceptions rtti

LOCAL_MODULE := Codec
LOCAL_SRC_FILES := Codec.cpp

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)