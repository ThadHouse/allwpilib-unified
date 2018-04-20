#include "HAL/Accelerometer.h"
#include "HAL/HAL.h"
#include "gtest/gtest.h"
#include "Simulation/AccelerometerSim.h"

using namespace frc::sim;

namespace hal {

TEST(AcclerometerSimTests, TestActiveCallback) {
  HAL_Initialize(500, 0);

  AccelerometerSim sim{0};

  sim.ResetData();

  auto store = std::make_pair(false, false);

  auto uid = sim.RegisterActiveCallback([](const char* name, void* param, const HAL_Value* value){
    std::pair<bool, bool>* store = reinterpret_cast<std::pair<bool,bool>*>(param);
    store->first = true;
    store->second = value->data.v_boolean;
  }, &store, false);

  bool wasTriggeredAfterRegister = store.first;
  HAL_SetAccelerometerActive(true);
  sim.CancelActiveCallback(uid);
  EXPECT_FALSE(wasTriggeredAfterRegister);
  EXPECT_TRUE(store.first);
  EXPECT_TRUE(store.second);
}

}
