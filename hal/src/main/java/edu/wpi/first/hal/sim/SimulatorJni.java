package edu.wpi.first.hal.sim;

import edu.wpi.first.wpilibj.hal.JNIWrapper;

public class SimulatorJni extends JNIWrapper {
  public static native void waitForProgramStart();
  public static native void setProgramStarted();
  public static native void restartTiming();
  public static native void resetHandles();
}
