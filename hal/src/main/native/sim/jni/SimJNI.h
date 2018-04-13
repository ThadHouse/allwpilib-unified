#pragma once

#include "jni.h"
#include "support/jni_util.h"
#include "HAL/Types.h"
#include "MockData/HAL_Value.h"

typedef HAL_Handle SIM_JniHandle;

namespace sim {
void InitializeAccelerometerSim();

JavaVM* GetJVM();

jmethodID GetNotifyCallback();

jobject MakeSimValue(JNIEnv* env, const HAL_Value* value);
}
