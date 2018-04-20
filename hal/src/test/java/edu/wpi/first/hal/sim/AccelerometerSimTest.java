package edu.wpi.first.hal.sim;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import edu.wpi.first.hal.sim.mockdata.AccelerometerDataJNI;
import edu.wpi.first.wpilibj.hal.AccelerometerJNI;
import edu.wpi.first.wpilibj.hal.HAL;
import edu.wpi.first.wpilibj.sim.AccelerometerSim;


public class AccelerometerSimTest {

  static class TriggeredStore {
    public boolean wasTriggered = false;
    public boolean setValue = true;
  }

  @Test
  public void testCallbacks() {
    HAL.initialize(500, 0);
    AccelerometerSim sim = new AccelerometerSim(0);
    sim.resetData();

    TriggeredStore store = new TriggeredStore();
    int uid = AccelerometerDataJNI.registerActiveCallback(0, (s, v) -> {
      store.wasTriggered = true;
      store.setValue = v.getBoolean();
    }, false);

      boolean wasTriggeredAfterRegister = store.wasTriggered;

      AccelerometerJNI.setAccelerometerActive(true);
      sim.cancelActiveCallback(uid);
      assertFalse(wasTriggeredAfterRegister);
      assertTrue(store.wasTriggered);
      assertTrue(store.setValue);
  }
}
