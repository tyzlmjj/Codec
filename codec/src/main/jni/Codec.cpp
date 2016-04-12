#include <jni.h>
#include "Base64.h"
#include "MD5.h"
#include "me_majiajie_codec_NativeMethod.h"

JNIEXPORT jbyteArray JNICALL Java_me_majiajie_codec_NativeMethod_Base64Decode
        (JNIEnv * env, jclass jclass1, jstring oldString, jcharArray alphabet, jchar fillChar)
{
    jchar decode_alphabet[64];
    env->GetCharArrayRegion(alphabet , 0 , 64 , decode_alphabet);

    const char *old = env->GetStringUTFChars(oldString, 0);

    int lenght;
    for(lenght=0; old[lenght] != '\0';lenght++);

    signed char *decode_String = base64_decode(old,decode_alphabet,fillChar,lenght);

    env->ReleaseStringUTFChars(oldString,old);

    jbyteArray byteArray = env->NewByteArray(lenght/4*3);
    env->SetByteArrayRegion(byteArray,0,lenght/4*3,decode_String);
    return byteArray;
}

JNIEXPORT jbyteArray JNICALL Java_me_majiajie_codec_NativeMethod_Base64Encode
        (JNIEnv *env, jclass jclass1, jstring oldString, jcharArray alphabet, jchar fillChar, jint maxCharPreLine){

    jchar encode_alphabet[64];
    env->GetCharArrayRegion(alphabet , 0 , 64 ,encode_alphabet);

    const char *old = env->GetStringUTFChars(oldString, 0);

    int lenght;
    for(lenght=0;old[lenght] != '\0';lenght++);

    signed char *encode_string;
    if(maxCharPreLine >0)
    {
        encode_string =base64_encode(old,encode_alphabet,fillChar,maxCharPreLine,lenght);
    }
    else
    {
        encode_string = base64_encode(old,encode_alphabet,fillChar,lenght);
    }
    env->ReleaseStringUTFChars(oldString,old);

    int l = lenght%3==0? lenght/3*4: lenght/3*4+4;
    jbyteArray byteArray = env->NewByteArray(l);
    env->SetByteArrayRegion(byteArray,0,l,encode_string);

    return byteArray;
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
            str[i] = md5_str[8+i];
        }
        str[16] = '\0';
        env->ReleaseStringUTFChars(old_string,old);
        return env->NewStringUTF(str);
    }
    env->ReleaseStringUTFChars(old_string,old);

    return env->NewStringUTF(md5_str);
}


