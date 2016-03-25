package me.majiajie.codec;


public class CustomBase64_Encode extends Custom
{
    protected int mMaxCharLine;

    private String mString;

    private char[] mAlphabet;

    private char mFillChar;

    public CustomBase64_Encode(String string)
    {
        mString = string;
        mFillChar = Const_Base64.FILL_CHAR;
        mAlphabet = Const_Base64.DEFAULT_ALPHABET;
        mMaxCharLine = Const_Base64.MAX_CHAR_PRE_LINE;
    }

    /**
     * 设置字母表。<br/>
     * @param alphabet 64位的字符数组
     * @return
     */
    public CustomBase64_Encode setAlphabet(char[] alphabet)
    {
        mAlphabet = alphabet;
        return this;
    }

    /**
     * 设置末尾填充的字符，默认是‘=’。
     * 填充字符是在编码字符位数不足时使用。<br/>
     * <strong>注意：</strong>解码和编码需要设置相同的
     */
    public CustomBase64_Encode setFillChar(char fillChar) {
        mFillChar = fillChar;
        return this;
    }

    /**
     * 设置每行最大的字符数。即加入换行符'\n'。<br/>
     * 这里我写的算法默认是不换行的，但按BASE64标准的话是需要每76个字符加一个换行符的<br/>
     * 解码时会自动忽略'\n'
     */
    public CustomBase64_Encode setMaxCharLine(int n)
    {
        mMaxCharLine = n;
        return this;
    }

    @Override
    public String doit()
    {
        return NativeMethod.Base64Encode(mString, mAlphabet, mFillChar, mMaxCharLine);
    }
}
