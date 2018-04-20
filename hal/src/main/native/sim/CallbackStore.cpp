#include "Simulation/CallbackStore.h"

void frc::sim::CallbackStoreThunk(const char* name, void* param, const HAL_Value* value) {
  reinterpret_cast<CallbackStore*>(param)->callback(name, value);
}
void frc::sim::CallbackStoreCancel(CallbackStore* store) {
  if (store->uid >= 0) {
    store->cancelCallback(store->index, store->uid);
  }
  delete store;
}
