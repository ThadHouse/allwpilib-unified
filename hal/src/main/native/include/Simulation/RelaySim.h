#pragma once

#include "MockData/RelayData.h"

namespace frc {
namespace sim {
class RelaySim {
 public:
  RelaySim(int index) {
    m_index = index;
  }

  int RegisterInitializedForwardCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRelayInitializedForwardCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedForwardCallback(int uid) {
    HALSIM_CancelRelayInitializedForwardCallback(m_index, uid);
  }
  bool GetInitializedForward() {
    return HALSIM_GetRelayInitializedForward(m_index);
  }
  void SetInitializedForward(bool initializedForward) {
    HALSIM_SetRelayInitializedForward(m_index, initializedForward);
  }

  int RegisterInitializedReverseCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRelayInitializedReverseCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedReverseCallback(int uid) {
    HALSIM_CancelRelayInitializedReverseCallback(m_index, uid);
  }
  bool GetInitializedReverse() {
    return HALSIM_GetRelayInitializedReverse(m_index);
  }
  void SetInitializedReverse(bool initializedReverse) {
    HALSIM_SetRelayInitializedReverse(m_index, initializedReverse);
  }

  int RegisterForwardCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRelayForwardCallback(m_index, callback, param, initialNotify);
  }
  void CancelForwardCallback(int uid) {
    HALSIM_CancelRelayForwardCallback(m_index, uid);
  }
  bool GetForward() {
    return HALSIM_GetRelayForward(m_index);
  }
  void SetForward(bool forward) {
    HALSIM_SetRelayForward(m_index, forward);
  }

  int RegisterReverseCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRelayReverseCallback(m_index, callback, param, initialNotify);
  }
  void CancelReverseCallback(int uid) {
    HALSIM_CancelRelayReverseCallback(m_index, uid);
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
}
}
