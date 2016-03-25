package me.majiajie.codec;


class NativeMethod
{
    static {
        System.loadLibrary("Codec");
    }

    public static native String Base64Decode(String oldString,char[] alphabet,char fillChar);

    public static native String Base64Encode(String oldString,char[] alphabet,char fillChar,int maxCharPreLine);

}
