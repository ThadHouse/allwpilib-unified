#pragma once

#include "MockData/EncoderData.h"

namespace frc {
namespace sim {
class EncoderSim {
 public:
  EncoderSim(int index) {
    m_index = index;
  }

  int RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterEncoderInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedCallback(int uid) {
    HALSIM_CancelEncoderInitializedCallback(m_index, uid);
  }
  bool GetInitialized() {
    return HALSIM_GetEncoderInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetEncoderInitialized(m_index, initialized);
  }

  int RegisterCountCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterEncoderCountCallback(m_index, callback, param, initialNotify);
  }
  void CancelCountCallback(int uid) {
    HALSIM_CancelEncoderCountCallback(m_index, uid);
  }
  int GetCount() {
    return HALSIM_GetEncoderCount(m_index);
  }
  void SetCount(int count) {
    HALSIM_SetEncoderCount(m_index, count);
  }

  int RegisterPeriodCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterEncoderPeriodCallback(m_index, callback, param, initialNotify);
  }
  void CancelPeriodCallback(int uid) {
    HALSIM_CancelEncoderPeriodCallback(m_index, uid);
  }
  double GetPeriod() {
    return HALSIM_GetEncoderPeriod(m_index);
  }
  void SetPeriod(double period) {
    HALSIM_SetEncoderPeriod(m_index, period);
  }

  int RegisterResetCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterEncoderResetCallback(m_index, callback, param, initialNotify);
  }
  void CancelResetCallback(int uid) {
    HALSIM_CancelEncoderResetCallback(m_index, uid);
  }
  bool GetReset() {
    return HALSIM_GetEncoderReset(m_index);
  }
  void SetReset(bool reset) {
    HALSIM_SetEncoderReset(m_index, reset);
  }

  int RegisterMaxPeriodCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterEncoderMaxPeriodCallback(m_index, callback, param, initialNotify);
  }
  void CancelMaxPeriodCallback(int uid) {
    HALSIM_CancelEncoderMaxPeriodCallback(m_index, uid);
  }
  double GetMaxPeriod() {
    return HALSIM_GetEncoderMaxPeriod(m_index);
  }
  void SetMaxPeriod(double maxPeriod) {
    HALSIM_SetEncoderMaxPeriod(m_index, maxPeriod);
  }

  int RegisterDirectionCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterEncoderDirectionCallback(m_index, callback, param, initialNotify);
  }
  void CancelDirectionCallback(int uid) {
    HALSIM_CancelEncoderDirectionCallback(m_index, uid);
  }
  bool GetDirection() {
    return HALSIM_GetEncoderDirection(m_index);
  }
  void SetDirection(bool direction) {
    HALSIM_SetEncoderDirection(m_index, direction);
  }

  int RegisterReverseDirectionCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterEncoderReverseDirectionCallback(m_index, callback, param, initialNotify);
  }
  void CancelReverseDirectionCallback(int uid) {
    HALSIM_CancelEncoderReverseDirectionCallback(m_index, uid);
  }
  bool GetReverseDirection() {
    return HALSIM_GetEncoderReverseDirection(m_index);
  }
  void SetReverseDirection(bool reverseDirection) {
    HALSIM_SetEncoderReverseDirection(m_index, reverseDirection);
  }

  int RegisterSamplesToAverageCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterEncoderSamplesToAverageCallback(m_index, callback, param, initialNotify);
  }
  void CancelSamplesToAverageCallback(int uid) {
    HALSIM_CancelEncoderSamplesToAverageCallback(m_index, uid);
  }
  int GetSamplesToAverage() {
    return HALSIM_GetEncoderSamplesToAverage(m_index);
  }
  void SetSamplesToAverage(int samplesToAverage) {
    HALSIM_SetEncoderSamplesToAverage(m_index, samplesToAverage);
  }

  void ResetData() {
    HALSIM_ResetEncoderData(m_index);
  }
 private:
  int m_index;
};
}
}
