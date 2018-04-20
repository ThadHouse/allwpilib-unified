package edu.wpi.first.wpilibj.sim;

public interface SpiReadAutoReceiveBufferCallback {
  int callback(String name, byte[] buffer, int numToRead);
}
