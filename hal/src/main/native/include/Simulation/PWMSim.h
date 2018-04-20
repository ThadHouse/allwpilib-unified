#pragma once

#include "MockData/PWMData.h"

namespace frc {
namespace sim {
class PWMSim {
 public:
  PWMSim(int index) {
    m_index = index;
  }

  int RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPWMInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedCallback(int uid) {
    HALSIM_CancelPWMInitializedCallback(m_index, uid);
  }
  bool GetInitialized() {
    return HALSIM_GetPWMInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetPWMInitialized(m_index, initialized);
  }

  int RegisterRawValueCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPWMRawValueCallback(m_index, callback, param, initialNotify);
  }
  void CancelRawValueCallback(int uid) {
    HALSIM_CancelPWMRawValueCallback(m_index, uid);
  }
  int GetRawValue() {
    return HALSIM_GetPWMRawValue(m_index);
  }
  void SetRawValue(int rawValue) {
    HALSIM_SetPWMRawValue(m_index, rawValue);
  }

  int RegisterSpeedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPWMSpeedCallback(m_index, callback, param, initialNotify);
  }
  void CancelSpeedCallback(int uid) {
    HALSIM_CancelPWMSpeedCallback(m_index, uid);
  }
  double GetSpeed() {
    return HALSIM_GetPWMSpeed(m_index);
  }
  void SetSpeed(double speed) {
    HALSIM_SetPWMSpeed(m_index, speed);
  }

  int RegisterPositionCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPWMPositionCallback(m_index, callback, param, initialNotify);
  }
  void CancelPositionCallback(int uid) {
    HALSIM_CancelPWMPositionCallback(m_index, uid);
  }
  double GetPosition() {
    return HALSIM_GetPWMPosition(m_index);
  }
  void SetPosition(double position) {
    HALSIM_SetPWMPosition(m_index, position);
  }

  int RegisterPeriodScaleCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPWMPeriodScaleCallback(m_index, callback, param, initialNotify);
  }
  void CancelPeriodScaleCallback(int uid) {
    HALSIM_CancelPWMPeriodScaleCallback(m_index, uid);
  }
  int GetPeriodScale() {
    return HALSIM_GetPWMPeriodScale(m_index);
  }
  void SetPeriodScale(int periodScale) {
    HALSIM_SetPWMPeriodScale(m_index, periodScale);
  }

  int RegisterZeroLatchCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPWMZeroLatchCallback(m_index, callback, param, initialNotify);
  }
  void CancelZeroLatchCallback(int uid) {
    HALSIM_CancelPWMZeroLatchCallback(m_index, uid);
  }
  bool GetZeroLatch() {
    return HALSIM_GetPWMZeroLatch(m_index);
  }
  void SetZeroLatch(bool zeroLatch) {
    HALSIM_SetPWMZeroLatch(m_index, zeroLatch);
  }

  void ResetData() {
    HALSIM_ResetPWMData(m_index);
  }
 private:
  int m_index;
};
}
}
