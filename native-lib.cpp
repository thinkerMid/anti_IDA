#include <jni.h>
#include <string>
#include <iostream>

static __attribute__((always_inline)) void junk_code_004() {
#ifdef __aarch64__
    int a = 3;
    int b = 4;
    int c = 6;
    if (c < sqrt(a*a+b*b)) {
        __asm__ __volatile__(
                ".long 12345678\n"
                ".long 12345678\n"
                );
    }
#endif
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ollvmdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    junk_code_004();
    return env->NewStringUTF(hello.c_str());
}




