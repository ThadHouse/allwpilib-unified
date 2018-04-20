#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/AccelerometerData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class AccelerometerSim {
 public:
  AccelerometerSim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterActiveCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAccelerometerActiveCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAccelerometerActiveCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetActive() {
    return HALSIM_GetAccelerometerActive(m_index);
  }
  void SetActive(bool active) {
    HALSIM_SetAccelerometerActive(m_index, active);
  }

  CallbackUniquePtr RegisterRangeCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAccelerometerRangeCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAccelerometerRangeCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  HAL_AccelerometerRange GetRange() {
    return HALSIM_GetAccelerometerRange(m_index);
  }
  void SetRange(HAL_AccelerometerRange range) {
    HALSIM_SetAccelerometerRange(m_index, range);
  }

  CallbackUniquePtr RegisterXCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAccelerometerXCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAccelerometerXCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetX() {
    return HALSIM_GetAccelerometerX(m_index);
  }
  void SetX(double x) {
    HALSIM_SetAccelerometerX(m_index, x);
  }

  CallbackUniquePtr RegisterYCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAccelerometerYCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAccelerometerYCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetY() {
    return HALSIM_GetAccelerometerY(m_index);
  }
  void SetY(double y) {
    HALSIM_SetAccelerometerY(m_index, y);
  }

  CallbackUniquePtr RegisterZCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAccelerometerZCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAccelerometerZCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetZ() {
    return HALSIM_GetAccelerometerZ(m_index);
  }
  void SetZ(double z) {
    HALSIM_SetAccelerometerZ(m_index, z);
  }

  void ResetData() {
    HALSIM_ResetAccelerometerData(m_index);
  }
 private:
  int m_index;
};
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
