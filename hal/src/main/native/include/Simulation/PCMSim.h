#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/PCMData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class PCMSim {
 public:
  PCMSim(int index) {
    m_index = index;
  }

  ChannelCallbackUniquePtr RegisterSolenoidInitializedCallback(int channel, NotifyCallback callback, bool initialNotify) {
    ChannelCallbackUniquePtr store(new CallbackStore<CancelCallbackChannelFunc>(m_index, channel, -1, callback, &HALSIM_CancelPCMSolenoidInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPCMSolenoidInitializedCallback(m_index, channel, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetSolenoidInitialized(int channel) {
    return HALSIM_GetPCMSolenoidInitialized(m_index, channel);
  }
  void SetSolenoidInitialized(int channel, bool solenoidInitialized) {
    HALSIM_SetPCMSolenoidInitialized(m_index, channel, solenoidInitialized);
  }

  ChannelCallbackUniquePtr RegisterSolenoidOutputCallback(int channel, NotifyCallback callback, bool initialNotify) {
    ChannelCallbackUniquePtr store(new CallbackStore<CancelCallbackChannelFunc>(m_index, channel, -1, callback, &HALSIM_CancelPCMSolenoidOutputCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPCMSolenoidOutputCallback(m_index, channel, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetSolenoidOutput(int channel) {
    return HALSIM_GetPCMSolenoidOutput(m_index, channel);
  }
  void SetSolenoidOutput(int channel, bool solenoidOutput) {
    HALSIM_SetPCMSolenoidOutput(m_index, channel, solenoidOutput);
  }

  CallbackUniquePtr RegisterCompressorInitializedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPCMCompressorInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPCMCompressorInitializedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetCompressorInitialized() {
    return HALSIM_GetPCMCompressorInitialized(m_index);
  }
  void SetCompressorInitialized(bool compressorInitialized) {
    HALSIM_SetPCMCompressorInitialized(m_index, compressorInitialized);
  }

  CallbackUniquePtr RegisterCompressorOnCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPCMCompressorOnCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPCMCompressorOnCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetCompressorOn() {
    return HALSIM_GetPCMCompressorOn(m_index);
  }
  void SetCompressorOn(bool compressorOn) {
    HALSIM_SetPCMCompressorOn(m_index, compressorOn);
  }

  CallbackUniquePtr RegisterClosedLoopEnabledCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPCMClosedLoopEnabledCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPCMClosedLoopEnabledCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetClosedLoopEnabled() {
    return HALSIM_GetPCMClosedLoopEnabled(m_index);
  }
  void SetClosedLoopEnabled(bool closedLoopEnabled) {
    HALSIM_SetPCMClosedLoopEnabled(m_index, closedLoopEnabled);
  }

  CallbackUniquePtr RegisterPressureSwitchCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPCMPressureSwitchCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPCMPressureSwitchCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetPressureSwitch() {
    return HALSIM_GetPCMPressureSwitch(m_index);
  }
  void SetPressureSwitch(bool pressureSwitch) {
    HALSIM_SetPCMPressureSwitch(m_index, pressureSwitch);
  }

  CallbackUniquePtr RegisterCompressorCurrentCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPCMCompressorCurrentCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPCMCompressorCurrentCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
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
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
