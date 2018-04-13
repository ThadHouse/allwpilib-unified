#pragma once

#include "support/jni_util.h"
#include <jni.h>
#include "HAL/handles/UnlimitedHandleResource.h"
#include "MockData/HAL_Value.h"
#include "MockData/NotifyListener.h"
#include "HAL/types.h"
#include "SimJni.h"

using namespace wpi::java;

namespace {
  struct CallbackStore {
    void create(JNIEnv* env, jobject obj) {
      m_call = JGlobal<jobject>(env, obj);
    }

    void performCallback(const char* name, const HAL_Value* value) {
      JNIEnv* env;
      JavaVM* vm = sim::GetJVM();
      bool didAttachThread = false;
      int tryGetEnv = vm->GetEnv((void**)&env, JNI_VERSION_1_6);
      if (tryGetEnv == JNI_EDETACHED) {
        // Thread not attached
        didAttachThread = true;
        if (vm->AttachCurrentThread((void**)&env, nullptr) != 0) {
          // Failed to attach, log and return
          llvm::outs() << "Failed to attach\n";
          llvm::outs().flush();
          return;
        }
      } else if (tryGetEnv == JNI_EVERSION) {
        llvm::outs() << "Invalid JVM Version requested\n";
        llvm::outs().flush();
      }

      env->CallVoidMethod(m_call, sim::GetNotifyCallback(), MakeJString(env, name), sim::MakeSimValue(env, value));

      if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
      }

      if (didAttachThread) {
        vm->DetachCurrentThread();
      }
    }

    void free(JNIEnv* env) {
      m_call.free(env);
    }

    JGlobal<jobject> m_call;
    int32_t callbackId;
  };
}

static hal::UnlimitedHandleResource<SIM_JniHandle, CallbackStore, hal::HAL_HandleEnum::SimulationJni>* callbackHandles;

static void InitializeStore() {
  static hal::UnlimitedHandleResource<SIM_JniHandle, CallbackStore, hal::HAL_HandleEnum::SimulationJni> cb;
  callbackHandles = &cb;
}

typedef int32_t (*RegisterCallbackFunc)(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);

static SIM_JniHandle AllocateCallback(JNIEnv* env, jint index, jobject callback, jboolean initialNotify, RegisterCallbackFunc createCallback) {

  auto callbackStore = std::make_shared<CallbackStore>();

  auto handle = callbackHandles->Allocate(callbackStore);

  if (handle == HAL_kInvalidHandle) {
    return -1;
  }

  uintptr_t handleAsPtr = static_cast<uintptr_t>(handle);
  void* handleAsVoidPtr = reinterpret_cast<void*>(handleAsPtr);

  callbackStore->create(env, callback);

  auto callbackFunc = [](const char* name, void* param, const HAL_Value* value){
    llvm::outs().flush();
    uintptr_t handleTmp = reinterpret_cast<uintptr_t>(param);
    SIM_JniHandle handle =
        static_cast<SIM_JniHandle>(handleTmp);
    auto data = callbackHandles->Get(handle);
    if (!data) return;

    data->performCallback(name, value);

    llvm::outs().flush();

  };

  auto id = createCallback(index, callbackFunc, handleAsVoidPtr, initialNotify);

  callbackStore->callbackId = id;

  return handle;
}
