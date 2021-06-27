package com.example.logproject;

import java.io.File;

/**
 * c++ 尽量写简单，定制化操作留给java层来做
 * 同步锁，文件目录创建
 */
public class FileLogger {

    private long mNativePtr;

    public FileLogger(File logFile,long fileMaxSize){
        mNativePtr = nativeCreate(logFile.getAbsolutePath(),fileMaxSize);
    }

    /**
     * 在C++ 层创建一个FileLog对象
     * @param absolutePath
     * @param fileMaxSize
     * @return
     */
    private native long nativeCreate(String absolutePath, long fileMaxSize);


    public void write(String text) {

        byte[] data= text.getBytes();
        nWrite(mNativePtr,data,data.length);
    }

    private native void nWrite(long mNativePtr, byte[] data, int dataLength) ;
}
