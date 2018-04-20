#pragma once

#include "MockData/DigitalPWMData.h"

namespace frc {
namespace sim {
class DigitalPWMSim {
 public:
  DigitalPWMSim(int index) {
    m_index = index;
  }

  int RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDigitalPWMInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedCallback(int uid) {
    HALSIM_CancelDigitalPWMInitializedCallback(m_index, uid);
  }
  bool GetInitialized() {
    return HALSIM_GetDigitalPWMInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetDigitalPWMInitialized(m_index, initialized);
  }

  int RegisterDutyCycleCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDigitalPWMDutyCycleCallback(m_index, callback, param, initialNotify);
  }
  void CancelDutyCycleCallback(int uid) {
    HALSIM_CancelDigitalPWMDutyCycleCallback(m_index, uid);
  }
  double GetDutyCycle() {
    return HALSIM_GetDigitalPWMDutyCycle(m_index);
  }
  void SetDutyCycle(double dutyCycle) {
    HALSIM_SetDigitalPWMDutyCycle(m_index, dutyCycle);
  }

  int RegisterPinCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDigitalPWMPinCallback(m_index, callback, param, initialNotify);
  }
  void CancelPinCallback(int uid) {
    HALSIM_CancelDigitalPWMPinCallback(m_index, uid);
  }
  int GetPin() {
    return HALSIM_GetDigitalPWMPin(m_index);
  }
  void SetPin(int pin) {
    HALSIM_SetDigitalPWMPin(m_index, pin);
  }

  void ResetData() {
    HALSIM_ResetDigitalPWMData(m_index);
  }
 private:
  int m_index;
};
}
}
