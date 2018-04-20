#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/AnalogOutData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class AnalogOutSim {
 public:
  AnalogOutSim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterVoltageCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogOutVoltageCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogOutVoltageCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetVoltage() {
    return HALSIM_GetAnalogOutVoltage(m_index);
  }
  void SetVoltage(double voltage) {
    HALSIM_SetAnalogOutVoltage(m_index, voltage);
  }

  CallbackUniquePtr RegisterInitializedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogOutInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogOutInitializedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
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
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
