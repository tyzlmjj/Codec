#include <jni.h>
#include <stdio.h>
#include "Base64.h"
#include "me_majiajie_codec_NativeMethod.h"

//导入日志头文件
#include <android/log.h>
//修改日志tag中的值
#define LOG_TAG "asd"
//日志显示的等级
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


JNIEXPORT jstring JNICALL Java_me_majiajie_codec_NativeMethod_Base64Decode
        (JNIEnv * env, jclass jclass1, jstring oldString, jcharArray alphabet, jchar fillChar)
{
    jchar decode_alphabet[64];
    env->GetCharArrayRegion(alphabet , 0 , 64 , decode_alphabet);

    const char *old = env->GetStringUTFChars(oldString, 0);

    char *decode_String = base64_decode(old,decode_alphabet,fillChar);

    env->ReleaseStringUTFChars(oldString,old);
    env->ReleaseCharArrayElements(alphabet,decode_alphabet,0);

    return env->NewStringUTF(decode_String);
}


JNIEXPORT jstring JNICALL Java_me_majiajie_codec_NativeMethod_Base64Encode
        (JNIEnv *env, jclass jclass1, jstring oldString, jcharArray alphabet, jchar fillChar, jint maxCharPreLine){

    jchar encode_alphabet[64];
    env->GetCharArrayRegion(alphabet , 0 , 64 ,encode_alphabet);

    const char *old = env->GetStringUTFChars(oldString, 0);

    char *encode_string;
    if(maxCharPreLine >0)
    {
        encode_string =base64_encode(old,encode_alphabet,fillChar,maxCharPreLine);
        LOGI("maxCharPreLine: %d",maxCharPreLine);
        LOGI("encode_string[0]: %c",encode_string[0]);
    }
    else
    {
        encode_string = base64_encode(old,encode_alphabet,fillChar);
    }

    env->ReleaseStringUTFChars(oldString,old);
    env->ReleaseCharArrayElements(alphabet,encode_alphabet,0);

    return env->NewStringUTF(encode_string);
}


