#pragma once

#include "MockData/AnalogInData.h"

namespace frc {
namespace sim {
class AnalogInSim {
 public:
  AnalogInSim(int index) {
    m_index = index;
  }

  int RegisterInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogInInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelInitializedCallback(int uid) {
    HALSIM_CancelAnalogInInitializedCallback(m_index, uid);
  }
  bool GetInitialized() {
    return HALSIM_GetAnalogInInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetAnalogInInitialized(m_index, initialized);
  }

  int RegisterAverageBitsCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogInAverageBitsCallback(m_index, callback, param, initialNotify);
  }
  void CancelAverageBitsCallback(int uid) {
    HALSIM_CancelAnalogInAverageBitsCallback(m_index, uid);
  }
  int GetAverageBits() {
    return HALSIM_GetAnalogInAverageBits(m_index);
  }
  void SetAverageBits(int averageBits) {
    HALSIM_SetAnalogInAverageBits(m_index, averageBits);
  }

  int RegisterOversampleBitsCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogInOversampleBitsCallback(m_index, callback, param, initialNotify);
  }
  void CancelOversampleBitsCallback(int uid) {
    HALSIM_CancelAnalogInOversampleBitsCallback(m_index, uid);
  }
  int GetOversampleBits() {
    return HALSIM_GetAnalogInOversampleBits(m_index);
  }
  void SetOversampleBits(int oversampleBits) {
    HALSIM_SetAnalogInOversampleBits(m_index, oversampleBits);
  }

  int RegisterVoltageCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogInVoltageCallback(m_index, callback, param, initialNotify);
  }
  void CancelVoltageCallback(int uid) {
    HALSIM_CancelAnalogInVoltageCallback(m_index, uid);
  }
  double GetVoltage() {
    return HALSIM_GetAnalogInVoltage(m_index);
  }
  void SetVoltage(double voltage) {
    HALSIM_SetAnalogInVoltage(m_index, voltage);
  }

  int RegisterAccumulatorInitializedCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogInAccumulatorInitializedCallback(m_index, callback, param, initialNotify);
  }
  void CancelAccumulatorInitializedCallback(int uid) {
    HALSIM_CancelAnalogInAccumulatorInitializedCallback(m_index, uid);
  }
  bool GetAccumulatorInitialized() {
    return HALSIM_GetAnalogInAccumulatorInitialized(m_index);
  }
  void SetAccumulatorInitialized(bool accumulatorInitialized) {
    HALSIM_SetAnalogInAccumulatorInitialized(m_index, accumulatorInitialized);
  }

  int RegisterAccumulatorValueCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogInAccumulatorValueCallback(m_index, callback, param, initialNotify);
  }
  void CancelAccumulatorValueCallback(int uid) {
    HALSIM_CancelAnalogInAccumulatorValueCallback(m_index, uid);
  }
  int64_t GetAccumulatorValue() {
    return HALSIM_GetAnalogInAccumulatorValue(m_index);
  }
  void SetAccumulatorValue(int64_t accumulatorValue) {
    HALSIM_SetAnalogInAccumulatorValue(m_index, accumulatorValue);
  }

  int RegisterAccumulatorCountCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogInAccumulatorCountCallback(m_index, callback, param, initialNotify);
  }
  void CancelAccumulatorCountCallback(int uid) {
    HALSIM_CancelAnalogInAccumulatorCountCallback(m_index, uid);
  }
  int64_t GetAccumulatorCount() {
    return HALSIM_GetAnalogInAccumulatorCount(m_index);
  }
  void SetAccumulatorCount(int64_t accumulatorCount) {
    HALSIM_SetAnalogInAccumulatorCount(m_index, accumulatorCount);
  }

  int RegisterAccumulatorCenterCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogInAccumulatorCenterCallback(m_index, callback, param, initialNotify);
  }
  void CancelAccumulatorCenterCallback(int uid) {
    HALSIM_CancelAnalogInAccumulatorCenterCallback(m_index, uid);
  }
  int GetAccumulatorCenter() {
    return HALSIM_GetAnalogInAccumulatorCenter(m_index);
  }
  void SetAccumulatorCenter(int accumulatorCenter) {
    HALSIM_SetAnalogInAccumulatorCenter(m_index, accumulatorCenter);
  }

  int RegisterAccumulatorDeadbandCallback(HAL_NotifyCallback callback, void* param, bool initialNotify) {
    return HALSIM_RegisterAnalogInAccumulatorDeadbandCallback(m_index, callback, param, initialNotify);
  }
  void CancelAccumulatorDeadbandCallback(int uid) {
    HALSIM_CancelAnalogInAccumulatorDeadbandCallback(m_index, uid);
  }
  int GetAccumulatorDeadband() {
    return HALSIM_GetAnalogInAccumulatorDeadband(m_index);
  }
  void SetAccumulatorDeadband(int accumulatorDeadband) {
    HALSIM_SetAnalogInAccumulatorDeadband(m_index, accumulatorDeadband);
  }

  void ResetData() {
    HALSIM_ResetAnalogInData(m_index);
  }
 private:
  int m_index;
};
}
}
