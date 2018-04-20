#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/AnalogTriggerData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class AnalogTriggerSim {
 public:
  AnalogTriggerSim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterInitializedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogTriggerInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogTriggerInitializedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetInitialized() {
    return HALSIM_GetAnalogTriggerInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetAnalogTriggerInitialized(m_index, initialized);
  }

  CallbackUniquePtr RegisterTriggerLowerBoundCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogTriggerTriggerLowerBoundCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogTriggerTriggerLowerBoundCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetTriggerLowerBound() {
    return HALSIM_GetAnalogTriggerTriggerLowerBound(m_index);
  }
  void SetTriggerLowerBound(double triggerLowerBound) {
    HALSIM_SetAnalogTriggerTriggerLowerBound(m_index, triggerLowerBound);
  }

  CallbackUniquePtr RegisterTriggerUpperBoundCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogTriggerTriggerUpperBoundCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogTriggerTriggerUpperBoundCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
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
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
