//
// Created by xiaotian on 2016/7/29.
//



#include <stdio.h>

#include <unistd.h>

#include "com_tangyin_mobile_ges_jnidemo_MainActivity.h"
#include <android/log.h>

#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)


JNIEXPORT void JNICALL Java_com_tangyin_mobile_ges_jnidemo_MainActivity_fork
        (JNIEnv *env, jobject obj){
    int pid = fork();//开一个子进程，拿到进程的pid
    if(pid == 0){//这个函数会执行两次，0时是子线程执行
        LOGD("pid== %d",pid);
        while(1){
//            sleep(1);
//            LOGD("sub process is running");
            int ppid = getppid();
            if (ppid == 1){
                sleep(1);
                FILE *pFILE = fopen("data/data/com.tangyin.mobile.ges.jnidemo","r");
                if(pFILE == NULL){//程序被卸载了，跳到百度
                    execlp("am", "am", "start", "--user","0","-a", "android.intent.action.VIEW", "-d", "http://www.baidu.com", (char *) NULL);
                } else{//程序只是进程挂掉了，重启进程
                    execlp("am", "am", "start", "--user","0", "-n" , "com.tangyin.mobile.ges.jnidemo/com.tangyin.mobile.ges.jnidemo.MainActivity",(char *) NULL);
                }
            }
        }
    }else if (pid > 0){
//        LOGD("pid== %d",pid);
    } else{
//        LOGD("pid== %d",pid);
    }

}


