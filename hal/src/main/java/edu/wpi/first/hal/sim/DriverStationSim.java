package edu.wpi.first.hal.sim;

import edu.wpi.first.wpilibj.hal.JNIWrapper;
import edu.wpi.first.wpilibj.hal.MatchInfoData;

public class DriverStationSim extends JNIWrapper {
  public static native int registerEnabledCallback(NotifyCallback callback, boolean initialNotify);
  public static native void cancelEnabledCallback(int uid);
  public static native boolean getEnabled();
  public static native void setEnabled(boolean enabled);

  public static native int registerAutonomousCallback(NotifyCallback callback, boolean initialNotify);
  public static native void cancelAutonomousCallback(int uid);
  public static native boolean getAutonomous();
  public static native void setAutonomous(boolean autonomous);

  public static native int registerTestCallback(NotifyCallback callback, boolean initialNotify);
  public static native void cancelTestCallback(int uid);
  public static native boolean getTest();
  public static native void setTest(boolean test);

  public static native int registerEStopCallback(NotifyCallback callback, boolean initialNotify);
  public static native void cancelEStopCallback(int uid);
  public static native boolean getEStop();
  public static native void setEStop(boolean eStop);

  public static native int registerFmsAttachedCallback(NotifyCallback callback, boolean initialNotify);
  public static native void cancelFmsAttachedCallback(int uid);
  public static native boolean getFmsAttached();
  public static native void setFmsAttached(boolean fmsAttached);

  public static native int registerDsAttachedCallback(NotifyCallback callback, boolean initialNotify);
  public static native void cancelDsAttachedCallback(int uid);
  public static native boolean getDsAttached();
  public static native void setDsAttached(boolean dsAttached);

  public static native void setJoystickAxes(byte joystickNum, float[] axesArray);
  public static native void setJoystickPOVs(byte joystickNum, short[] povsArray);
  public static native void setJoystickButtons(byte joystickNum, int buttons, int count);

  public static native void setMatchInfo(MatchInfoData info);
  public static native void registerAllCallbacks(NotifyCallback callback, boolean initialNotify);
  public static native void notifyNewData();

  public static native void resetData();
}