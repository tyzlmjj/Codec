package me.majiajie.codec;

import me.majiajie.codec.exception.DecodeException;

public class Decode {

    /**
     * 标准Base64解码
     * @param string    需要解码的字符串
     * @return Base64解码后的字符串，如果解码失败，返回null
     */
    public static String Base64(String string)
    {
        try{
            return NativeMethod.Base64Decode
                    (string,Const_Base64.DEFAULT_ALPHABET,Const_Base64.FILL_CHAR);
        }
        catch (Throwable throwable)
        {
           return null;
        }
    }

    public static CustomBase64_Decode Custom_Base64(String string)
    {
        return new CustomBase64_Decode(string);
    }

}
