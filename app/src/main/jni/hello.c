#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include <android/log.h>
#define TAG "myTag"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE,TAG,__VA_ARGS__)
JNIEXPORT jstring JNICALL
Java_com_test_ndk_hellondk_MainActivity_getHelloStringFromC(JNIEnv *env, jclass type) {
    LOGV("log from native!");
    return (*env)->NewStringUTF(env,"Get Hello String from C!");
}

JNIEXPORT jintArray JNICALL
Java_com_test_ndk_hellondk_MainActivity_updateIntArray(JNIEnv *env, jclass type, jintArray array) {
    //方法一：Java层数组传给native层，native层获取数据修改后返回该数组
     jint nativeArray[5];
     (*env)->GetIntArrayRegion(env,array,0,5,nativeArray);
     int j;
     for(j = 0; j<5;j++){
         nativeArray[j]+=5;
         LOGV("from c int %d",nativeArray[j]);
     }
     (*env)->SetIntArrayRegion(env,array,0,5,nativeArray);
     return array;
     /*
    //方法二：生成数据的指针
    jint* data =(*env)->GetIntArrayElements(env,array,NULL);
    jsize len = (*env)->GetArrayLength(env,array);
    int j;
    for(j = 0;j<len;j++){
        data[j]+=3;
        LOGV("from c int %d",data[j]);
    }
    //释放相关的资源
    (*env)->ReleaseIntArrayElements(env,array,data,0);
    return array;
      */
}