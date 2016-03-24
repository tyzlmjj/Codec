#include <jni.h>
#include <stdio.h>
#include "me_majiajie_codectest_NativeMethod.h"

////导入日志头文件
//#include <android/log.h>
////修改日志tag中的值
//#define LOG_TAG "asd"
////日志显示的等级
//#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

/*
	Base64加解密
*/

const char c_default_fill = '=';

const char *c_alphabet_normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";





/*
const int c_alphabet_normal[64] =
{
//	A~Z
0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,
//	a~z
0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,
//	0~9
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,
//	+ /
0x2B,0x2F
};
*/

void base64_encode(char *encode_String,const char *string,int lenght)
{
    int n = 0;
    int i;
    for(i = 0; i < lenght ; i+=3)
    {

        if(lenght - i < 3)
        {
            int a,b,c;
            if(lenght%3 == 2)
            {
                a = ((int)string[lenght-2]) >> 2;
                b = ((((int)string[lenght-2]) & 0x03) << 4) | (((int)string[lenght-1]) >> 4);
                c = ((((int)string[i+1]) & 0x0F) << 2);

                encode_String[n++] = c_alphabet_normal[a];
                encode_String[n++] = c_alphabet_normal[b];
                encode_String[n++] = c_alphabet_normal[c];
                encode_String[n++] = c_default_fill;
            }
            else
            {
                a = ((int)string[lenght-1]) >> 2;
                b = ((((int)string[lenght-1]) & 0x03) << 4);

                encode_String[n++] = c_alphabet_normal[a];
                encode_String[n++] = c_alphabet_normal[b];
                encode_String[n++] = c_default_fill;
                encode_String[n++] = c_default_fill;
            }
        }
        else
        {
            int temp[4];
            temp[0] = ((int)string[i]) >> 2 ;
            temp[1] = ((((int)string[i]) & 0x03) << 4) | (((int)string[i+1]) >> 4);
            temp[2] = ((((int)string[i+1]) & 0x0F) << 2) | (((int)string[i+2]) >> 6);
            temp[3] = ((int)string[i+2]) & 0x3F;

            encode_String[n++] = c_alphabet_normal[temp[0]];
            encode_String[n++] = c_alphabet_normal[temp[1]];
            encode_String[n++] = c_alphabet_normal[temp[2]];
            encode_String[n++] = c_alphabet_normal[temp[3]];
        }
    }

    encode_String[n] = '\0';
}


int decode_Char(int c)
{
    int i;
    for(i = 0; i < 64; i++)
    {
        if(c == c_alphabet_normal[i])
        {
            return i;
        }
    }
    return c_default_fill;
}


void base64_decode(char *decode_String,const char *string,int lenght)
{
    int i;
    int n = 0;
    for(i = 0; i < lenght ;i+=4)
    {
        if(lenght -i >= 4)
        {
            int a,b,c,d;
            a = decode_Char(string[i] != '\n'? string[i] : string[++i]);
            b = decode_Char(string[i+1] != '\n'? string[i+1] : string[++i+1]);
            c = decode_Char(string[i+2] != '\n'? string[i+2] : string[++i+2]);
            d = decode_Char(string[i+3] != '\n'? string[i+3] : string[++i+3]);

            if(c == c_default_fill)
            {
                decode_String[n++] = (a << 2) | (b >> 4);
            }
            else if(d == c_default_fill)
            {
                decode_String[n++] = (a << 2) | (b >> 4);
                decode_String[n++] = ((b & 0xF) << 4) | (c >> 2);
            }
            else
            {
                decode_String[n++] = (a << 2) | (b >> 4);
                decode_String[n++] = ((b & 0xF) << 4) | (c >> 2);
                decode_String[n++] = ((c & 0x3) << 6) | d;
            }
        }
    }

    decode_String[n] = '\0';
}

JNIEXPORT jstring JNICALL Java_me_majiajie_codec_NativeMethod_Base64Decode
        (JNIEnv * env, jclass jclass1, jstring oldString, jcharArray alphabet, jchar fillChar, jint maxCharPreLine)
{
    const char *old = env->GetStringUTFChars(oldString, 0);

    int lenght;
    for(lenght=0;old[lenght] != '\0';lenght++);
    char decode_String[lenght/4*3+1];

    base64_decode(decode_String,old,lenght);

    env->ReleaseStringUTFChars(oldString,old);
    return env->NewStringUTF(decode_String);
}

JNIEXPORT jstring JNICALL Java_me_majiajie_codec_NativeMethod_Base64Encode
        (JNIEnv *env, jclass jclass1,jstring oldString, jcharArray alphabet, jchar fillChar, jint maxCharPreLine)
{
    jchar * encode_alphabet = env->GetCharArrayElements(alphabet,NULL);



    const char *old = env->GetStringUTFChars(oldString, 0);

    int lenght;
    for(lenght=0;old[lenght] != '\0';lenght++);
    int encode_lenght = lenght%3==0? lenght/3*4+1: lenght/3*4+4+1;
    char encode_String[encode_lenght];
    base64_encode(encode_String,old,lenght);

    env->ReleaseStringUTFChars(oldString,old);

    return env->NewStringUTF("aasdasdasdasd");

}

