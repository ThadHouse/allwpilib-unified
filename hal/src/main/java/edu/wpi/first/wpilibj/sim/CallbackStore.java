package edu.wpi.first.wpilibj.sim;

import java.io.Closeable;
import java.io.IOException;

public class CallbackStore implements Closeable {
  public static interface CancelCallbackFunc {
    void cancel(int index, int uid);
  }

  public CallbackStore(int index, int uid, NotifyCallback cb, CancelCallbackFunc ccf) {
    this.index = index;
    this.uid = uid;
    this.callback = cb;
    this.cancelCallback = ccf;
  }

  public int index;
  public int uid;
  public NotifyCallback callback;
  CancelCallbackFunc cancelCallback;

  @Override
  public void close() throws IOException {
    if (cancelCallback != null) {
      cancelCallback.cancel(index, uid);
    }
  }

  @Override
  protected void finalize() throws Throwable {
    try {
        close();        // close open files
    } finally {
        super.finalize();
    }
  }
}
