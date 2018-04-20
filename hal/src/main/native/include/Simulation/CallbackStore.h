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

struct CallbackStore {
  CallbackStore(int32_t i, int32_t u, NotifyCallback cb, CancelCallbackFunc ccf) {
    index = i;
    uid = u;
    callback = cb;
    cancelCallback = ccf;
  }
  int32_t index;
  int32_t uid;
  NotifyCallback callback;
  CancelCallbackFunc cancelCallback;
};

using CallbackUniquePtr = std::unique_ptr<CallbackStore, void(*)(CallbackStore*)>;

void CallbackStoreThunk(const char* name, void* param, const HAL_Value* value);
void CallbackStoreCancel(CallbackStore* store);

}
}

#endif
