package me.majiajie.codec;


public class Encode
{
    public static String Base64(String string)
    {
        return  NativeMethod.Base64Encode(string,null,'=',-1);
    }

    public static CustomBase64_Encode Custom_Base64(String string)
    {
        return new CustomBase64_Encode(string);
    }
}
