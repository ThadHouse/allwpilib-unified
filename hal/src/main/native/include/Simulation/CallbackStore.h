#pragma once

#ifndef __FRC_ROBORIO__

#include <functional>
#include <memory>
#include <llvm/StringRef.h>
#include "MockData/HAL_Value.h"

namespace frc {
namespace sim {

using NotifyCallback = std::function<void(llvm::StringRef, const HAL_Value*)>;
typedef void(*CancelCallbackFunc)(int32_t index, int32_t uid);
typedef void(*CancelCallbackNoIndexFunc)(int32_t uid);
typedef void(*CancelCallbackChannelFunc)(int32_t index, int32_t channel, int32_t uid);

struct CallbackStoreBase {
  NotifyCallback callback;
};

template<typename T>
struct CallbackStore : public CallbackStoreBase {
    CallbackStore(int32_t i, NotifyCallback cb, T ccf) {
    index = i;
    callback = cb;
    cancelCallback = ccf;
  }
  CallbackStore(int32_t i, int32_t u, NotifyCallback cb, T ccf) {
    index = i;
    uid = u;
    callback = cb;
    cancelCallback = ccf;
  }
  CallbackStore(int32_t i, int32_t c, int32_t u, NotifyCallback cb, T ccf) {
    index = i;
    channel = c;
    uid = u;
    callback = cb;
    cancelCallback = ccf;
  }
  int32_t index;
  int32_t channel;
  int32_t uid;
  T cancelCallback;
};

using CallbackUniquePtr = std::unique_ptr<CallbackStore<CancelCallbackFunc>, void(*)(CallbackStore<CancelCallbackFunc>*)>;
using ChannelCallbackUniquePtr = std::unique_ptr<CallbackStore<CancelCallbackChannelFunc>, void(*)(CallbackStore<CancelCallbackChannelFunc>*)>;
using NoIndexCallbackUniquePtr = std::unique_ptr<CallbackStore<CancelCallbackNoIndexFunc>, void(*)(CallbackStore<CancelCallbackNoIndexFunc>*)>;

void CallbackStoreThunk(const char* name, void* param, const HAL_Value* value);
void CallbackStoreCancel(CallbackStore<CancelCallbackFunc>* store);
void CallbackStoreCancel(CallbackStore<CancelCallbackChannelFunc>* store);
void CallbackStoreCancel(CallbackStore<CancelCallbackNoIndexFunc>* store);

}
}

#endif
