#pragma once

#include "MockData/RoboRioData.h"

namespace frc {
namespace sim {
class RoboRioSim {
 public:
  RoboRioSim(int index) {
    m_index = index;
  }

  int RegisterFPGAButtonCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioFPGAButtonCallback(m_index, callback, param, initialNotify);
  }
  void CancelFPGAButtonCallback(int uid) {
    HALSIM_CancelRoboRioFPGAButtonCallback(m_index, uid);
  }
  bool GetFPGAButton() {
    return HALSIM_GetRoboRioFPGAButton(m_index);
  }
  void SetFPGAButton(bool fPGAButton) {
    HALSIM_SetRoboRioFPGAButton(m_index, fPGAButton);
  }

  int RegisterVInVoltageCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioVInVoltageCallback(m_index, callback, param, initialNotify);
  }
  void CancelVInVoltageCallback(int uid) {
    HALSIM_CancelRoboRioVInVoltageCallback(m_index, uid);
  }
  double GetVInVoltage() {
    return HALSIM_GetRoboRioVInVoltage(m_index);
  }
  void SetVInVoltage(double vInVoltage) {
    HALSIM_SetRoboRioVInVoltage(m_index, vInVoltage);
  }

  int RegisterVInCurrentCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioVInCurrentCallback(m_index, callback, param, initialNotify);
  }
  void CancelVInCurrentCallback(int uid) {
    HALSIM_CancelRoboRioVInCurrentCallback(m_index, uid);
  }
  double GetVInCurrent() {
    return HALSIM_GetRoboRioVInCurrent(m_index);
  }
  void SetVInCurrent(double vInCurrent) {
    HALSIM_SetRoboRioVInCurrent(m_index, vInCurrent);
  }

  int RegisterUserVoltage6VCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserVoltage6VCallback(m_index, callback, param, initialNotify);
  }
  void CancelUserVoltage6VCallback(int uid) {
    HALSIM_CancelRoboRioUserVoltage6VCallback(m_index, uid);
  }
  double GetUserVoltage6V() {
    return HALSIM_GetRoboRioUserVoltage6V(m_index);
  }
  void SetUserVoltage6V(double userVoltage6V) {
    HALSIM_SetRoboRioUserVoltage6V(m_index, userVoltage6V);
  }

  int RegisterUserCurrent6VCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserCurrent6VCallback(m_index, callback, param, initialNotify);
  }
  void CancelUserCurrent6VCallback(int uid) {
    HALSIM_CancelRoboRioUserCurrent6VCallback(m_index, uid);
  }
  double GetUserCurrent6V() {
    return HALSIM_GetRoboRioUserCurrent6V(m_index);
  }
  void SetUserCurrent6V(double userCurrent6V) {
    HALSIM_SetRoboRioUserCurrent6V(m_index, userCurrent6V);
  }

  int RegisterUserActive6VCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserActive6VCallback(m_index, callback, param, initialNotify);
  }
  void CancelUserActive6VCallback(int uid) {
    HALSIM_CancelRoboRioUserActive6VCallback(m_index, uid);
  }
  bool GetUserActive6V() {
    return HALSIM_GetRoboRioUserActive6V(m_index);
  }
  void SetUserActive6V(bool userActive6V) {
    HALSIM_SetRoboRioUserActive6V(m_index, userActive6V);
  }

  int RegisterUserVoltage5VCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserVoltage5VCallback(m_index, callback, param, initialNotify);
  }
  void CancelUserVoltage5VCallback(int uid) {
    HALSIM_CancelRoboRioUserVoltage5VCallback(m_index, uid);
  }
  double GetUserVoltage5V() {
    return HALSIM_GetRoboRioUserVoltage5V(m_index);
  }
  void SetUserVoltage5V(double userVoltage5V) {
    HALSIM_SetRoboRioUserVoltage5V(m_index, userVoltage5V);
  }

  int RegisterUserCurrent5VCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserCurrent5VCallback(m_index, callback, param, initialNotify);
  }
  void CancelUserCurrent5VCallback(int uid) {
    HALSIM_CancelRoboRioUserCurrent5VCallback(m_index, uid);
  }
  double GetUserCurrent5V() {
    return HALSIM_GetRoboRioUserCurrent5V(m_index);
  }
  void SetUserCurrent5V(double userCurrent5V) {
    HALSIM_SetRoboRioUserCurrent5V(m_index, userCurrent5V);
  }

  int RegisterUserActive5VCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserActive5VCallback(m_index, callback, param, initialNotify);
  }
  void CancelUserActive5VCallback(int uid) {
    HALSIM_CancelRoboRioUserActive5VCallback(m_index, uid);
  }
  bool GetUserActive5V() {
    return HALSIM_GetRoboRioUserActive5V(m_index);
  }
  void SetUserActive5V(bool userActive5V) {
    HALSIM_SetRoboRioUserActive5V(m_index, userActive5V);
  }

  int RegisterUserVoltage3V3Callback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserVoltage3V3Callback(m_index, callback, param, initialNotify);
  }
  void CancelUserVoltage3V3Callback(int uid) {
    HALSIM_CancelRoboRioUserVoltage3V3Callback(m_index, uid);
  }
  double GetUserVoltage3V3() {
    return HALSIM_GetRoboRioUserVoltage3V3(m_index);
  }
  void SetUserVoltage3V3(double userVoltage3V3) {
    HALSIM_SetRoboRioUserVoltage3V3(m_index, userVoltage3V3);
  }

  int RegisterUserCurrent3V3Callback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserCurrent3V3Callback(m_index, callback, param, initialNotify);
  }
  void CancelUserCurrent3V3Callback(int uid) {
    HALSIM_CancelRoboRioUserCurrent3V3Callback(m_index, uid);
  }
  double GetUserCurrent3V3() {
    return HALSIM_GetRoboRioUserCurrent3V3(m_index);
  }
  void SetUserCurrent3V3(double userCurrent3V3) {
    HALSIM_SetRoboRioUserCurrent3V3(m_index, userCurrent3V3);
  }

  int RegisterUserActive3V3Callback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserActive3V3Callback(m_index, callback, param, initialNotify);
  }
  void CancelUserActive3V3Callback(int uid) {
    HALSIM_CancelRoboRioUserActive3V3Callback(m_index, uid);
  }
  bool GetUserActive3V3() {
    return HALSIM_GetRoboRioUserActive3V3(m_index);
  }
  void SetUserActive3V3(bool userActive3V3) {
    HALSIM_SetRoboRioUserActive3V3(m_index, userActive3V3);
  }

  int RegisterUserFaults6VCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserFaults6VCallback(m_index, callback, param, initialNotify);
  }
  void CancelUserFaults6VCallback(int uid) {
    HALSIM_CancelRoboRioUserFaults6VCallback(m_index, uid);
  }
  int GetUserFaults6V() {
    return HALSIM_GetRoboRioUserFaults6V(m_index);
  }
  void SetUserFaults6V(int userFaults6V) {
    HALSIM_SetRoboRioUserFaults6V(m_index, userFaults6V);
  }

  int RegisterUserFaults5VCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserFaults5VCallback(m_index, callback, param, initialNotify);
  }
  void CancelUserFaults5VCallback(int uid) {
    HALSIM_CancelRoboRioUserFaults5VCallback(m_index, uid);
  }
  int GetUserFaults5V() {
    return HALSIM_GetRoboRioUserFaults5V(m_index);
  }
  void SetUserFaults5V(int userFaults5V) {
    HALSIM_SetRoboRioUserFaults5V(m_index, userFaults5V);
  }

  int RegisterUserFaults3V3Callback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterRoboRioUserFaults3V3Callback(m_index, callback, param, initialNotify);
  }
  void CancelUserFaults3V3Callback(int uid) {
    HALSIM_CancelRoboRioUserFaults3V3Callback(m_index, uid);
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
}
}
