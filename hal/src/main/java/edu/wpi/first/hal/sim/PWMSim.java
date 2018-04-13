package edu.wpi.first.hal.sim;

import edu.wpi.first.wpilibj.hal.JNIWrapper;

public class PWMSim extends JNIWrapper {
  public static native int registerInitializedCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelInitializedCallback(int index, int uid);
  public static native boolean getInitialized(int index);
  public static native void setInitialized(int index, boolean initialized);

  public static native int registerRawValueCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelRawValueCallback(int index, int uid);
  public static native int getRawValue(int index);
  public static native void setRawValue(int index, int rawValue);

  public static native int registerSpeedCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelSpeedCallback(int index, int uid);
  public static native double getSpeed(int index);
  public static native void setSpeed(int index, double speed);

  public static native int registerPositionCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelPositionCallback(int index, int uid);
  public static native double getPosition(int index);
  public static native void setPosition(int index, double position);

  public static native int registerPeriodScaleCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelPeriodScaleCallback(int index, int uid);
  public static native int getPeriodScale(int index);
  public static native void setPeriodScale(int index, int periodScale);

  public static native int registerZeroLatchCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelZeroLatchCallback(int index, int uid);
  public static native boolean getZeroLatch(int index);
  public static native void setZeroLatch(int index, boolean zeroLatch);

  public static native void resetData(int index);
}
