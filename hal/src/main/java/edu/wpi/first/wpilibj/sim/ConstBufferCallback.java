package edu.wpi.first.wpilibj.sim;

public interface ConstBufferCallback {
  void callback(String name, byte[] buffer, int count);
}
