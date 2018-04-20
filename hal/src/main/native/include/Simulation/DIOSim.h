#pragma once

#include "MockData/DIOData.h"

namespace frc {
namespace sim {
class DIOSim {
 public:
  DIOSim(int index) {
    m_index = index;
  }

  int RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDIOInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedCallback(int uid) {
    HALSIM_CancelDIOInitializedCallback(m_index, uid);
  }
  bool GetInitialized() {
    return HALSIM_GetDIOInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetDIOInitialized(m_index, initialized);
  }

  int RegisterValueCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDIOValueCallback(m_index, callback, param, initialNotify);
  }
  void CancelValueCallback(int uid) {
    HALSIM_CancelDIOValueCallback(m_index, uid);
  }
  bool GetValue() {
    return HALSIM_GetDIOValue(m_index);
  }
  void SetValue(bool value) {
    HALSIM_SetDIOValue(m_index, value);
  }

  int RegisterPulseLengthCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDIOPulseLengthCallback(m_index, callback, param, initialNotify);
  }
  void CancelPulseLengthCallback(int uid) {
    HALSIM_CancelDIOPulseLengthCallback(m_index, uid);
  }
  double GetPulseLength() {
    return HALSIM_GetDIOPulseLength(m_index);
  }
  void SetPulseLength(double pulseLength) {
    HALSIM_SetDIOPulseLength(m_index, pulseLength);
  }

  int RegisterIsInputCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDIOIsInputCallback(m_index, callback, param, initialNotify);
  }
  void CancelIsInputCallback(int uid) {
    HALSIM_CancelDIOIsInputCallback(m_index, uid);
  }
  bool GetIsInput() {
    return HALSIM_GetDIOIsInput(m_index);
  }
  void SetIsInput(bool isInput) {
    HALSIM_SetDIOIsInput(m_index, isInput);
  }

  int RegisterFilterIndexCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDIOFilterIndexCallback(m_index, callback, param, initialNotify);
  }
  void CancelFilterIndexCallback(int uid) {
    HALSIM_CancelDIOFilterIndexCallback(m_index, uid);
  }
  int GetFilterIndex() {
    return HALSIM_GetDIOFilterIndex(m_index);
  }
  void SetFilterIndex(int filterIndex) {
    HALSIM_SetDIOFilterIndex(m_index, filterIndex);
  }

  void ResetData() {
    HALSIM_ResetDIOData(m_index);
  }
 private:
  int m_index;
};
}
}
