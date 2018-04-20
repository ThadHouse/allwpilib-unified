package edu.wpi.first.wpilibj.sim;

import edu.wpi.first.hal.sim.mockdata.PDPDataJNI;

public class PDPSim {
  private int m_index;

  public PDPSim(int index) {
    m_index = index;
  }

  public int registerInitializedCallback(NotifyCallback callback, boolean initialNotify) {
    return PDPDataJNI.registerInitializedCallback(m_index, callback, initialNotify);
  }
  public void cancelInitializedCallback(int uid) {
    PDPDataJNI.cancelInitializedCallback(m_index, uid);
  }
  public boolean getInitialized() {
    return PDPDataJNI.getInitialized(m_index);
  }
  public void setInitialized(boolean initialized) {
    PDPDataJNI.setInitialized(m_index, initialized);
  }

  public int registerTemperatureCallback(NotifyCallback callback, boolean initialNotify) {
    return PDPDataJNI.registerTemperatureCallback(m_index, callback, initialNotify);
  }
  public void cancelTemperatureCallback(int uid) {
    PDPDataJNI.cancelTemperatureCallback(m_index, uid);
  }
  public double getTemperature() {
    return PDPDataJNI.getTemperature(m_index);
  }
  public void setTemperature(double temperature) {
    PDPDataJNI.setTemperature(m_index, temperature);
  }

  public int registerVoltageCallback(NotifyCallback callback, boolean initialNotify) {
    return PDPDataJNI.registerVoltageCallback(m_index, callback, initialNotify);
  }
  public void cancelVoltageCallback(int uid) {
    PDPDataJNI.cancelVoltageCallback(m_index, uid);
  }
  public double getVoltage() {
    return PDPDataJNI.getVoltage(m_index);
  }
  public void setVoltage(double voltage) {
    PDPDataJNI.setVoltage(m_index, voltage);
  }

  public int registerCurrentCallback(int channel, NotifyCallback callback, boolean initialNotify) {
    return PDPDataJNI.registerCurrentCallback(m_index, channel, callback, initialNotify);
  }
  public void cancelCurrentCallback(int channel, int uid) {
    PDPDataJNI.cancelCurrentCallback(m_index, channel, uid);
  }
  public double getCurrent(int channel) {
    return PDPDataJNI.getCurrent(m_index, channel);
  }
  public void setCurrent(int channel, double current) {
    PDPDataJNI.setCurrent(m_index, channel, current);
  }

  public void resetData() {
    PDPDataJNI.resetData(m_index);
  }
}
