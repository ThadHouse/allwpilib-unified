#pragma once

#include "MockData/DriverStationData.h"

namespace frc {
namespace sim {
class DriverStationSim {
 public:

  int RegisterEnabledCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDriverStationEnabledCallback(callback, param, initialNotify);
  }
  void CancelEnabledCallback(int uid) {
    HALSIM_CancelDriverStationEnabledCallback(uid);
  }
  bool GetEnabled() {
    return HALSIM_GetDriverStationEnabled();
  }
  void SetEnabled(bool enabled) {
    HALSIM_SetDriverStationEnabled(enabled);
  }

  int RegisterAutonomousCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDriverStationAutonomousCallback(callback, param, initialNotify);
  }
  void CancelAutonomousCallback(int uid) {
    HALSIM_CancelDriverStationAutonomousCallback(uid);
  }
  bool GetAutonomous() {
    return HALSIM_GetDriverStationAutonomous();
  }
  void SetAutonomous(bool autonomous) {
    HALSIM_SetDriverStationAutonomous(autonomous);
  }

  int RegisterTestCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDriverStationTestCallback(callback, param, initialNotify);
  }
  void CancelTestCallback(int uid) {
    HALSIM_CancelDriverStationTestCallback(uid);
  }
  bool GetTest() {
    return HALSIM_GetDriverStationTest();
  }
  void SetTest(bool test) {
    HALSIM_SetDriverStationTest(test);
  }

  int RegisterEStopCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDriverStationEStopCallback(callback, param, initialNotify);
  }
  void CancelEStopCallback(int uid) {
    HALSIM_CancelDriverStationEStopCallback(uid);
  }
  bool GetEStop() {
    return HALSIM_GetDriverStationEStop();
  }
  void SetEStop(bool eStop) {
    HALSIM_SetDriverStationEStop(eStop);
  }

  int RegisterFmsAttachedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDriverStationFmsAttachedCallback(callback, param, initialNotify);
  }
  void CancelFmsAttachedCallback(int uid) {
    HALSIM_CancelDriverStationFmsAttachedCallback(uid);
  }
  bool GetFmsAttached() {
    return HALSIM_GetDriverStationFmsAttached();
  }
  void SetFmsAttached(bool fmsAttached) {
    HALSIM_SetDriverStationFmsAttached(fmsAttached);
  }

  int RegisterDsAttachedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterDriverStationDsAttachedCallback(callback, param, initialNotify);
  }
  void CancelDsAttachedCallback(int uid) {
    HALSIM_CancelDriverStationDsAttachedCallback(uid);
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
}
}
