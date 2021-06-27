#include <jni.h>
#include <string>
#include "TXFileLogger.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_logproject_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_logproject_FileLogger_nativeCreate(JNIEnv *env, jobject instance,jstring logPath_, jlong fileMaxSize) {
    // TODO: implement nativeCreate()
    const char* logPath = env->GetStringUTFChars(logPath_,JNI_FALSE);
    TXFileLogger *txFileLogger = new TXFileLogger(logPath,fileMaxSize);

    env->ReleaseStringUTFChars(logPath_,logPath);
    return (jlong)txFileLogger;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_logproject_FileLogger_nWrite(JNIEnv *env, jobject thiz, jlong nativePtr,
                                              jbyteArray data_, jint dataLen) {
    // TODO: implement nWrite()

    jbyte  *data = env->GetByteArrayElements(data_,NULL);
    TXFileLogger * txFileLogger = reinterpret_cast<TXFileLogger *>(nativePtr);
    txFileLogger->writeData(data,dataLen);
    env->ReleaseByteArrayElements(data_,data,0);

}