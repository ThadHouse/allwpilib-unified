#pragma once

#include "MockData/AnalogOutData.h"

namespace frc {
namespace sim {
class AnalogOutSim {
 public:
  AnalogOutSim(int index) {
    m_index = index;
  }

  int RegisterVoltageCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogOutVoltageCallback(m_index, callback, param, initialNotify);
  }
  void CancelVoltageCallback(int uid) {
    HALSIM_CancelAnalogOutVoltageCallback(m_index, uid);
  }
  double GetVoltage() {
    return HALSIM_GetAnalogOutVoltage(m_index);
  }
  void SetVoltage(double voltage) {
    HALSIM_SetAnalogOutVoltage(m_index, voltage);
  }

  int RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogOutInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedCallback(int uid) {
    HALSIM_CancelAnalogOutInitializedCallback(m_index, uid);
  }
  bool GetInitialized() {
    return HALSIM_GetAnalogOutInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetAnalogOutInitialized(m_index, initialized);
  }

  void ResetData() {
    HALSIM_ResetAnalogOutData(m_index);
  }
 private:
  int m_index;
};
}
}
