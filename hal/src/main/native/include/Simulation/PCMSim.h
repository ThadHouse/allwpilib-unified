#pragma once

#include "MockData/PCMData.h"

namespace frc {
namespace sim {
class PCMSim {
 public:
  PCMSim(int index) {
    m_index = index;
  }

  int RegisterSolenoidInitializedCallback(int channel, HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPCMSolenoidInitializedCallback(m_index, channel, callback, param, initialNotify);
  }
  void CancelSolenoidInitializedCallback(int channel, int uid) {
    HALSIM_CancelPCMSolenoidInitializedCallback(m_index, channel, uid);
  }
  bool GetSolenoidInitialized(int channel) {
    return HALSIM_GetPCMSolenoidInitialized(m_index, channel);
  }
  void SetSolenoidInitialized(int channel, bool solenoidInitialized) {
    HALSIM_SetPCMSolenoidInitialized(m_index, channel, solenoidInitialized);
  }

  int RegisterSolenoidOutputCallback(int channel, HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPCMSolenoidOutputCallback(m_index, channel, callback, param, initialNotify);
  }
  void CancelSolenoidOutputCallback(int channel, int uid) {
    HALSIM_CancelPCMSolenoidOutputCallback(m_index, channel, uid);
  }
  bool GetSolenoidOutput(int channel) {
    return HALSIM_GetPCMSolenoidOutput(m_index, channel);
  }
  void SetSolenoidOutput(int channel, bool solenoidOutput) {
    HALSIM_SetPCMSolenoidOutput(m_index, channel, solenoidOutput);
  }

  int RegisterCompressorInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPCMCompressorInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelCompressorInitializedCallback(int uid) {
    HALSIM_CancelPCMCompressorInitializedCallback(m_index, uid);
  }
  bool GetCompressorInitialized() {
    return HALSIM_GetPCMCompressorInitialized(m_index);
  }
  void SetCompressorInitialized(bool compressorInitialized) {
    HALSIM_SetPCMCompressorInitialized(m_index, compressorInitialized);
  }

  int RegisterCompressorOnCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPCMCompressorOnCallback(m_index, callback, param, initialNotify);
  }
  void CancelCompressorOnCallback(int uid) {
    HALSIM_CancelPCMCompressorOnCallback(m_index, uid);
  }
  bool GetCompressorOn() {
    return HALSIM_GetPCMCompressorOn(m_index);
  }
  void SetCompressorOn(bool compressorOn) {
    HALSIM_SetPCMCompressorOn(m_index, compressorOn);
  }

  int RegisterClosedLoopEnabledCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPCMClosedLoopEnabledCallback(m_index, callback, param, initialNotify);
  }
  void CancelClosedLoopEnabledCallback(int uid) {
    HALSIM_CancelPCMClosedLoopEnabledCallback(m_index, uid);
  }
  bool GetClosedLoopEnabled() {
    return HALSIM_GetPCMClosedLoopEnabled(m_index);
  }
  void SetClosedLoopEnabled(bool closedLoopEnabled) {
    HALSIM_SetPCMClosedLoopEnabled(m_index, closedLoopEnabled);
  }

  int RegisterPressureSwitchCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPCMPressureSwitchCallback(m_index, callback, param, initialNotify);
  }
  void CancelPressureSwitchCallback(int uid) {
    HALSIM_CancelPCMPressureSwitchCallback(m_index, uid);
  }
  bool GetPressureSwitch() {
    return HALSIM_GetPCMPressureSwitch(m_index);
  }
  void SetPressureSwitch(bool pressureSwitch) {
    HALSIM_SetPCMPressureSwitch(m_index, pressureSwitch);
  }

  int RegisterCompressorCurrentCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterPCMCompressorCurrentCallback(m_index, callback, param, initialNotify);
  }
  void CancelCompressorCurrentCallback(int uid) {
    HALSIM_CancelPCMCompressorCurrentCallback(m_index, uid);
  }
  double GetCompressorCurrent() {
    return HALSIM_GetPCMCompressorCurrent(m_index);
  }
  void SetCompressorCurrent(double compressorCurrent) {
    HALSIM_SetPCMCompressorCurrent(m_index, compressorCurrent);
  }

  void ResetData() {
    HALSIM_ResetPCMData(m_index);
  }
 private:
  int m_index;
};
}
}
