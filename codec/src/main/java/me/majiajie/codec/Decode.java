package me.majiajie.codec;

public class Decode {

    public static String Base64(String string)
    {
        return NativeMethod.Base64Decode
                (string,Const_Base64.DEFAULT_ALPHABET,Const_Base64.FILL_CHAR);
    }

    public static CustomBase64_Decode Custom_Base64(String string)
    {
        return new CustomBase64_Decode(string);
    }

}
