package edu.wpi.first.hal.sim;

import edu.wpi.first.wpilibj.hal.JNIWrapper;

public class AccelerometerSim extends JNIWrapper {
  public static native void resetData(int index);
  public static native int registerActiveCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelActiveCallback(int index, int uid);
  public static native boolean getActive(int index);
  public static native void setActive(int index, boolean active);
}
