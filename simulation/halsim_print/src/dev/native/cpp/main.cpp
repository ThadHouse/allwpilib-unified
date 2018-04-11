#include "HAL/HAL.h"
#include <thread>
#include <chrono>

int main() {
  HAL_Initialize(500, 0);
  std::this_thread::sleep_for(std::chrono::seconds(2));
}
