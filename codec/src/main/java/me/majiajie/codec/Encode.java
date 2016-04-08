package me.majiajie.codec;


import java.nio.charset.Charset;

import me.majiajie.codec.charset.CodecCharsets;

public class Encode
{
    /**
     * 标准Base64加密
     * @param string  需要加密的字符串
     * @return 加密后的字符串
     */
    public static String Base64(String string)
    {
        return  new String(Base64_byte(string));
    }

    /**
     * 标准Base64加密
     * @param string  需要加密的字符串
     * @param charset 字符编码，建议使用{@link CodecCharsets CodecCharsets}
     * @return 加密后的字符串
     */
    public static String Base64(String string,Charset charset)
    {
        return  new String(Base64_byte(string),charset);
    }

    /**
     * 标准Base64加密
     * @param string    需要加密的字符串
     * @return 加密后的byte数组
     */
    public static byte[] Base64_byte(String string)
    {
        return  NativeMethod.Base64Encode
                (string,Const_Base64.DEFAULT_ALPHABET,Const_Base64.FILL_CHAR,Const_Base64.MAX_CHAR_PRE_LINE);
    }

    /**
     * 自定义Base64加密
     * @param string    需要加密的字符串
     * @return 加密后的字符串
     */
    public static CustomBase64_Encode Custom_Base64(String string)
    {
        return new CustomBase64_Encode(string);
    }

    /**
     * MD5加密，默认32位、小写
     * @param string    需要加密的字符串
     * @return 加密后的字符串
     */
    public static String MD5(String string)
    {
        return  NativeMethod.Md5Encode(string,false,true);
    }

    /**
     * MD5加密，32位、大写
     * @param string    需要加密的字符串
     * @return 加密后的字符串
     */
    public static String MD5_UpperCase(String string)
    {
        return  NativeMethod.Md5Encode(string, false, false);
    }

    /**
     * MD5加密，16位、小写
     * @param string    需要加密的字符串
     * @return 加密后的字符串
     */
    public static String MD5_16(String string)
    {
        return  NativeMethod.Md5Encode(string, true, true);
    }

    /**
     * MD5加密，16位、大写
     * @param string    需要加密的字符串
     * @return 加密后的字符串
     */
    public static String MD5_16_UpperCase(String string)
    {
        return  NativeMethod.Md5Encode(string, true, false);
    }
}
