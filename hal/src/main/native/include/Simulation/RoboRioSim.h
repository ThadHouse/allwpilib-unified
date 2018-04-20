#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/RoboRioData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class RoboRioSim {
 public:
  RoboRioSim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterFPGAButtonCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioFPGAButtonCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioFPGAButtonCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetFPGAButton() {
    return HALSIM_GetRoboRioFPGAButton(m_index);
  }
  void SetFPGAButton(bool fPGAButton) {
    HALSIM_SetRoboRioFPGAButton(m_index, fPGAButton);
  }

  CallbackUniquePtr RegisterVInVoltageCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioVInVoltageCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioVInVoltageCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetVInVoltage() {
    return HALSIM_GetRoboRioVInVoltage(m_index);
  }
  void SetVInVoltage(double vInVoltage) {
    HALSIM_SetRoboRioVInVoltage(m_index, vInVoltage);
  }

  CallbackUniquePtr RegisterVInCurrentCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioVInCurrentCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioVInCurrentCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetVInCurrent() {
    return HALSIM_GetRoboRioVInCurrent(m_index);
  }
  void SetVInCurrent(double vInCurrent) {
    HALSIM_SetRoboRioVInCurrent(m_index, vInCurrent);
  }

  CallbackUniquePtr RegisterUserVoltage6VCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserVoltage6VCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserVoltage6VCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetUserVoltage6V() {
    return HALSIM_GetRoboRioUserVoltage6V(m_index);
  }
  void SetUserVoltage6V(double userVoltage6V) {
    HALSIM_SetRoboRioUserVoltage6V(m_index, userVoltage6V);
  }

  CallbackUniquePtr RegisterUserCurrent6VCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserCurrent6VCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserCurrent6VCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetUserCurrent6V() {
    return HALSIM_GetRoboRioUserCurrent6V(m_index);
  }
  void SetUserCurrent6V(double userCurrent6V) {
    HALSIM_SetRoboRioUserCurrent6V(m_index, userCurrent6V);
  }

  CallbackUniquePtr RegisterUserActive6VCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserActive6VCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserActive6VCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetUserActive6V() {
    return HALSIM_GetRoboRioUserActive6V(m_index);
  }
  void SetUserActive6V(bool userActive6V) {
    HALSIM_SetRoboRioUserActive6V(m_index, userActive6V);
  }

  CallbackUniquePtr RegisterUserVoltage5VCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserVoltage5VCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserVoltage5VCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetUserVoltage5V() {
    return HALSIM_GetRoboRioUserVoltage5V(m_index);
  }
  void SetUserVoltage5V(double userVoltage5V) {
    HALSIM_SetRoboRioUserVoltage5V(m_index, userVoltage5V);
  }

  CallbackUniquePtr RegisterUserCurrent5VCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserCurrent5VCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserCurrent5VCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetUserCurrent5V() {
    return HALSIM_GetRoboRioUserCurrent5V(m_index);
  }
  void SetUserCurrent5V(double userCurrent5V) {
    HALSIM_SetRoboRioUserCurrent5V(m_index, userCurrent5V);
  }

  CallbackUniquePtr RegisterUserActive5VCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserActive5VCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserActive5VCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetUserActive5V() {
    return HALSIM_GetRoboRioUserActive5V(m_index);
  }
  void SetUserActive5V(bool userActive5V) {
    HALSIM_SetRoboRioUserActive5V(m_index, userActive5V);
  }

  CallbackUniquePtr RegisterUserVoltage3V3Callback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserVoltage3V3Callback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserVoltage3V3Callback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetUserVoltage3V3() {
    return HALSIM_GetRoboRioUserVoltage3V3(m_index);
  }
  void SetUserVoltage3V3(double userVoltage3V3) {
    HALSIM_SetRoboRioUserVoltage3V3(m_index, userVoltage3V3);
  }

  CallbackUniquePtr RegisterUserCurrent3V3Callback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserCurrent3V3Callback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserCurrent3V3Callback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetUserCurrent3V3() {
    return HALSIM_GetRoboRioUserCurrent3V3(m_index);
  }
  void SetUserCurrent3V3(double userCurrent3V3) {
    HALSIM_SetRoboRioUserCurrent3V3(m_index, userCurrent3V3);
  }

  CallbackUniquePtr RegisterUserActive3V3Callback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserActive3V3Callback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserActive3V3Callback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetUserActive3V3() {
    return HALSIM_GetRoboRioUserActive3V3(m_index);
  }
  void SetUserActive3V3(bool userActive3V3) {
    HALSIM_SetRoboRioUserActive3V3(m_index, userActive3V3);
  }

  CallbackUniquePtr RegisterUserFaults6VCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserFaults6VCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserFaults6VCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int GetUserFaults6V() {
    return HALSIM_GetRoboRioUserFaults6V(m_index);
  }
  void SetUserFaults6V(int userFaults6V) {
    HALSIM_SetRoboRioUserFaults6V(m_index, userFaults6V);
  }

  CallbackUniquePtr RegisterUserFaults5VCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserFaults5VCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserFaults5VCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int GetUserFaults5V() {
    return HALSIM_GetRoboRioUserFaults5V(m_index);
  }
  void SetUserFaults5V(int userFaults5V) {
    HALSIM_SetRoboRioUserFaults5V(m_index, userFaults5V);
  }

  CallbackUniquePtr RegisterUserFaults3V3Callback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelRoboRioUserFaults3V3Callback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterRoboRioUserFaults3V3Callback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int GetUserFaults3V3() {
    return HALSIM_GetRoboRioUserFaults3V3(m_index);
  }
  void SetUserFaults3V3(int userFaults3V3) {
    HALSIM_SetRoboRioUserFaults3V3(m_index, userFaults3V3);
  }

  void ResetData() {
    HALSIM_ResetRoboRioData(m_index);
  }
 private:
  int m_index;
};
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
