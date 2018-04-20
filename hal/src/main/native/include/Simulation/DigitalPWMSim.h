#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/DigitalPWMData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class DigitalPWMSim {
 public:
  DigitalPWMSim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterInitializedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelDigitalPWMInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDigitalPWMInitializedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetInitialized() {
    return HALSIM_GetDigitalPWMInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetDigitalPWMInitialized(m_index, initialized);
  }

  CallbackUniquePtr RegisterDutyCycleCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelDigitalPWMDutyCycleCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDigitalPWMDutyCycleCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetDutyCycle() {
    return HALSIM_GetDigitalPWMDutyCycle(m_index);
  }
  void SetDutyCycle(double dutyCycle) {
    HALSIM_SetDigitalPWMDutyCycle(m_index, dutyCycle);
  }

  CallbackUniquePtr RegisterPinCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelDigitalPWMPinCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDigitalPWMPinCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int GetPin() {
    return HALSIM_GetDigitalPWMPin(m_index);
  }
  void SetPin(int pin) {
    HALSIM_SetDigitalPWMPin(m_index, pin);
  }

  void ResetData() {
    HALSIM_ResetDigitalPWMData(m_index);
  }
 private:
  int m_index;
};
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
