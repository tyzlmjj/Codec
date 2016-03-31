package me.majiajie.codec;

public class CustomBase64_Decode extends Custom
{
    private String mString;

    private char[] mAlphabet;

    private char mFillChar;

    public CustomBase64_Decode(String string)
    {
        mString = string;
        mFillChar = Const_Base64.FILL_CHAR;
        mAlphabet = Const_Base64.DEFAULT_ALPHABET;
    }

    /**
     * 设置64位字符映射表，对应ASCII。
     * <strong>注意：</strong>解码和编码需要设置相同的<p>
     * @param alphabet 64位的字符数组
     * @return 自定义构建类
     */
    public CustomBase64_Decode setAlphabet(char[] alphabet)
    {
        mAlphabet = alphabet;
        return this;
    }

    /**
     * 设置末尾填充的字符，默认是‘=’。<p>
     * 填充字符是在编码字符位数不足时使用。<p>
     * <strong>注意：</strong>这个字符必须不能为64位映射表中的字符，否则可能出错，解码和编码需要设置相同的
     * @param fillChar 填充字符
     * @return 自定义构建类
     */
    public CustomBase64_Decode setFillChar(char fillChar) {
        mFillChar = fillChar;
        return this;
    }

    @Override
    public String doit()
    {
        return NativeMethod.Base64Decode(mString, mAlphabet, mFillChar);
    }
}
