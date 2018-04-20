#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/DIOData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class DIOSim {
 public:
  DIOSim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterInitializedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelDIOInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDIOInitializedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetInitialized() {
    return HALSIM_GetDIOInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetDIOInitialized(m_index, initialized);
  }

  CallbackUniquePtr RegisterValueCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelDIOValueCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDIOValueCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetValue() {
    return HALSIM_GetDIOValue(m_index);
  }
  void SetValue(bool value) {
    HALSIM_SetDIOValue(m_index, value);
  }

  CallbackUniquePtr RegisterPulseLengthCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelDIOPulseLengthCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDIOPulseLengthCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetPulseLength() {
    return HALSIM_GetDIOPulseLength(m_index);
  }
  void SetPulseLength(double pulseLength) {
    HALSIM_SetDIOPulseLength(m_index, pulseLength);
  }

  CallbackUniquePtr RegisterIsInputCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelDIOIsInputCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDIOIsInputCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetIsInput() {
    return HALSIM_GetDIOIsInput(m_index);
  }
  void SetIsInput(bool isInput) {
    HALSIM_SetDIOIsInput(m_index, isInput);
  }

  CallbackUniquePtr RegisterFilterIndexCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelDIOFilterIndexCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDIOFilterIndexCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int GetFilterIndex() {
    return HALSIM_GetDIOFilterIndex(m_index);
  }
  void SetFilterIndex(int filterIndex) {
    HALSIM_SetDIOFilterIndex(m_index, filterIndex);
  }

  void ResetData() {
    HALSIM_ResetDIOData(m_index);
  }
 private:
  int m_index;
};
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
