package edu.wpi.first.wpilibj.sim;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

import edu.wpi.first.wpilibj.AnalogInput;
import edu.wpi.first.wpilibj.hal.HAL;

public class AnalogInputSimTest {
  static class DoubleStore {
    public boolean wasTriggered = false;
    public boolean wasCorrectType = false;
    public double setValue = 0;
  }

  @Test
  public void testSetCallback() {
    HAL.initialize(500, 0);


    AnalogInput input = new AnalogInput(5);

    AnalogInSim inputSim = input.getSimObject();

    for (double i = 0; i < 5.0; i+=0.1) {
      inputSim.setVoltage(0);

      assertEquals(input.getVoltage(), 0, 0.001);

      inputSim.setVoltage(i);

      assertEquals(input.getVoltage(), i, 0.001);

    }



  }
}
