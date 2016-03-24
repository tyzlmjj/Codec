package me.majiajie.codec;

public class Decode {

    public static String Base64(String string)
    {
        return NativeMethod.Base64Decode(string,null,'=',-1);
    }

    public static CustomBase64_Decode Custom_Base64(String string)
    {
        return new CustomBase64_Decode(string);
    }

}
