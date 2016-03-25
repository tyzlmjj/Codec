package me.majiajie.codec;


import me.majiajie.codec.exception.DecodeException;

public abstract class Custom
{
    /**
     * 执行加解密
     * @return 结果
     */
    public abstract String doit() throws DecodeException;
}
