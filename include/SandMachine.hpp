/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-18 17:39:53
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-18 17:43:33
 *  Description: Sand Machine Class
 */

#include <FastAccelStepper.h>

class SandMachine {
 private:
  FastAccelStepper* _stepper1;
  FastAccelStepper* _stepper2;

 public:
  SandMachine(FastAccelStepper* stepper1, FastAccelStepper* stepper2);

 public:
  void setPos(int x, int y);
};