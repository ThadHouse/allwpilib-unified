#pragma once

#include "MockData/AnalogTriggerData.h"

namespace frc {
namespace sim {
class AnalogTriggerSim {
 public:
  AnalogTriggerSim(int index) {
    m_index = index;
  }

  int RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogTriggerInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedCallback(int uid) {
    HALSIM_CancelAnalogTriggerInitializedCallback(m_index, uid);
  }
  bool GetInitialized() {
    return HALSIM_GetAnalogTriggerInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetAnalogTriggerInitialized(m_index, initialized);
  }

  int RegisterTriggerLowerBoundCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogTriggerTriggerLowerBoundCallback(m_index, callback, param, initialNotify);
  }
  void CancelTriggerLowerBoundCallback(int uid) {
    HALSIM_CancelAnalogTriggerTriggerLowerBoundCallback(m_index, uid);
  }
  double GetTriggerLowerBound() {
    return HALSIM_GetAnalogTriggerTriggerLowerBound(m_index);
  }
  void SetTriggerLowerBound(double triggerLowerBound) {
    HALSIM_SetAnalogTriggerTriggerLowerBound(m_index, triggerLowerBound);
  }

  int RegisterTriggerUpperBoundCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogTriggerTriggerUpperBoundCallback(m_index, callback, param, initialNotify);
  }
  void CancelTriggerUpperBoundCallback(int uid) {
    HALSIM_CancelAnalogTriggerTriggerUpperBoundCallback(m_index, uid);
  }
  double GetTriggerUpperBound() {
    return HALSIM_GetAnalogTriggerTriggerUpperBound(m_index);
  }
  void SetTriggerUpperBound(double triggerUpperBound) {
    HALSIM_SetAnalogTriggerTriggerUpperBound(m_index, triggerUpperBound);
  }

  void ResetData() {
    HALSIM_ResetAnalogTriggerData(m_index);
  }
 private:
  int m_index;
};
}
}
