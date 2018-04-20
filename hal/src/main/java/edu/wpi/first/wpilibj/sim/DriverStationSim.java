package edu.wpi.first.wpilibj.sim;

import edu.wpi.first.hal.sim.mockdata.DriverStationDataJNI;

public class DriverStationSim {
  public int registerEnabledCallback(NotifyCallback callback, boolean initialNotify) {
    return DriverStationDataJNI.registerEnabledCallback(callback, initialNotify);
  }
  public void cancelEnabledCallback(int uid) {
    DriverStationDataJNI.cancelEnabledCallback(uid);
  }
  public boolean getEnabled() {
    return DriverStationDataJNI.getEnabled();
  }
  public void setEnabled(boolean enabled) {
    DriverStationDataJNI.setEnabled(enabled);
  }

  public int registerAutonomousCallback(NotifyCallback callback, boolean initialNotify) {
    return DriverStationDataJNI.registerAutonomousCallback(callback, initialNotify);
  }
  public void cancelAutonomousCallback(int uid) {
    DriverStationDataJNI.cancelAutonomousCallback(uid);
  }
  public boolean getAutonomous() {
    return DriverStationDataJNI.getAutonomous();
  }
  public void setAutonomous(boolean autonomous) {
    DriverStationDataJNI.setAutonomous(autonomous);
  }

  public int registerTestCallback(NotifyCallback callback, boolean initialNotify) {
    return DriverStationDataJNI.registerTestCallback(callback, initialNotify);
  }
  public void cancelTestCallback(int uid) {
    DriverStationDataJNI.cancelTestCallback(uid);
  }
  public boolean getTest() {
    return DriverStationDataJNI.getTest();
  }
  public void setTest(boolean test) {
    DriverStationDataJNI.setTest(test);
  }

  public int registerEStopCallback(NotifyCallback callback, boolean initialNotify) {
    return DriverStationDataJNI.registerEStopCallback(callback, initialNotify);
  }
  public void cancelEStopCallback(int uid) {
    DriverStationDataJNI.cancelEStopCallback(uid);
  }
  public boolean getEStop() {
    return DriverStationDataJNI.getEStop();
  }
  public void setEStop(boolean eStop) {
    DriverStationDataJNI.setEStop(eStop);
  }

  public int registerFmsAttachedCallback(NotifyCallback callback, boolean initialNotify) {
    return DriverStationDataJNI.registerFmsAttachedCallback(callback, initialNotify);
  }
  public void cancelFmsAttachedCallback(int uid) {
    DriverStationDataJNI.cancelFmsAttachedCallback(uid);
  }
  public boolean getFmsAttached() {
    return DriverStationDataJNI.getFmsAttached();
  }
  public void setFmsAttached(boolean fmsAttached) {
    DriverStationDataJNI.setFmsAttached(fmsAttached);
  }

  public int registerDsAttachedCallback(NotifyCallback callback, boolean initialNotify) {
    return DriverStationDataJNI.registerDsAttachedCallback(callback, initialNotify);
  }
  public void cancelDsAttachedCallback(int uid) {
    DriverStationDataJNI.cancelDsAttachedCallback(uid);
  }
  public boolean getDsAttached() {
    return DriverStationDataJNI.getDsAttached();
  }
  public void setDsAttached(boolean dsAttached) {
    DriverStationDataJNI.setDsAttached(dsAttached);
  }

  public void resetData() {
    DriverStationDataJNI.resetData();
  }
}
