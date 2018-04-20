#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/RelayData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class RelaySim {
 public:
  RelaySim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterInitializedForwardCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRelayInitializedForwardCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRelayInitializedForwardCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetInitializedForward() {
    return HALSIM_GetRelayInitializedForward(m_index);
  }
  void SetInitializedForward(bool initializedForward) {
    HALSIM_SetRelayInitializedForward(m_index, initializedForward);
  }

  CallbackUniquePtr RegisterInitializedReverseCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRelayInitializedReverseCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRelayInitializedReverseCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetInitializedReverse() {
    return HALSIM_GetRelayInitializedReverse(m_index);
  }
  void SetInitializedReverse(bool initializedReverse) {
    HALSIM_SetRelayInitializedReverse(m_index, initializedReverse);
  }

  CallbackUniquePtr RegisterForwardCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRelayForwardCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRelayForwardCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetForward() {
    return HALSIM_GetRelayForward(m_index);
  }
  void SetForward(bool forward) {
    HALSIM_SetRelayForward(m_index, forward);
  }

  CallbackUniquePtr RegisterReverseCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRelayReverseCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRelayReverseCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetReverse() {
    return HALSIM_GetRelayReverse(m_index);
  }
  void SetReverse(bool reverse) {
    HALSIM_SetRelayReverse(m_index, reverse);
  }

  void ResetData() {
    HALSIM_ResetRelayData(m_index);
  }
 private:
  int m_index;
};
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
