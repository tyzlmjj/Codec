package me.majiajie.codec;


import android.support.annotation.NonNull;

import java.nio.charset.Charset;

import me.majiajie.codec.charset.CodecCharsets;

public class CustomBase64_Encode extends Custom
{
    private int mMaxCharLine;

    private String mString;

    private char[] mAlphabet;

    private char mFillChar;

    private Charset mCharset;

    public CustomBase64_Encode(@NonNull String string)
    {
        mString = string;
        mFillChar = Const_Base64.FILL_CHAR;
        mAlphabet = Const_Base64.DEFAULT_ALPHABET;
        mMaxCharLine = Const_Base64.MAX_CHAR_PRE_LINE;
    }

    /**
     * 设置64位字符映射表，对应ASCII。
     * <strong>注意：</strong>解码和编码需要设置相同的
     * @param alphabet 64位的字符数组
     * @return 自定义构建类
     */
    public CustomBase64_Encode setAlphabet(@NonNull char[] alphabet)
    {
        mAlphabet = alphabet;
        return this;
    }

    /**
     * 设置末尾填充的字符，默认是‘=’。<p>
     * 填充字符是在编码字符位数不足时使用。<p>
     * <strong>注意：</strong>这个字符必须不能为64位映射表中的字符，否则可能出错，并且解码和编码需要设置相同的
     * @param fillChar 填充字符
     * @return 自定义构建类
     */
    public CustomBase64_Encode setFillChar(@NonNull char fillChar) {
        mFillChar = fillChar;
        return this;
    }

    /**
     * 设置每行最大的字符数。即加入换行符'\n'。<p>
     * 这里我写的算法默认是不换行的，但按BASE64标准的话是需要每76个字符加一个换行符的<p>
     * 解码时会自动忽略'\n'
     * @param n 每行最大的字符数
     * @return 自定义构建类
     */
    public CustomBase64_Encode setMaxCharLine(@NonNull int n)
    {
        mMaxCharLine = n;
        return this;
    }

    /**
     * 设置字符编码
     * @param charset 建议使用{@link CodecCharsets CodecCharsets}
     * @return  自定义构建类
     */
    public CustomBase64_Encode setCharset(@NonNull Charset charset) {
        mCharset = charset;
        return this;
    }

    @Override
    public String doit()
    {
        if(mCharset != null)
        {
            return new String(doit_byte(),mCharset);
        }
        else
        {
            return new String(doit_byte());
        }
    }

    @Override
    public byte[] doit_byte() {
        return NativeMethod.Base64Encode(mString, mAlphabet, mFillChar, mMaxCharLine);
    }
}
