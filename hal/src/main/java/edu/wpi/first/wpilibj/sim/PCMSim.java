package edu.wpi.first.wpilibj.sim;

import edu.wpi.first.wpilibj.sim.NotifyCallback;
import edu.wpi.first.hal.sim.mockdata.PCMDataJNI;

public class PCMSim {
  private int m_index;

  public PCMSim(int index) {
    m_index = index;
  }

  public int registerSolenoidInitializedCallback(int channel, NotifyCallback callback, boolean initialNotify) {
    return PCMDataJNI.registerSolenoidInitializedCallback(m_index, channel, callback, initialNotify);
  }
  public void cancelSolenoidInitializedCallback(int channel, int uid) {
    PCMDataJNI.cancelSolenoidInitializedCallback(m_index, channel, uid);
  }
  public boolean getSolenoidInitialized(int channel) {
    return PCMDataJNI.getSolenoidInitialized(m_index, channel);
  }
  public void setSolenoidInitialized(int channel, boolean solenoidInitialized) {
    PCMDataJNI.setSolenoidInitialized(m_index, channel, solenoidInitialized);
  }

  public int registerSolenoidOutputCallback(int channel, NotifyCallback callback, boolean initialNotify) {
    return PCMDataJNI.registerSolenoidOutputCallback(m_index, channel, callback, initialNotify);
  }
  public void cancelSolenoidOutputCallback(int channel, int uid) {
    PCMDataJNI.cancelSolenoidOutputCallback(m_index, channel, uid);
  }
  public boolean getSolenoidOutput(int channel) {
    return PCMDataJNI.getSolenoidOutput(m_index, channel);
  }
  public void setSolenoidOutput(int channel, boolean solenoidOutput) {
    PCMDataJNI.setSolenoidOutput(m_index, channel, solenoidOutput);
  }

  public int registerCompressorInitializedCallback(NotifyCallback callback, boolean initialNotify) {
    return PCMDataJNI.registerCompressorInitializedCallback(m_index, callback, initialNotify);
  }
  public void cancelCompressorInitializedCallback(int uid) {
    PCMDataJNI.cancelCompressorInitializedCallback(m_index, uid);
  }
  public boolean getCompressorInitialized() {
    return PCMDataJNI.getCompressorInitialized(m_index);
  }
  public void setCompressorInitialized(boolean compressorInitialized) {
    PCMDataJNI.setCompressorInitialized(m_index, compressorInitialized);
  }

  public int registerCompressorOnCallback(NotifyCallback callback, boolean initialNotify) {
    return PCMDataJNI.registerCompressorOnCallback(m_index, callback, initialNotify);
  }
  public void cancelCompressorOnCallback(int uid) {
    PCMDataJNI.cancelCompressorOnCallback(m_index, uid);
  }
  public boolean getCompressorOn() {
    return PCMDataJNI.getCompressorOn(m_index);
  }
  public void setCompressorOn(boolean compressorOn) {
    PCMDataJNI.setCompressorOn(m_index, compressorOn);
  }

  public int registerClosedLoopEnabledCallback(NotifyCallback callback, boolean initialNotify) {
    return PCMDataJNI.registerClosedLoopEnabledCallback(m_index, callback, initialNotify);
  }
  public void cancelClosedLoopEnabledCallback(int uid) {
    PCMDataJNI.cancelClosedLoopEnabledCallback(m_index, uid);
  }
  public boolean getClosedLoopEnabled() {
    return PCMDataJNI.getClosedLoopEnabled(m_index);
  }
  public void setClosedLoopEnabled(boolean closedLoopEnabled) {
    PCMDataJNI.setClosedLoopEnabled(m_index, closedLoopEnabled);
  }

  public int registerPressureSwitchCallback(NotifyCallback callback, boolean initialNotify) {
    return PCMDataJNI.registerPressureSwitchCallback(m_index, callback, initialNotify);
  }
  public void cancelPressureSwitchCallback(int uid) {
    PCMDataJNI.cancelPressureSwitchCallback(m_index, uid);
  }
  public boolean getPressureSwitch() {
    return PCMDataJNI.getPressureSwitch(m_index);
  }
  public void setPressureSwitch(boolean pressureSwitch) {
    PCMDataJNI.setPressureSwitch(m_index, pressureSwitch);
  }

  public int registerCompressorCurrentCallback(NotifyCallback callback, boolean initialNotify) {
    return PCMDataJNI.registerCompressorCurrentCallback(m_index, callback, initialNotify);
  }
  public void cancelCompressorCurrentCallback(int uid) {
    PCMDataJNI.cancelCompressorCurrentCallback(m_index, uid);
  }
  public double getCompressorCurrent() {
    return PCMDataJNI.getCompressorCurrent(m_index);
  }
  public void setCompressorCurrent(double compressorCurrent) {
    PCMDataJNI.setCompressorCurrent(m_index, compressorCurrent);
  }

  public void resetData() {
    PCMDataJNI.resetData(m_index);
  }
}
