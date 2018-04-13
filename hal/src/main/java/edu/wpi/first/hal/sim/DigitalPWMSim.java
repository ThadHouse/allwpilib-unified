package edu.wpi.first.hal.sim;

import edu.wpi.first.wpilibj.hal.JNIWrapper;

public class DigitalPWMSim extends JNIWrapper {
  public static native int registerInitializedCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelInitializedCallback(int index, int uid);
  public static native boolean getInitialized(int index);
  public static native void setInitialized(int index, boolean initialized);

  public static native int registerDutyCycleCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelDutyCycleCallback(int index, int uid);
  public static native double getDutyCycle(int index);
  public static native void setDutyCycle(int index, double dutyCycle);

  public static native int registerPinCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelPinCallback(int index, int uid);
  public static native int getPin(int index);
  public static native void setPin(int index, int pin);

  public static native void resetData(int index);
}
