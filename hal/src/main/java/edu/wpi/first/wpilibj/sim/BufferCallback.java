package edu.wpi.first.wpilibj.sim;

public interface BufferCallback {
  void callback(String name, byte[] buffer, int count);
}
