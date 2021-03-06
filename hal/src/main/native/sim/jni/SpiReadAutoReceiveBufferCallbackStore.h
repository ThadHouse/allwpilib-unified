/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <jni.h>

#include <support/jni_util.h>

#include "HAL/Types.h"
#include "HAL/handles/UnlimitedHandleResource.h"
#include "MockData/HAL_Value.h"
#include "MockData/NotifyListener.h"
#include "MockData/SPIData.h"
#include "SimulatorJNI.h"

namespace sim {
class SpiReadAutoReceiveBufferCallbackStore {
 public:
  void create(JNIEnv* env, jobject obj);
  int32_t performCallback(const char* name, unsigned char* buffer,
                          int32_t numToRead);
  void free(JNIEnv* env);
  void setCallbackId(int32_t id) { callbackId = id; }
  int32_t getCallbackId() { return callbackId; }

 private:
  wpi::java::JGlobal<jobject> m_call;
  int32_t callbackId;
};

void InitializeSpiBufferStore();

typedef int32_t (*RegisterSpiBufferCallbackFunc)(
    int32_t index, HAL_SpiReadAutoReceiveBufferCallback callback, void* param);
typedef void (*FreeSpiBufferCallbackFunc)(int32_t index, int32_t uid);

SIM_JniHandle AllocateSpiBufferCallback(
    JNIEnv* env, jint index, jobject callback,
    RegisterSpiBufferCallbackFunc createCallback);
void FreeSpiBufferCallback(JNIEnv* env, SIM_JniHandle handle, jint index,
                           FreeSpiBufferCallbackFunc freeCallback);
}  // namespace sim
