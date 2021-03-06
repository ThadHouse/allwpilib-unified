/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <jni.h>

#include "CallbackStore.h"
#include "MockData/RelayData.h"
#include "edu_wpi_first_hal_sim_mockdata_RelayDataJNI.h"

extern "C" {

JNIEXPORT jint JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_registerInitializedForwardCallback(
    JNIEnv* env, jclass, jint index, jobject callback, jboolean initialNotify) {
  return sim::AllocateCallback(env, index, callback, initialNotify,
                               &HALSIM_RegisterRelayInitializedForwardCallback);
}

JNIEXPORT void JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_cancelInitializedForwardCallback(
    JNIEnv* env, jclass, jint index, jint handle) {
  return sim::FreeCallback(env, handle, index,
                           &HALSIM_CancelRelayInitializedForwardCallback);
}

JNIEXPORT jboolean JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_getInitializedForward(
    JNIEnv*, jclass, jint index) {
  return HALSIM_GetRelayInitializedForward(index);
}

JNIEXPORT void JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_setInitializedForward(
    JNIEnv*, jclass, jint index, jboolean value) {
  HALSIM_SetRelayInitializedForward(index, value);
}

JNIEXPORT jint JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_registerInitializedReverseCallback(
    JNIEnv* env, jclass, jint index, jobject callback, jboolean initialNotify) {
  return sim::AllocateCallback(env, index, callback, initialNotify,
                               &HALSIM_RegisterRelayInitializedReverseCallback);
}

JNIEXPORT void JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_cancelInitializedReverseCallback(
    JNIEnv* env, jclass, jint index, jint handle) {
  return sim::FreeCallback(env, handle, index,
                           &HALSIM_CancelRelayInitializedReverseCallback);
}

JNIEXPORT jboolean JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_getInitializedReverse(
    JNIEnv*, jclass, jint index) {
  return HALSIM_GetRelayInitializedReverse(index);
}

JNIEXPORT void JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_setInitializedReverse(
    JNIEnv*, jclass, jint index, jboolean value) {
  HALSIM_SetRelayInitializedReverse(index, value);
}

JNIEXPORT jint JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_registerForwardCallback(
    JNIEnv* env, jclass, jint index, jobject callback, jboolean initialNotify) {
  return sim::AllocateCallback(env, index, callback, initialNotify,
                               &HALSIM_RegisterRelayForwardCallback);
}

JNIEXPORT void JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_cancelForwardCallback(
    JNIEnv* env, jclass, jint index, jint handle) {
  return sim::FreeCallback(env, handle, index,
                           &HALSIM_CancelRelayForwardCallback);
}

JNIEXPORT jboolean JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_getForward(JNIEnv*, jclass,
                                                            jint index) {
  return HALSIM_GetRelayForward(index);
}

JNIEXPORT void JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_setForward(JNIEnv*, jclass,
                                                            jint index,
                                                            jboolean value) {
  HALSIM_SetRelayForward(index, value);
}

JNIEXPORT jint JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_registerReverseCallback(
    JNIEnv* env, jclass, jint index, jobject callback, jboolean initialNotify) {
  return sim::AllocateCallback(env, index, callback, initialNotify,
                               &HALSIM_RegisterRelayReverseCallback);
}

JNIEXPORT void JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_cancelReverseCallback(
    JNIEnv* env, jclass, jint index, jint handle) {
  return sim::FreeCallback(env, handle, index,
                           &HALSIM_CancelRelayReverseCallback);
}

JNIEXPORT jboolean JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_getReverse(JNIEnv*, jclass,
                                                            jint index) {
  return HALSIM_GetRelayReverse(index);
}

JNIEXPORT void JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_setReverse(JNIEnv*, jclass,
                                                            jint index,
                                                            jboolean value) {
  HALSIM_SetRelayReverse(index, value);
}

JNIEXPORT void JNICALL
Java_edu_wpi_first_hal_sim_mockdata_RelayDataJNI_resetData(JNIEnv*, jclass,
                                                           jint index) {
  HALSIM_ResetRelayData(index);
}

}  // extern "C"
