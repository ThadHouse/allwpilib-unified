#include "SimJNI.h"
#include "HAL/cpp/Log.h"

JavaVM* jvm = nullptr;

namespace frc {
jint SimOnLoad(JavaVM* vm, void* reserved) {
  jvm = vm;

  Log::ReportingLevel() = logDEBUG;

  JNIEnv *env;
  if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK)
    return JNI_ERR;

  return JNI_VERSION_1_6;
}

void SimOnUnload(JavaVM * vm, void* reserved) {
  JNIEnv *env;
  if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK)
    return;
  jvm = nullptr;
}
}
