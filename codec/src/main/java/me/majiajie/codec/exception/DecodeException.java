package me.majiajie.codec.exception;

import java.io.IOException;

public class DecodeException extends IOException
{
    public DecodeException()
    {
        super("Decoding error: please confirm whether the input character can be applied to this decoding method.");
    }
}
