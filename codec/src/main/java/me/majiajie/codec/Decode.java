package me.majiajie.codec;

import me.majiajie.codec.exception.DecodeException;

public class Decode {

    public static String Base64(String string) throws DecodeException
    {
        try{
            return NativeMethod.Base64Decode
                    (string,Const_Base64.DEFAULT_ALPHABET,Const_Base64.FILL_CHAR);
        }
        catch (Throwable throwable)
        {
            DecodeException exception = new DecodeException();
            exception.initCause(throwable);
            throw exception;
        }
    }

    public static CustomBase64_Decode Custom_Base64(String string)
    {
        return new CustomBase64_Decode(string);
    }

}
