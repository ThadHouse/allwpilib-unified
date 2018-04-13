#include "edu_wpi_first_hal_sim_AccelerometerSim.h"
#include "MockData/AccelerometerData.h"
#include "HAL/handles/UnlimitedHandleResource.h"
#include "SimJni.h"
#include "support/jni_util.h"
#include "CallbackStore.h"

using namespace wpi::java;

namespace sim {
  void InitializeAccelerometerSim() {
    InitializeStore();
  }
}

extern "C" {
/*
 * Class:     edu_wpi_first_hal_sim_AccelerometerSim
 * Method:    resetData
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_AccelerometerSim_resetData
  (JNIEnv *, jclass, jint index) {
    HALSIM_ResetAccelerometerData(index);
  }

/*
 * Class:     edu_wpi_first_hal_sim_AccelerometerSim
 * Method:    registerActiveCallback
 * Signature: (ILedu/wpi/first/hal/sim/NotifyCallback;Z)I
 */
JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_AccelerometerSim_registerActiveCallback
  (JNIEnv * env, jclass, jint index, jobject callback, jboolean initialNotify) {
    return AllocateCallback(env, index, callback, initialNotify, &HALSIM_RegisterAccelerometerActiveCallback);
  }

/*
 * Class:     edu_wpi_first_hal_sim_AccelerometerSim
 * Method:    cancelActiveCallback
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_AccelerometerSim_cancelActiveCallback
  (JNIEnv * env, jclass, jint index, jint handle) {
  auto callback = callbackHandles->Free(handle);
  HALSIM_CancelAccelerometerActiveCallback(index, callback->callbackId);
  callback->free(env);
}

/*
 * Class:     edu_wpi_first_hal_sim_AccelerometerSim
 * Method:    getActive
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_AccelerometerSim_getActive
  (JNIEnv *, jclass, jint index) {
    return HALSIM_GetAccelerometerActive(index);
  }

/*
 * Class:     edu_wpi_first_hal_sim_AccelerometerSim
 * Method:    setActive
 * Signature: (IZ)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_AccelerometerSim_setActive
  (JNIEnv *, jclass, jint index, jboolean value) {
    HALSIM_SetAccelerometerActive(index, value);
  }
}
