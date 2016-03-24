package me.majiajie.codectest;


class NativeMethod
{
    static {
        System.loadLibrary("Base64");
    }

    protected static native String Base64Decode(String oldString,char[] alphabet,char fillChar,int maxCharPreLine);

    protected static native String Base64Encode(String oldString,char[] alphabet,char fillChar,int maxCharPreLine);

}
