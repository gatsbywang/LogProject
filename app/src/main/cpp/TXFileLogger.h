//
// Created by 花歹 on 2021/2/13.
//

#ifndef LOGPROJECT_TXFILELOGGER_H
#define LOGPROJECT_TXFILELOGGER_H

#include <string>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <jni.h>

using namespace std;
class TXFileLogger{

public:
    TXFileLogger(const char* logPath, long fileMaxSize);

    ~TXFileLogger();

    void writeData(jbyte *data, jint dataLen);

private:
    string logPath;
    long fileMaxSize;
    /**
     * 每次映射的大小
     */
    long increaseSize;

    /**
     * 映射的大小
     */
    long mmapSize;

    /**
     * 映射的首地址
     */
    char* mmapPtr;


    /**
     * 每次写入的位置
     */
    long dataPosition = 0;

    int getFileSize();

    void mmapFile(int i, long size);
};

#endif //LOGPROJECT_TXFILELOGGER_H
