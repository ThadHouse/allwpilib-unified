package edu.wpi.first.hal.sim;

public interface ConstBufferCallback {
  void callback(String name, byte[] buffer, int count);
}
