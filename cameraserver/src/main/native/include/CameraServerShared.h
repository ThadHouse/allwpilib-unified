#pragma once

#include "llvm/StringRef.h"
#include <thread>

namespace frc {

  typedef void (*ReportUsbCameraFunc)(int);
  typedef void (*ReportAxisCameraFunc)(int);
  typedef void (*ReportVideoServerFunc)(int);
  typedef void (*SetCameraServerErrorFunc)(llvm::StringRef);
  typedef void (*SetVisionRunnerErrorFunc)(llvm::StringRef);
  typedef void (*ReportDriverStationErrorFunc)(llvm::StringRef);
  typedef std::pair<std::thread::id, bool> (*GetRobotMainThreadIdFunc)();

  struct CameraServerShared {
    ReportUsbCameraFunc ReportUsbCamera;
    ReportAxisCameraFunc ReportAxisCamera;
    ReportVideoServerFunc ReportVideoServer;
    SetCameraServerErrorFunc SetCameraServerError;
    SetVisionRunnerErrorFunc SetVisionRunnerError;
    ReportDriverStationErrorFunc ReportDriverStationError;
    GetRobotMainThreadIdFunc GetRobotMainThreadId;
  };

  void SetCameraServerShared(const CameraServerShared& shared);
  const CameraServerShared& GetCameraServerShared();
}
