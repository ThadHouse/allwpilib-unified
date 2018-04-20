package edu.wpi.first.hal.sim;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import edu.wpi.first.hal.sim.mockdata.AccelerometerDataJNI;
import edu.wpi.first.wpilibj.hal.HAL;


public class AccelerometerSimTest {

  static class TriggeredStore {
    public boolean wasTriggered = false;
    public boolean setValue = true;
  }

  @Test
  public void testCallbacks() {
    String property = System.getProperty("os.arch");

    System.out.println(property);
    HAL.initialize(500, 0);
    AccelerometerDataJNI.resetData(0);
    AccelerometerDataJNI.setActive(0, false);

    TriggeredStore store = new TriggeredStore();
    int uid = AccelerometerDataJNI.registerActiveCallback(0, (s, v) -> {
      store.wasTriggered = true;
      store.setValue = v.getBoolean();
    }, false);

    try {
      assertFalse(store.wasTriggered);

      AccelerometerDataJNI.setActive(0, true);

      assertTrue(store.wasTriggered);
      assertTrue(store.setValue);
    } finally {
      AccelerometerDataJNI.cancelActiveCallback(0, uid);
    }

  }
}
