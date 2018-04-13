#include "edu_wpi_first_hal_sim_DriverStationSim.h"
#include "MockData/DriverStationData.h"
#include <jni.h>
#include "CallbackStore.h"

extern "C" {

JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_registerEnabledCallback
  (JNIEnv * env, jclass, jobject callback, jboolean initialNotify) {
  return sim::AllocateCallbackNoIndex(env, callback, initialNotify, &HALSIM_RegisterDriverStationEnabledCallback);
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_cancelEnabledCallback
  (JNIEnv * env, jclass, jint handle) {
  return sim::FreeCallbackNoIndex(env, handle, &HALSIM_CancelDriverStationEnabledCallback);
}

JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_getEnabled
  (JNIEnv *, jclass) {
  return HALSIM_GetDriverStationEnabled();
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_setEnabled
  (JNIEnv *, jclass, jboolean value) {
  HALSIM_SetDriverStationEnabled(value);
}

JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_registerAutonomousCallback
  (JNIEnv * env, jclass, jobject callback, jboolean initialNotify) {
  return sim::AllocateCallbackNoIndex(env, callback, initialNotify, &HALSIM_RegisterDriverStationAutonomousCallback);
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_cancelAutonomousCallback
  (JNIEnv * env, jclass, jint handle) {
  return sim::FreeCallbackNoIndex(env, handle, &HALSIM_CancelDriverStationAutonomousCallback);
}

JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_getAutonomous
  (JNIEnv *, jclass) {
  return HALSIM_GetDriverStationAutonomous();
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_setAutonomous
  (JNIEnv *, jclass, jboolean value) {
  HALSIM_SetDriverStationAutonomous(value);
}

JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_registerTestCallback
  (JNIEnv * env, jclass, jobject callback, jboolean initialNotify) {
  return sim::AllocateCallbackNoIndex(env, callback, initialNotify, &HALSIM_RegisterDriverStationTestCallback);
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_cancelTestCallback
  (JNIEnv * env, jclass, jint handle) {
  return sim::FreeCallbackNoIndex(env, handle, &HALSIM_CancelDriverStationTestCallback);
}

JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_getTest
  (JNIEnv *, jclass) {
  return HALSIM_GetDriverStationTest();
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_setTest
  (JNIEnv *, jclass, jboolean value) {
  HALSIM_SetDriverStationTest(value);
}

JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_registerEStopCallback
  (JNIEnv * env, jclass, jobject callback, jboolean initialNotify) {
  return sim::AllocateCallbackNoIndex(env, callback, initialNotify, &HALSIM_RegisterDriverStationEStopCallback);
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_cancelEStopCallback
  (JNIEnv * env, jclass, jint handle) {
  return sim::FreeCallbackNoIndex(env, handle, &HALSIM_CancelDriverStationEStopCallback);
}

JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_getEStop
  (JNIEnv *, jclass) {
  return HALSIM_GetDriverStationEStop();
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_setEStop
  (JNIEnv *, jclass, jboolean value) {
  HALSIM_SetDriverStationEStop(value);
}

JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_registerFmsAttachedCallback
  (JNIEnv * env, jclass, jobject callback, jboolean initialNotify) {
  return sim::AllocateCallbackNoIndex(env, callback, initialNotify, &HALSIM_RegisterDriverStationFmsAttachedCallback);
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_cancelFmsAttachedCallback
  (JNIEnv * env, jclass, jint handle) {
  return sim::FreeCallbackNoIndex(env, handle, &HALSIM_CancelDriverStationFmsAttachedCallback);
}

JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_getFmsAttached
  (JNIEnv *, jclass) {
  return HALSIM_GetDriverStationFmsAttached();
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_setFmsAttached
  (JNIEnv *, jclass, jboolean value) {
  HALSIM_SetDriverStationFmsAttached(value);
}

JNIEXPORT jint JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_registerDsAttachedCallback
  (JNIEnv * env, jclass, jobject callback, jboolean initialNotify) {
  return sim::AllocateCallbackNoIndex(env, callback, initialNotify, &HALSIM_RegisterDriverStationDsAttachedCallback);
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_cancelDsAttachedCallback
  (JNIEnv * env, jclass, jint handle) {
  return sim::FreeCallbackNoIndex(env, handle, &HALSIM_CancelDriverStationDsAttachedCallback);
}

JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_getDsAttached
  (JNIEnv *, jclass) {
  return HALSIM_GetDriverStationDsAttached();
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_setDsAttached
  (JNIEnv *, jclass, jboolean value) {
  HALSIM_SetDriverStationDsAttached(value);
}

/*
 * Class:     edu_wpi_first_hal_sim_DriverStationSim
 * Method:    setJoystickAxes
 * Signature: (B[F)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_setJoystickAxes
  (JNIEnv * env, jclass, jbyte joystickNum, jfloatArray axesArray) {
  HAL_JoystickAxes axes;
  {
      wpi::java::JFloatArrayRef jArrayRef(env, axesArray);
      auto arrayRef = jArrayRef.array();
      auto arraySize = arrayRef.size();
      int maxCount = arraySize < HAL_kMaxJoystickAxes  ? arraySize : HAL_kMaxJoystickAxes;
      axes.count = maxCount;
      for (int i = 0; i < maxCount; i++) {
        axes.axes[i] = arrayRef[i];
      }
  }
  HALSIM_SetJoystickAxes(joystickNum, &axes);
  return;
}

/*
 * Class:     edu_wpi_first_hal_sim_DriverStationSim
 * Method:    setJoystickPOVs
 * Signature: (B[S)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_setJoystickPOVs
  (JNIEnv * env, jclass, jbyte joystickNum, jshortArray povsArray) {
  HAL_JoystickPOVs povs;
  {
      wpi::java::JShortArrayRef jArrayRef(env, povsArray);
      auto arrayRef = jArrayRef.array();
      auto arraySize = arrayRef.size();
      int maxCount = arraySize < HAL_kMaxJoystickPOVs  ? arraySize : HAL_kMaxJoystickPOVs;
      povs.count = maxCount;
      for (int i = 0; i < maxCount; i++) {
        povs.povs[i] = arrayRef[i];
      }
  }
  HALSIM_SetJoystickPOVs(joystickNum, &povs);
  return;
}

/*
 * Class:     edu_wpi_first_hal_sim_DriverStationSim
 * Method:    setJoystickButtons
 * Signature: (BII)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_setJoystickButtons
  (JNIEnv * env, jclass, jbyte joystickNum, jint buttons , jint count) {
  if (count > 32) {
    count = 32;
  }
  HAL_JoystickButtons joystickButtons;
  joystickButtons.count = count;
  joystickButtons.buttons = buttons;
  HALSIM_SetJoystickButtons(joystickNum, &joystickButtons);
}

/*
 * Class:     edu_wpi_first_hal_sim_DriverStationSim
 * Method:    setMatchInfo
 * Signature: (Ledu/wpi/first/wpilibj/hal/MatchInfoData;)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_setMatchInfo
  (JNIEnv * env, jclass, jobject info) {

  }

/*
 * Class:     edu_wpi_first_hal_sim_DriverStationSim
 * Method:    registerAllCallbacks
 * Signature: (Ledu/wpi/first/hal/sim/NotifyCallback;Z)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_registerAllCallbacks
  (JNIEnv * env, jclass, jobject callback, jboolean initialNotify) {
  sim::AllocateCallbackNoIndex(env, callback, initialNotify, [](HAL_NotifyCallback cb, void* param, HAL_Bool in){
    HALSIM_RegisterDriverStationAllCallbacks(cb, param, in);
    return 0;
  });
}

/*
 * Class:     edu_wpi_first_hal_sim_DriverStationSim
 * Method:    notifyNewData
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_notifyNewData
  (JNIEnv *, jclass) {
  HALSIM_NotifyDriverStationNewData();
}

JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_DriverStationSim_resetData
  (JNIEnv*, jclass) {
  HALSIM_ResetDriverStationData();
}

}
