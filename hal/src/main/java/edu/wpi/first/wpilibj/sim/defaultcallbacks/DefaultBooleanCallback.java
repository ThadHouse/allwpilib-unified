package edu.wpi.first.wpilibj.sim.defaultcallbacks;

import java.io.Closeable;
import java.io.IOException;

import edu.wpi.first.wpilibj.sim.NotifyCallback;

public class DefaultBooleanCallback implements Closeable {
  public static interface CloseFunc {
    void close();
  }

  public final NotifyCallback callback;
  public CloseFunc closeFunc;
  public int triggerCount = 0;
  public boolean lastValue = false;

  public DefaultBooleanCallback() {
    callback = (s, v) -> {
      triggerCount++;
      lastValue = v.getBoolean();
    };
  }

  @Override
  public void close() throws IOException {
    if (closeFunc != null) {
      closeFunc.close();
    }
  }
}
