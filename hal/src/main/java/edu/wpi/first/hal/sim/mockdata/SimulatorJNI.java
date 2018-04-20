package edu.wpi.first.hal.sim.mockdata;

import edu.wpi.first.wpilibj.hal.JNIWrapper;

public class SimulatorJNI extends JNIWrapper {
  public static native void waitForProgramStart();
  public static native void setProgramStarted();
  public static native void restartTiming();
  public static native void resetHandles();
}
