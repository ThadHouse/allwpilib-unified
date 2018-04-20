#pragma once

#ifndef __FRC_ROBORIO__

#include "MockData/AnalogInData.h"
#include "CallbackStore.h"

namespace frc {
namespace sim {
class AnalogInSim {
 public:
  AnalogInSim(int index) {
    m_index = index;
  }

  CallbackUniquePtr RegisterInitializedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogInInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogInInitializedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetInitialized() {
    return HALSIM_GetAnalogInInitialized(m_index);
  }
  void SetInitialized(bool initialized) {
    HALSIM_SetAnalogInInitialized(m_index, initialized);
  }

  CallbackUniquePtr RegisterAverageBitsCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogInAverageBitsCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogInAverageBitsCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int GetAverageBits() {
    return HALSIM_GetAnalogInAverageBits(m_index);
  }
  void SetAverageBits(int averageBits) {
    HALSIM_SetAnalogInAverageBits(m_index, averageBits);
  }

  CallbackUniquePtr RegisterOversampleBitsCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogInOversampleBitsCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogInOversampleBitsCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int GetOversampleBits() {
    return HALSIM_GetAnalogInOversampleBits(m_index);
  }
  void SetOversampleBits(int oversampleBits) {
    HALSIM_SetAnalogInOversampleBits(m_index, oversampleBits);
  }

  CallbackUniquePtr RegisterVoltageCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogInVoltageCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogInVoltageCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  double GetVoltage() {
    return HALSIM_GetAnalogInVoltage(m_index);
  }
  void SetVoltage(double voltage) {
    HALSIM_SetAnalogInVoltage(m_index, voltage);
  }

  CallbackUniquePtr RegisterAccumulatorInitializedCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogInAccumulatorInitializedCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogInAccumulatorInitializedCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  bool GetAccumulatorInitialized() {
    return HALSIM_GetAnalogInAccumulatorInitialized(m_index);
  }
  void SetAccumulatorInitialized(bool accumulatorInitialized) {
    HALSIM_SetAnalogInAccumulatorInitialized(m_index, accumulatorInitialized);
  }

  CallbackUniquePtr RegisterAccumulatorValueCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogInAccumulatorValueCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogInAccumulatorValueCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int64_t GetAccumulatorValue() {
    return HALSIM_GetAnalogInAccumulatorValue(m_index);
  }
  void SetAccumulatorValue(int64_t accumulatorValue) {
    HALSIM_SetAnalogInAccumulatorValue(m_index, accumulatorValue);
  }

  CallbackUniquePtr RegisterAccumulatorCountCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogInAccumulatorCountCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogInAccumulatorCountCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int64_t GetAccumulatorCount() {
    return HALSIM_GetAnalogInAccumulatorCount(m_index);
  }
  void SetAccumulatorCount(int64_t accumulatorCount) {
    HALSIM_SetAnalogInAccumulatorCount(m_index, accumulatorCount);
  }

  CallbackUniquePtr RegisterAccumulatorCenterCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogInAccumulatorCenterCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogInAccumulatorCenterCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
  }
  int GetAccumulatorCenter() {
    return HALSIM_GetAnalogInAccumulatorCenter(m_index);
  }
  void SetAccumulatorCenter(int accumulatorCenter) {
    HALSIM_SetAnalogInAccumulatorCenter(m_index, accumulatorCenter);
  }

  CallbackUniquePtr RegisterAccumulatorDeadbandCallback(NotifyCallback callback, bool initialNotify) {
    CallbackUniquePtr store(new CallbackStore<CancelCallbackFunc>(m_index, -1, callback, &HALSIM_CancelAnalogInAccumulatorDeadbandCallback), &CallbackStoreCancel);
    store->uid = HALSIM_RegisterAnalogInAccumulatorDeadbandCallback(m_index, &CallbackStoreThunk, store.get(), initialNotify);
    return std::move(store);
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
} // namespace sim
} // namespace frc
#endif // __FRC_ROBORIO__
