package edu.wpi.first.hal.sim;

public interface BufferCallback {
  void callback(String name, byte[] buffer, int count);
}
