
#ifndef CODEC_BASE64_H
#define CODEC_BASE64_H


//标准的填充字符
#define DEFAULT_FILL '='

//标准的映射表
const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

//char* alphabet;
char  temp_fill_char;

/**
 * Base64加密算法，无换行符
 */
char* base64_encode(const char *old_string,jchar *alphabet, char fillChar)
{
    temp_fill_char = fillChar;

    int lenght;
    for(lenght=0;old_string[lenght] != '\0';lenght++);
    int encode_lenght = lenght%3==0? lenght/3*4+1: lenght/3*4+4+1;
    char* encode_string = new char[encode_lenght];

    int n = 0;
    int i;
    for(i = 0; i < lenght ; i+=3)
    {
        if(lenght - i < 3)
        {
            int a,b,c;
            if(lenght%3 == 2)
            {
                a = ((int) old_string[lenght-2]) >> 2;
                b = ((((int) old_string[lenght-2]) & 0x03) << 4) | (((int) old_string[lenght-1]) >> 4);
                c = ((((int) old_string[i+1]) & 0x0F) << 2);

                encode_string[n++] = alphabet[a];
                encode_string[n++] = alphabet[b];
                encode_string[n++] = alphabet[c];
                encode_string[n++] = temp_fill_char;
            }
            else
            {
                a = ((int) old_string[lenght-1]) >> 2;
                b = ((((int) old_string[lenght-1]) & 0x03) << 4);

                encode_string[n++] = alphabet[a];
                encode_string[n++] = alphabet[b];
                encode_string[n++] = temp_fill_char;
                encode_string[n++] = temp_fill_char;
            }
        }
        else
        {
            int temp[4];
            temp[0] = ((int) old_string[i]) >> 2 ;
            temp[1] = ((((int) old_string[i]) & 0x03) << 4) | (((int) old_string[i+1]) >> 4);
            temp[2] = ((((int) old_string[i+1]) & 0x0F) << 2) | (((int) old_string[i+2]) >> 6);
            temp[3] = ((int) old_string[i+2]) & 0x3F;

            encode_string[n++] = alphabet[temp[0]];
            encode_string[n++] = alphabet[temp[1]];
            encode_string[n++] = alphabet[temp[2]];
            encode_string[n++] = alphabet[temp[3]];
        }
    }

    encode_string[n] = '\0';

    return encode_string;
}

/**
 * Base64加密算法，有换行符
 */
char* base64_encode(const char *old_string,jchar *alphabet, char fillChar,int maxCharPreLine)
{
    temp_fill_char = fillChar;

    int lenght;
    for(lenght=0;old_string[lenght] != '\0';lenght++);
    int encode_lenght = lenght%3==0? lenght/3*4+1: lenght/3*4+4+1;
    encode_lenght += encode_lenght%maxCharPreLine;
    char* encode_string = new char[encode_lenght];

    int n = 0;
    int i;
    for(i = 0; i < lenght ; i+=3)
    {
        if(lenght - i < 3)
        {
            int a,b,c;
            if(lenght%3 == 2)
            {
                a = ((int) old_string[lenght-2]) >> 2;
                b = ((((int) old_string[lenght-2]) & 0x03) << 4) | (((int) old_string[lenght-1]) >> 4);
                c = ((((int) old_string[i+1]) & 0x0F) << 2);

                if(n!=0 && (n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
                encode_string[n++] = alphabet[a];
                if((n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
                encode_string[n++] = alphabet[b];
                if((n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
                encode_string[n++] = alphabet[c];
                if((n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
                encode_string[n++] = temp_fill_char;
            }
            else
            {
                a = ((int) old_string[lenght-1]) >> 2;
                b = ((((int) old_string[lenght-1]) & 0x03) << 4);

                if(n!=0 && (n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
                encode_string[n++] = alphabet[a];
                if((n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
                encode_string[n++] = alphabet[b];
                if((n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
                encode_string[n++] = temp_fill_char;
                if((n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
                encode_string[n++] = temp_fill_char;
            }
        }
        else
        {
            int temp[4];
            temp[0] = ((int) old_string[i]) >> 2 ;
            temp[1] = ((((int) old_string[i]) & 0x03) << 4) | (((int) old_string[i+1]) >> 4);
            temp[2] = ((((int) old_string[i+1]) & 0x0F) << 2) | (((int) old_string[i+2]) >> 6);
            temp[3] = ((int) old_string[i+2]) & 0x3F;

            if(n!=0 && (n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
            encode_string[n++] = alphabet[temp[0]];
            if((n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
            encode_string[n++] = alphabet[temp[1]];
            if((n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
            encode_string[n++] = alphabet[temp[2]];
            if((n+1)%(maxCharPreLine+1) == 0){encode_string[n++] = '\n';}
            encode_string[n++] = alphabet[temp[3]];
        }
    }
    encode_string[n] = '\0';

    return encode_string;
}


int decode_Char(int c,jchar * alphabet )
{
    int i;
    for(i = 0; i < 64; i++)
    {
        if(c == alphabet[i])
        {
            return i;
        }
    }
    return temp_fill_char;
}

/**
 * Base64解码
 */
char* base64_decode(const char *old_string,jchar *alphabet, char fillChar)
{
    temp_fill_char = fillChar;

    int lenght;
    for(lenght=0; old_string[lenght] != '\0';lenght++);
    char *decode_String = new char[lenght/4*3+1];

    int i;
    int n = 0;
    for(i = 0; i < lenght ;i+=4)
    {
        if(lenght -i >= 4)
        {
            int a,b,c,d;
            a = decode_Char(old_string[i] != '\n'? old_string[i] : old_string[++i],alphabet);
            b = decode_Char(old_string[i+1] != '\n'? old_string[i+1] : old_string[++i+1],alphabet);
            c = decode_Char(old_string[i+2] != '\n'? old_string[i+2] : old_string[++i+2],alphabet);
            d = decode_Char(old_string[i+3] != '\n'? old_string[i+3] : old_string[++i+3],alphabet);

            if(c == temp_fill_char)
            {
                decode_String[n++] = (a << 2) | (b >> 4);
            }
            else if(d == temp_fill_char)
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

    return decode_String;
}





#endif //CODEC_BASE64_H
