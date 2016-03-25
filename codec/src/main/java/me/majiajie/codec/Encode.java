package me.majiajie.codec;


public class Encode
{
    public static String Base64(String string)
    {
        return  NativeMethod.Base64Encode
                (string,Const_Base64.DEFAULT_ALPHABET,Const_Base64.FILL_CHAR,Const_Base64.MAX_CHAR_PRE_LINE);
    }

    public static CustomBase64_Encode Custom_Base64(String string)
    {
        return new CustomBase64_Encode(string);
    }
}
