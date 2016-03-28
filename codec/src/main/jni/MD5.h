#include <stdio.h>
#include <jni.h>


#ifndef CODEC_MD5_H
#define CODEC_MD5_H


/**
* MD5加密算法
* unsigned int 0～4294967295
*/

//	循环移位
#define shift(x, n) (((x) << (n)) | ((x) >> (32-(n))))

//	非线性函数
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define FF(a, b, c, d, Mj, s, ti) 	(a = b + (shift((a + F(b, c, d) + Mj + ti),s)))
#define GG(a, b, c, d, Mj, s, ti)  	(a = b + (shift((a + G(b, c, d) + Mj + ti),s)))
#define HH(a, b, c, d, Mj, s, ti)  	(a = b + (shift((a + H(b, c, d) + Mj + ti),s)))
#define II(a, b, c, d, Mj, s, ti)  	(a = b + (shift((a + I(b, c, d) + Mj + ti),s)))

//	链接变量
#define A 0x67452301
#define B 0xefcdab89
#define C 0x98badcfe
#define D 0x10325476

unsigned int temp_a;
unsigned int temp_b;
unsigned int temp_c;
unsigned int temp_d;

//常量ti unsigned int(abs(sin(i+1))*(2pow32))
const unsigned int k[]={
        0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,
        0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,
        0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,
        0xa679438e,0x49b40821,0xf61e2562,0xc040b340,0x265e5a51,
        0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
        0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,
        0xfcefa3f8,0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,
        0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,
        0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,
        0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,0xf4292244,
        0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,
        0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,
        0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};

//向左位移数
const unsigned int s[]={7,12,17,22,7,12,17,22,7,12,17,22,7,
                        12,17,22,5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20,
                        4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,6,10,
                        15,21,6,10,15,21,6,10,15,21,6,10,15,21};

//16进制
#define STR16 "0123456789ABCDEF"
#define STR16_LOW "0123456789abcdef"



/**
* First : 填充字符
*/
void fill(int*  new_str,int fill_lenght,unsigned int lenght)
{
    new_str[lenght] = 0x80;
    int i;
    for(i = 1 ; i < fill_lenght - 8 ; i++)
    {
        new_str[lenght+i] = 0;
    }

    int n1 = 0,n2 = 0,n3 = 0,n4 = 0,n5 = 0,n6 = 0,n7 = 0,n8 = 0;

    unsigned int  size = lenght*8;

    n1 = size & 0xFF;
    n2 = (size >> 8) & 0xFF;
    n3 = (size >> 16) & 0xFF;
    n4 = (size >> 24)  & 0xFF;

//	n5 = (size  >> 32) & 0xFF;
//	n6 = (size  >> 40) & 0xFF;
//	n7 = (size  >> 48) & 0xFF;
//	n8 = (size  >> 56) & 0xFF;

    unsigned int j = lenght + fill_lenght-8;
    new_str[j++] = n1;
    new_str[j++] = n2;
    new_str[j++] = n3;
    new_str[j++] = n4;
    new_str[j++] = n5;
    new_str[j++] = n6;
    new_str[j++] = n7;
    new_str[j++] = n8;

}

/**
* 计算字符串长度
*/
unsigned int str_lenght(const char*  str)
{
    unsigned int lenght;
    for(lenght=0;str[lenght] != '\0';lenght++);
    return lenght;
}

/**
* 将jchar*变成int*
*/
void str_to_int(int *new_str,const char* old_str)
{
    int i;
    for(i = 0; old_str[i] != '\0'; i++)
    {
        new_str[i] = old_str[i] & 0xFF;
    }
}

/**
* 分组
*/
int* group(int *str,int start)
{
    int *temp = new int[16];
    int i;
    for(i = 0;i < 16; i++)
    {
        temp[i] = str[start+i*4+3]<<24 | str[start+i*4+2] <<16 |
                  str[start+i*4+1] <<8 | str[start+i*4] ;
    }

    return temp;
}

/**
* 计算循环
*/
void mainLoop(int *M)
{
    int a = temp_a;
    int b = temp_b;
    int c = temp_c;
    int d = temp_d;
    int i,g;
    for(i = 0;i < 64;i++)
    {
        if(i < 16)
        {
            g=i;
            FF(a,b,c,d,M[g],s[i],k[i]);
        }
        else if(i < 32)
        {
            g=(5*i+1)%16;
            GG(a,b,c,d,M[g],s[i],k[i]);
        }
        else if(i < 48)
        {
            g=(3*i+5)%16;
            HH(a,b,c,d,M[g],s[i],k[i]);
        }
        else
        {
            g=(7*i)%16;
            II(a,b,c,d,M[g],s[i],k[i]);
        }
        int tmp = d;
        d = c;
        c = b;
        b = a;
        a = tmp;
    }
    temp_a += a;
    temp_b += b;
    temp_c += c;
    temp_d += d;
}

/**
* 最后逆序处理
*/
char* changeHex(int a[] ,const char *temp_str16)
{
    char* str = new char[32];
    int i,j;
    for(i = 0;i < 4 ;i++)
    {
        for(j = 0; j < 4 ;j++)
        {
            int n = (a[i] >> (j*2*4));

            str[i*8+j*2] = temp_str16[(n >> 4) & 0xF];
            str[i*8+j*2+1] = temp_str16[n & 0xF];
        }
    }
    return str;
}

char* md5_encode(const char *old_string, jboolean isLow)
{

    unsigned int lenght = str_lenght(old_string);
    int r = lenght % 64;
    int fill_lenght = ( r < 56 ? 64 : 128)-r;
    int new_str[lenght + fill_lenght];
    str_to_int(new_str,old_string);

    fill(new_str,fill_lenght,lenght);
    int n = (lenght + fill_lenght) / 64;
    int *M[n];

    int i;
    for(i = 0; i < n; i++){
        M[i] = group(new_str,i*64);
    }

    temp_a = A;
    temp_b = B;
    temp_c = C;
    temp_d = D;
    for(i = 0 ;i < n;i++)
    {
        mainLoop(M[i]);
    }
    int tmp[4] = {temp_a,temp_b,temp_c,temp_d};

    return changeHex(tmp,isLow?STR16_LOW:STR16);
}


#endif //CODEC_MD5_H
