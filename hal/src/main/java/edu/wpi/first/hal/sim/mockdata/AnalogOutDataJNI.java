package edu.wpi.first.hal.sim.mockdata;

import edu.wpi.first.hal.sim.NotifyCallback;
import edu.wpi.first.wpilibj.hal.JNIWrapper;

public class AnalogOutDataJNI extends JNIWrapper {
  public static native int registerVoltageCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelVoltageCallback(int index, int uid);
  public static native double getVoltage(int index);
  public static native void setVoltage(int index, double voltage);

  public static native int registerInitializedCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelInitializedCallback(int index, int uid);
  public static native boolean getInitialized(int index);
  public static native void setInitialized(int index, boolean initialized);

  public static native void resetData(int index);
}
