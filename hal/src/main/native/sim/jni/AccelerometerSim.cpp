#include "edu_wpi_first_hal_sim_AccelerometerSim.h"
#include "MockData/AccelerometerData.h"


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
  (JNIEnv *, jclass, jint index, jobject callback, jboolean initialNotify) {
    HALSIM_RegisterAccelerometerActiveCallback(index, [](const char* name, void* param, const HAL_Value* value){

    }, nullptr, initialNotify);
  }

/*
 * Class:     edu_wpi_first_hal_sim_AccelerometerSim
 * Method:    cancelActiveCallback
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_AccelerometerSim_cancelActiveCallback
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     edu_wpi_first_hal_sim_AccelerometerSim
 * Method:    getActive
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_edu_wpi_first_hal_sim_AccelerometerSim_getActive
  (JNIEnv *, jclass, jint);

/*
 * Class:     edu_wpi_first_hal_sim_AccelerometerSim
 * Method:    setActive
 * Signature: (IZ)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_sim_AccelerometerSim_setActive
  (JNIEnv *, jclass, jint, jboolean);
}
