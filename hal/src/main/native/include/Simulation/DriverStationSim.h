#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/DriverStationData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class DriverStationSim {
 public:
  NoIndexCallbackUniquePtr RegisterEnabledCallback(NotifyCallback callback, bool initialNotify) {
    NoIndexCallbackUniquePtr store(new CallbackStore<CancelCallbackNoIndexFunc>(-1, callback, &HALSIM_CancelDriverStationEnabledCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDriverStationEnabledCallback(&CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetEnabled() {
    return HALSIM_GetDriverStationEnabled();
  }
  void SetEnabled(bool enabled) {
    HALSIM_SetDriverStationEnabled(enabled);
  }

  NoIndexCallbackUniquePtr RegisterAutonomousCallback(NotifyCallback callback, bool initialNotify) {
    NoIndexCallbackUniquePtr store(new CallbackStore<CancelCallbackNoIndexFunc>(-1, callback, &HALSIM_CancelDriverStationAutonomousCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDriverStationAutonomousCallback(&CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetAutonomous() {
    return HALSIM_GetDriverStationAutonomous();
  }
  void SetAutonomous(bool autonomous) {
    HALSIM_SetDriverStationAutonomous(autonomous);
  }

  NoIndexCallbackUniquePtr RegisterTestCallback(NotifyCallback callback, bool initialNotify) {
    NoIndexCallbackUniquePtr store(new CallbackStore<CancelCallbackNoIndexFunc>(-1, callback, &HALSIM_CancelDriverStationTestCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDriverStationTestCallback(&CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetTest() {
    return HALSIM_GetDriverStationTest();
  }
  void SetTest(bool test) {
    HALSIM_SetDriverStationTest(test);
  }

  NoIndexCallbackUniquePtr RegisterEStopCallback(NotifyCallback callback, bool initialNotify) {
    NoIndexCallbackUniquePtr store(new CallbackStore<CancelCallbackNoIndexFunc>(-1, callback, &HALSIM_CancelDriverStationEStopCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDriverStationEStopCallback(&CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetEStop() {
    return HALSIM_GetDriverStationEStop();
  }
  void SetEStop(bool eStop) {
    HALSIM_SetDriverStationEStop(eStop);
  }

  NoIndexCallbackUniquePtr RegisterFmsAttachedCallback(NotifyCallback callback, bool initialNotify) {
    NoIndexCallbackUniquePtr store(new CallbackStore<CancelCallbackNoIndexFunc>(-1, callback, &HALSIM_CancelDriverStationFmsAttachedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDriverStationFmsAttachedCallback(&CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetFmsAttached() {
    return HALSIM_GetDriverStationFmsAttached();
  }
  void SetFmsAttached(bool fmsAttached) {
    HALSIM_SetDriverStationFmsAttached(fmsAttached);
  }

  NoIndexCallbackUniquePtr RegisterDsAttachedCallback(NotifyCallback callback, bool initialNotify) {
    NoIndexCallbackUniquePtr store(new CallbackStore<CancelCallbackNoIndexFunc>(-1, callback, &HALSIM_CancelDriverStationDsAttachedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterDriverStationDsAttachedCallback(&CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetDsAttached() {
    return HALSIM_GetDriverStationDsAttached();
  }
  void SetDsAttached(bool dsAttached) {
    HALSIM_SetDriverStationDsAttached(dsAttached);
  }

  void ResetData() {
    HALSIM_ResetDriverStationData();
  }
};
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
