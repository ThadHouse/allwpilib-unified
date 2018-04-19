package edu.wpi.first.hal.sim;

import edu.wpi.first.wpilibj.hal.JNIWrapper;

public class SPISim extends JNIWrapper {
  public static native int registerInitializedCallback(int index, NotifyCallback callback, boolean initialNotify);
  public static native void cancelInitializedCallback(int index, int uid);
  public static native boolean getInitialized(int index);
  public static native void setInitialized(int index, boolean initialized);

  public static native int registerReadCallback(int index, BufferCallback callback);
  public static native void cancelReadCallback(int index, int uid);

  public static native int registerWriteCallback(int index, ConstBufferCallback callback);
  public static native void cancelWriteCallback(int index, int uid);

  public static native int registerReadAutoReceiveBufferCallback(int index, SpiReadAutoReceiveBufferCallback callback);
  public static native void cancelReadAutoReceiveBufferCallback(int index, int uid);

  public static native void resetData(int index);
}
