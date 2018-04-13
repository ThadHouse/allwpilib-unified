#include "SimJni.h"
#include "HAL/cpp/Log.h"
#include "HAL/HAL.h"

using namespace wpi::java;

static JavaVM* jvm = nullptr;
static JClass simValueCls;
static JClass notifyCallbackCls;
static jmethodID notifyCallbackCallback;
static jmethodID valueMakeBoolean;
static jmethodID valueMakeEnum;
static jmethodID valueMakeInt;
static jmethodID valueMakeLong;
static jmethodID valueMakeDouble;
static jmethodID valueMakeUnassigned;

namespace sim {
jint SimOnLoad(JavaVM* vm, void* reserved) {
  jvm = vm;

  JNIEnv *env;
  if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK)
    return JNI_ERR;

  simValueCls = JClass(env, "edu/wpi/first/hal/sim/SimValue");
  if (!simValueCls) return JNI_ERR;

  notifyCallbackCls = JClass(env, "edu/wpi/first/hal/sim/NotifyCallback");
  if (!notifyCallbackCls) return JNI_ERR;

  notifyCallbackCallback = env->GetMethodID(notifyCallbackCls, "callback", "(Ljava/lang/String;Ledu/wpi/first/hal/sim/SimValue;)V");
  if (!notifyCallbackCallback) return JNI_ERR;

  valueMakeBoolean = env->GetStaticMethodID(simValueCls, "makeBoolean", "(Z)Ledu/wpi/first/hal/sim/SimValue;");
  if (!valueMakeBoolean) return JNI_ERR;

  valueMakeEnum = env->GetStaticMethodID(simValueCls, "makeEnum", "(I)Ledu/wpi/first/hal/sim/SimValue;");
  if (!valueMakeEnum) return JNI_ERR;

  valueMakeInt = env->GetStaticMethodID(simValueCls, "makeInt", "(I)Ledu/wpi/first/hal/sim/SimValue;");
  if (!valueMakeInt) return JNI_ERR;

  valueMakeLong = env->GetStaticMethodID(simValueCls, "makeLong", "(J)Ledu/wpi/first/hal/sim/SimValue;");
  if (!valueMakeLong) return JNI_ERR;

  valueMakeDouble = env->GetStaticMethodID(simValueCls, "makeDouble", "(D)Ledu/wpi/first/hal/sim/SimValue;");
  if (!valueMakeDouble) return JNI_ERR;

  valueMakeUnassigned = env->GetStaticMethodID(simValueCls, "makeUnassigned", "()Ledu/wpi/first/hal/sim/SimValue;");
  if (!valueMakeUnassigned) return JNI_ERR;

  HAL_Initialize(500, 0);
  InitializeAccelerometerSim();

  return JNI_VERSION_1_6;
}

void SimOnUnload(JavaVM * vm, void* reserved) {
  JNIEnv *env;
  if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK)
    return;

  simValueCls.free(env);
  jvm = nullptr;
}

JavaVM* GetJVM() {
  return jvm;
}

jmethodID GetNotifyCallback() {
  return notifyCallbackCallback;
}

jobject MakeSimValue(JNIEnv* env, const HAL_Value* value) {
  switch(value->type) {
    case HAL_BOOLEAN:
      return env->CallStaticObjectMethod(simValueCls, valueMakeBoolean, (jboolean)value->data.v_boolean);
    case HAL_DOUBLE:
      return env->CallStaticObjectMethod(simValueCls, valueMakeBoolean, (jdouble)value->data.v_double);
    case HAL_ENUM:
      return env->CallStaticObjectMethod(simValueCls, valueMakeBoolean, (jint)value->data.v_enum);
    case HAL_INT:
      return env->CallStaticObjectMethod(simValueCls, valueMakeBoolean, (jint)value->data.v_int);
    case HAL_LONG:
      return env->CallStaticObjectMethod(simValueCls, valueMakeBoolean, (jlong)value->data.v_long);
    default:
    return env->CallStaticObjectMethod(simValueCls, valueMakeUnassigned);
  }
}
}
