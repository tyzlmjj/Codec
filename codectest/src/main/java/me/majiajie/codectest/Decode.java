package me.majiajie.codectest;

public class Decode {

    public static String Base64(String string)
    {
        return NativeMethod.Base64Decode(string,null,'=',-1);
    }


}
