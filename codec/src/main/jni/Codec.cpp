#include <jni.h>
#include "Base64.h"
#include "MD5.h"
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
    }
    else
    {
        encode_string = base64_encode(old,encode_alphabet,fillChar);
    }

    env->ReleaseStringUTFChars(oldString,old);

    return env->NewStringUTF(encode_string);
}

JNIEXPORT jstring JNICALL Java_me_majiajie_codec_NativeMethod_Md5Encode
        (JNIEnv *env, jclass jclass1, jstring old_string, jboolean isSixteen, jboolean isLow)
{
    const char * old =env->GetStringUTFChars(old_string,0);
    char * md5_str = md5_encode(old,isLow);

    if(isSixteen)
    {
        char str[16+1];
        int i;
        for(i = 0;i < 16;i++){
            str[i] = md5_str[16+i];
        }
        str[16] = '\0';
        env->ReleaseStringUTFChars(old_string,old);
        return env->NewStringUTF(str);
    }
    env->ReleaseStringUTFChars(old_string,old);

    return env->NewStringUTF(md5_str);
}


