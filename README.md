# JniDemo
通过jni调用c的fork()函数，实现分叉出一个linux进程，用于检测自己的app进程是否被杀死，从而实现两个效果；
1、app进程被杀死，自动重启当前app；
2、app被卸载，手机浏览器自动开启并跳转到百度页面；