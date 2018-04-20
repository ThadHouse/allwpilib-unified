#pragma once

#include "MockData/PDPData.h"

namespace frc {
namespace sim {
class PDPSim {
 public:
  PDPSim(int index) {
    m_index = index;
  }

  int RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPDPInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedCallback(int uid) {
    HALSIM_CancelPDPInitializedCallback(m_index, uid);
  }
  bool GetInitialized() {
    return HALSIM_GetPDPInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetPDPInitialized(m_index, initialized);
  }

  int RegisterTemperatureCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPDPTemperatureCallback(m_index, callback, param, initialNotify);
  }
  void CancelTemperatureCallback(int uid) {
    HALSIM_CancelPDPTemperatureCallback(m_index, uid);
  }
  double GetTemperature() {
    return HALSIM_GetPDPTemperature(m_index);
  }
  void SetTemperature(double temperature) {
    HALSIM_SetPDPTemperature(m_index, temperature);
  }

  int RegisterVoltageCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPDPVoltageCallback(m_index, callback, param, initialNotify);
  }
  void CancelVoltageCallback(int uid) {
    HALSIM_CancelPDPVoltageCallback(m_index, uid);
  }
  double GetVoltage() {
    return HALSIM_GetPDPVoltage(m_index);
  }
  void SetVoltage(double voltage) {
    HALSIM_SetPDPVoltage(m_index, voltage);
  }

  int RegisterCurrentCallback(int channel, HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPDPCurrentCallback(m_index, channel, callback, param, initialNotify);
  }
  void CancelCurrentCallback(int channel, int uid) {
    HALSIM_CancelPDPCurrentCallback(m_index, channel, uid);
  }
  double GetCurrent(int channel) {
    return HALSIM_GetPDPCurrent(m_index, channel);
  }
  void SetCurrent(int channel, double current) {
    HALSIM_SetPDPCurrent(m_index, channel, current);
  }

  void ResetData() {
    HALSIM_ResetPDPData(m_index);
  }
 private:
  int m_index;
};
}
}
