// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("main");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("main")
//      }
//    }

#include <jni.h>
#include <iostream>

// Global java vm - this is shared between all plugins in Unity
JavaVM* globalVm;

// Called by unity upon loading the plugin
jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* jni_env = 0;
    vm->AttachCurrentThread(&jni_env, 0);

    // Share java vm with all other plugins that do not have direct jni access
    globalVm = vm;

    return JNI_VERSION_1_6;
}

extern "C" {
    JavaVM* getJavaVM(){
        return globalVm;
    }
};