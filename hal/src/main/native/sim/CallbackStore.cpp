#include "Simulation/CallbackStore.h"

void frc::sim::CallbackStoreThunk(const char* name, void* param, const HAL_Value* value) {
  reinterpret_cast<CallbackStore*>(param)->callback(name, value);
}

/*
void frc::sim::CallbackStoreCancel(CallbackStore<CancelCallbackFunc>* store) {
  if (store->uid >= 0) {
    store->cancelCallback(store->index, store->uid);
  }
  delete store;
}

void frc::sim::CallbackStoreCancel(CallbackStore<CancelCallbackChannelFunc>* store) {
  if (store->uid >= 0) {
    store->cancelCallback(store->index, store->channel, store->uid);
  }
  delete store;
}
void frc::sim::CallbackStoreCancel(CallbackStore<CancelCallbackNoIndexFunc>* store) {
  if (store->uid >= 0) {
    store->cancelCallback(store->uid);
  }
  delete store;
}
*/
