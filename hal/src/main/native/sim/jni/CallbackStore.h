#pragma once

#include "support/jni_util.h"
#include <jni.h>
#include "HAL/handles/UnlimitedHandleResource.h"
#include "MockData/HAL_Value.h"
#include "MockData/NotifyListener.h"
#include "HAL/types.h"
#include "SimJni.h"

namespace sim {
  class CallbackStore {
   public:
    void create(JNIEnv* env, jobject obj);
    void performCallback(const char* name, const HAL_Value* value);
    void free(JNIEnv* env);
    void setCallbackId(int32_t id) { callbackId = id; }
    int32_t getCallbackId() { return callbackId; }
   private:
    wpi::java::JGlobal<jobject> m_call;
    int32_t callbackId;
  };

  void InitializeStore();

  typedef int32_t (*RegisterCallbackFunc)(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
  typedef void (*FreeCallbackFunc)(int32_t index, int32_t uid);

  SIM_JniHandle AllocateCallback(JNIEnv* env, jint index, jobject callback, jboolean initialNotify, RegisterCallbackFunc createCallback);
  void FreeCallback(JNIEnv* env, SIM_JniHandle handle, jint index, FreeCallbackFunc freeCallback);
}
