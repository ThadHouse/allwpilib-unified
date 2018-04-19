package edu.wpi.first.hal.sim;

public interface SpiReadAutoReceiveBufferCallback {
  int callback(String name, byte[] buffer, int numToRead);
}
