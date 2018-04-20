#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/AnalogGyroData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class AnalogGyroSim {
 public:
  AnalogGyroSim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterAngleCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogGyroAngleCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogGyroAngleCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetAngle() {
    return HALSIM_GetAnalogGyroAngle(m_index);
  }
  void SetAngle(double angle) {
    HALSIM_SetAnalogGyroAngle(m_index, angle);
  }

  CallbackUniquePtr RegisterRateCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogGyroRateCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogGyroRateCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetRate() {
    return HALSIM_GetAnalogGyroRate(m_index);
  }
  void SetRate(double rate) {
    HALSIM_SetAnalogGyroRate(m_index, rate);
  }

  CallbackUniquePtr RegisterInitializedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogGyroInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogGyroInitializedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetInitialized() {
    return HALSIM_GetAnalogGyroInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetAnalogGyroInitialized(m_index, initialized);
  }

  void ResetData() {
    HALSIM_ResetAnalogGyroData(m_index);
  }
 private:
  int m_index;
};
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
