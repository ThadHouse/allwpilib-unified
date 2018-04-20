#pragma once

#include "MockData/SPIAccelerometerData.h"

namespace frc {
namespace sim {
class SPIAccelerometerSim {
 public:
  SPIAccelerometerSim(int index) {
    m_index = index;
  }

  int RegisterActiveCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterSPIAccelerometerActiveCallback(m_index, callback, param, initialNotify);
  }
  void CancelActiveCallback(int uid) {
    HALSIM_CancelSPIAccelerometerActiveCallback(m_index, uid);
  }
  bool GetActive() {
    return HALSIM_GetSPIAccelerometerActive(m_index);
  }
  void SetActive(bool active) {
    HALSIM_SetSPIAccelerometerActive(m_index, active);
  }

  int RegisterRangeCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterSPIAccelerometerRangeCallback(m_index, callback, param, initialNotify);
  }
  void CancelRangeCallback(int uid) {
    HALSIM_CancelSPIAccelerometerRangeCallback(m_index, uid);
  }
  int GetRange() {
    return HALSIM_GetSPIAccelerometerRange(m_index);
  }
  void SetRange(int range) {
    HALSIM_SetSPIAccelerometerRange(m_index, range);
  }

  int RegisterXCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterSPIAccelerometerXCallback(m_index, callback, param, initialNotify);
  }
  void CancelXCallback(int uid) {
    HALSIM_CancelSPIAccelerometerXCallback(m_index, uid);
  }
  double GetX() {
    return HALSIM_GetSPIAccelerometerX(m_index);
  }
  void SetX(double x) {
    HALSIM_SetSPIAccelerometerX(m_index, x);
  }

  int RegisterYCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterSPIAccelerometerYCallback(m_index, callback, param, initialNotify);
  }
  void CancelYCallback(int uid) {
    HALSIM_CancelSPIAccelerometerYCallback(m_index, uid);
  }
  double GetY() {
    return HALSIM_GetSPIAccelerometerY(m_index);
  }
  void SetY(double y) {
    HALSIM_SetSPIAccelerometerY(m_index, y);
  }

  int RegisterZCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterSPIAccelerometerZCallback(m_index, callback, param, initialNotify);
  }
  void CancelZCallback(int uid) {
    HALSIM_CancelSPIAccelerometerZCallback(m_index, uid);
  }
  double GetZ() {
    return HALSIM_GetSPIAccelerometerZ(m_index);
  }
  void SetZ(double z) {
    HALSIM_SetSPIAccelerometerZ(m_index, z);
  }

  void ResetData() {
    HALSIM_ResetSPIAccelerometerData(m_index);
  }
 private:
  int m_index;
};
}
}
