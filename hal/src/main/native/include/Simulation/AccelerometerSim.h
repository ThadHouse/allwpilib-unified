#pragma once

#include "MockData/AccelerometerData.h"

namespace frc {
namespace sim {
class AccelerometerSim {
 public:
  AccelerometerSim(int index) {
    m_index = index;
  }

  int RegisterActiveCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAccelerometerActiveCallback(m_index, callback, param, initialNotify);
  }
  void CancelActiveCallback(int uid) {
    HALSIM_CancelAccelerometerActiveCallback(m_index, uid);
  }
  bool GetActive() {
    return HALSIM_GetAccelerometerActive(m_index);
  }
  void SetActive(bool active) {
    HALSIM_SetAccelerometerActive(m_index, active);
  }

  int RegisterRangeCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAccelerometerRangeCallback(m_index, callback, param, initialNotify);
  }
  void CancelRangeCallback(int uid) {
    HALSIM_CancelAccelerometerRangeCallback(m_index, uid);
  }
  HAL_AccelerometerRange GetRange() {
    return HALSIM_GetAccelerometerRange(m_index);
  }
  void SetRange(HAL_AccelerometerRange range) {
    HALSIM_SetAccelerometerRange(m_index, range);
  }

  int RegisterXCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAccelerometerXCallback(m_index, callback, param, initialNotify);
  }
  void CancelXCallback(int uid) {
    HALSIM_CancelAccelerometerXCallback(m_index, uid);
  }
  double GetX() {
    return HALSIM_GetAccelerometerX(m_index);
  }
  void SetX(double x) {
    HALSIM_SetAccelerometerX(m_index, x);
  }

  int RegisterYCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAccelerometerYCallback(m_index, callback, param, initialNotify);
  }
  void CancelYCallback(int uid) {
    HALSIM_CancelAccelerometerYCallback(m_index, uid);
  }
  double GetY() {
    return HALSIM_GetAccelerometerY(m_index);
  }
  void SetY(double y) {
    HALSIM_SetAccelerometerY(m_index, y);
  }

  int RegisterZCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAccelerometerZCallback(m_index, callback, param, initialNotify);
  }
  void CancelZCallback(int uid) {
    HALSIM_CancelAccelerometerZCallback(m_index, uid);
  }
  double GetZ() {
    return HALSIM_GetAccelerometerZ(m_index);
  }
  void SetZ(double z) {
    HALSIM_SetAccelerometerZ(m_index, z);
  }

  void ResetData() {
    HALSIM_ResetAccelerometerData(m_index);
  }
 private:
  int m_index;
};
}
}
