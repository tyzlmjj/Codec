package me.majiajie.codec;


import android.support.annotation.NonNull;

import java.nio.charset.Charset;

import me.majiajie.codec.charset.CodecCharsets;

public class Decode {

    /**
     * 标准Base64解码<p>
     * @param string    需要解码的字符串
     * @return Base64解码后的字符串
     */
    public static String Base64(@NonNull String string)
    {
        return new String(Base64_byte(string));
    }

    /**
     * 标准Base64解码
     * @param string    需要解码的字符串
     * @param charset   字符编码，建议使用{@link CodecCharsets CodecCharsets}
     * @return Base64解码后的字符串
     */
    public static String Base64(@NonNull String string,@NonNull Charset charset)
    {
        return new String(Base64_byte(string),charset);
    }

    /**
     * 标准Base64解码<p>
     * @param string    需要解码的字符串
     * @return Base64解码后的byte数组
     */
    public static byte[] Base64_byte(@NonNull String string)
    {
        return NativeMethod.Base64Decode
                (string, Const_Base64.DEFAULT_ALPHABET, Const_Base64.FILL_CHAR);
    }

    /**
     * 自定义Base64解码
     * @param string 需要解码的字符串
     * @return Base64解码后的字符串
     */
    public static CustomBase64_Decode Custom_Base64(@NonNull String string)
    {
        return new CustomBase64_Decode(string);
    }

}
