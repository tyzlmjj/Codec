package me.majiajie.codec;


public class CustomBase64_Encode extends CustomBase64_Decode
{
    public CustomBase64_Encode(String string)
    {
        super(string);
    }

    @Override
    public String doit()
    {
        return NativeMethod.Base64Encode(mString, mAlphabet, mFillChar, mMaxCharLine);
    }
}
