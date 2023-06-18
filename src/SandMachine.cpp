/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-18 17:39:46
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-18 17:44:07
 *  Description: Sand Machine Class
 */

#include "SandMachine.hpp"

SandMachine::SandMachine(FastAccelStepper* stepper1,
                         FastAccelStepper* stepper2)
    : _stepper1(stepper1), _stepper2(stepper2) {}

void SandMachine::setPos(int x, int y) {
}