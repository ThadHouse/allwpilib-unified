package edu.wpi.first.hal.sim;

import edu.wpi.first.wpilibj.hal.JNIWrapper;

public class SimulatorJni extends JNIWrapper {
  public static native boolean doSimThing();
  public static native void doSomeStupidReallyLongExcruciatingNAmeThatNobodyWouldEverDoWithAllTheArgumentsToo(int a, int b, Object c, String[] d, boolean h, float f);
  public static native Object objectReturn();
}
