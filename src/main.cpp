/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-16 03:02:15
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-19 03:11:19
 *  Description: Sand Machine
 */

#include <Arduino.h>
#include <FastAccelStepper.h>

#include "Config.hpp"
#include "Coords.hpp"
#include "SandMachine.hpp"
#include "Utilities.hpp"

FastAccelStepperEngine engine = FastAccelStepperEngine();
SandMachine machine;

void setup() {
  Serial.begin(115200);

  engine.init();

  FastAccelStepper *stepper0 = engine.stepperConnectToPin(STP0_PUL);
  if (stepper0) {
    stepper0->setDirectionPin(STP0_DIR);
  }

  FastAccelStepper *stepper1 = engine.stepperConnectToPin(STP1_PUL);
  if (stepper1) {
    stepper1->setDirectionPin(STP1_DIR);
  }

  machine.setStepper0(stepper0);
  machine.setStepper1(stepper1);
  machine.setStepper0ResetPin(STP0_RST_PIN);
  machine.setStepper1ResetPin(STP1_RST_PIN);

  machine.init();

  machine.home();

  delay(1000);

  // machine.setPos(50, 50);
  CartesianCoord start(0, 0);
  CartesianCoord end(0, 100);

  CartesianCoord dis = end - start;
  PolarCoord dis_polar = Utilities::cartesianToPolar(dis);
  float r = dis_polar.r;
  float speed = 100;  // mm/s
  unsigned long move_time = (r / speed) * 1000;
  unsigned long start_time = millis();
  while (millis() - start_time < move_time) {
    unsigned long elapsed = millis() - start_time;
    float current_r = r * min((float)elapsed / (float)move_time, 1.0f);
    PolarCoord move_polar = dis_polar;
    move_polar.r = current_r;
    CartesianCoord move = Utilities::polarToCartesian(move_polar);

    machine.setPos(move.x, move.y);
    Serial.printf("%f %f\n", move.x, move.y);
  }
}

void loop() {
}