#pragma once

#include "MockData/AnalogGyroData.h"

namespace frc {
namespace sim {
class AnalogGyroSim {
 public:
  AnalogGyroSim(int index) {
    m_index = index;
  }

  int RegisterAngleCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogGyroAngleCallback(m_index, callback, param, initialNotify);
  }
  void CancelAngleCallback(int uid) {
    HALSIM_CancelAnalogGyroAngleCallback(m_index, uid);
  }
  double GetAngle() {
    return HALSIM_GetAnalogGyroAngle(m_index);
  }
  void SetAngle(double angle) {
    HALSIM_SetAnalogGyroAngle(m_index, angle);
  }

  int RegisterRateCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogGyroRateCallback(m_index, callback, param, initialNotify);
  }
  void CancelRateCallback(int uid) {
    HALSIM_CancelAnalogGyroRateCallback(m_index, uid);
  }
  double GetRate() {
    return HALSIM_GetAnalogGyroRate(m_index);
  }
  void SetRate(double rate) {
    HALSIM_SetAnalogGyroRate(m_index, rate);
  }

  int RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogGyroInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedCallback(int uid) {
    HALSIM_CancelAnalogGyroInitializedCallback(m_index, uid);
  }
  bool GetInitialized() {
    return HALSIM_GetAnalogGyroInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetAnalogGyroInitialized(m_index, initialized);
  }

  void ResetData() {
    HALSIM_ResetAnalogGyroData(m_index);
  }
 private:
  int m_index;
};
}
}
