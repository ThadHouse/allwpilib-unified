#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/PDPData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class PDPSim {
 public:
  PDPSim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterInitializedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPDPInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPDPInitializedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetInitialized() {
    return HALSIM_GetPDPInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetPDPInitialized(m_index, initialized);
  }

  CallbackUniquePtr RegisterTemperatureCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPDPTemperatureCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPDPTemperatureCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetTemperature() {
    return HALSIM_GetPDPTemperature(m_index);
  }
  void SetTemperature(double temperature) {
    HALSIM_SetPDPTemperature(m_index, temperature);
  }

  CallbackUniquePtr RegisterVoltageCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPDPVoltageCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPDPVoltageCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetVoltage() {
    return HALSIM_GetPDPVoltage(m_index);
  }
  void SetVoltage(double voltage) {
    HALSIM_SetPDPVoltage(m_index, voltage);
  }

  ChannelCallbackUniquePtr RegisterCurrentCallback(int channel, NotifyCallback callback, bool initialNotify) {
    ChannelCallbackUniquePtr store(new CallbackStore<CancelCallbackChannelFunc>(m_index, channel, -1, callback, &HALSIM_CancelPDPCurrentCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPDPCurrentCallback(m_index, channel, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
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
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
