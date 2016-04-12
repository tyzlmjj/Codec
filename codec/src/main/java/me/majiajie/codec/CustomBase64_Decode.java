package me.majiajie.codec;

import android.support.annotation.NonNull;

import java.nio.charset.Charset;

import me.majiajie.codec.charset.CodecCharsets;

public class CustomBase64_Decode extends Custom
{
    private String mString;

    private char[] mAlphabet;

    private char mFillChar;

    private Charset mCharset;

    public CustomBase64_Decode(@NonNull String string)
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
    public CustomBase64_Decode setAlphabet(@NonNull char[] alphabet)
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
    public CustomBase64_Decode setFillChar(@NonNull char fillChar) {
        mFillChar = fillChar;
        return this;
    }

    /**
     * 设置字符编码
     * @param charset 字符编码，建议使用{@link CodecCharsets CodecCharsets}
     * @return  自定义构建类
     */
    public CustomBase64_Decode setCharset(@NonNull Charset charset) {
        mCharset = charset;
        return this;
    }

    @Override
    public String doit()
    {
        if(mCharset!=null){
            return new String(doit_byte(),mCharset);
        }
        else
        {
            return new String(doit_byte());
        }
    }

    @Override
    public byte[] doit_byte()
    {
        return NativeMethod.Base64Decode
                (mString, mAlphabet, mFillChar);
    }
}
