package me.majiajie.codec;


public class Encode
{
    /**
     * 标准Base64加密
     */
    public static String Base64(String string)
    {
        return  NativeMethod.Base64Encode
                (string,Const_Base64.DEFAULT_ALPHABET,Const_Base64.FILL_CHAR,Const_Base64.MAX_CHAR_PRE_LINE);
    }

    /**
     * 自定义Base64加密
     */
    public static CustomBase64_Encode Custom_Base64(String string)
    {
        return new CustomBase64_Encode(string);
    }

    /**
     * MD5加密，默认32位、小写
     */
    public static String MD5(String string)
    {
        return  NativeMethod.Md5Encode(string,false,true);
    }

    /**
     * MD5加密，32位、大写
     */
    public static String MD5_UpperCase(String string)
    {
        return  NativeMethod.Md5Encode(string, false, false);
    }

    /**
     * MD5加密，16位、小写
     */
    public static String MD5_16(String string)
    {
        return  NativeMethod.Md5Encode(string, true, true);
    }

    /**
     * MD5加密，16位、大写
     */
    public static String MD5_16_UpperCase(String string)
    {
        return  NativeMethod.Md5Encode(string, true, false);
    }
}
