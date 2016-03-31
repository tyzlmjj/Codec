package me.majiajie.codec;


public class Decode {

    /**
     * 标准Base64解码<p>
     * <strong>注意：</strong>如果传入非Base64加密字符串会使应用崩溃，这个错误是可以人为避免的，<p>
     * 所以为了算法的速度，并未检查字符串的正确性。
     * @param string    需要解码的字符串
     * @return Base64解码后的字符串
     */
    public static String Base64(String string)
    {
        return NativeMethod.Base64Decode
                    (string,Const_Base64.DEFAULT_ALPHABET,Const_Base64.FILL_CHAR);
    }

    /**
     * 自定义Base64解码
     * @param string 需要解码的字符串
     * @return Base64解码后的字符串
     */
    public static CustomBase64_Decode Custom_Base64(String string)
    {
        return new CustomBase64_Decode(string);
    }

}
