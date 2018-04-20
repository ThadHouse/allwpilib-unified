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

  bool wasTriggered = false;
  bool lastValue = false;

  auto cb = sim.RegisterActiveCallback([&](llvm::StringRef name, const HAL_Value* value){
    wasTriggered = true;
    lastValue = value->data.v_boolean;
  }, false);

  EXPECT_FALSE(wasTriggered);

  HAL_SetAccelerometerActive(true);

  EXPECT_TRUE(wasTriggered);
  EXPECT_TRUE(lastValue);
}

}
