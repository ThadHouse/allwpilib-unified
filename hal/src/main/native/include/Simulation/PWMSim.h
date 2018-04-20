#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/PWMData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class PWMSim {
 public:
  PWMSim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterInitializedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPWMInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPWMInitializedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetInitialized() {
    return HALSIM_GetPWMInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetPWMInitialized(m_index, initialized);
  }

  CallbackUniquePtr RegisterRawValueCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPWMRawValueCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPWMRawValueCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int GetRawValue() {
    return HALSIM_GetPWMRawValue(m_index);
  }
  void SetRawValue(int rawValue) {
    HALSIM_SetPWMRawValue(m_index, rawValue);
  }

  CallbackUniquePtr RegisterSpeedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPWMSpeedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPWMSpeedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetSpeed() {
    return HALSIM_GetPWMSpeed(m_index);
  }
  void SetSpeed(double speed) {
    HALSIM_SetPWMSpeed(m_index, speed);
  }

  CallbackUniquePtr RegisterPositionCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPWMPositionCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPWMPositionCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetPosition() {
    return HALSIM_GetPWMPosition(m_index);
  }
  void SetPosition(double position) {
    HALSIM_SetPWMPosition(m_index, position);
  }

  CallbackUniquePtr RegisterPeriodScaleCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPWMPeriodScaleCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPWMPeriodScaleCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int GetPeriodScale() {
    return HALSIM_GetPWMPeriodScale(m_index);
  }
  void SetPeriodScale(int periodScale) {
    HALSIM_SetPWMPeriodScale(m_index, periodScale);
  }

  CallbackUniquePtr RegisterZeroLatchCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelPWMZeroLatchCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterPWMZeroLatchCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetZeroLatch() {
    return HALSIM_GetPWMZeroLatch(m_index);
  }
  void SetZeroLatch(bool zeroLatch) {
    HALSIM_SetPWMZeroLatch(m_index, zeroLatch);
  }

  void ResetData() {
    HALSIM_ResetPWMData(m_index);
  }
 private:
  int m_index;
};
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
