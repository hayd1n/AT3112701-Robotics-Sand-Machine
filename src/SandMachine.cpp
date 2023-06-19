/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-18 17:39:46
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-19 15:40:18
 *  Description: Sand Machine Class
 */

#include "SandMachine.hpp"

#include <Arduino.h>

#include "Config.hpp"
#include "Utilities.hpp"

SandMachine::SandMachine() {}

SandMachine::SandMachine(FastAccelStepper* stepper0,
                         FastAccelStepper* stepper1,
                         int stepper0_reset_pin, int stepper1_reset_pin)
    : _stepper0(stepper0), _stepper1(stepper1), _stepper0_reset_pin(stepper0_reset_pin), _stepper1_reset_pin(stepper1_reset_pin) {
}

void SandMachine::init() {
  // Set sensors pin mode
  pinMode(_stepper0_reset_pin, INPUT_PULLUP);
  pinMode(_stepper1_reset_pin, INPUT_PULLUP);

  // Set stepper motors
  this->setSpeed(STP_SPEED);
  this->setAcceleration(STP_ACC_SPEED);
  _stepper0->setAutoEnable(true);
  _stepper1->setAutoEnable(true);
}

void SandMachine::setSpeed(uint32_t speed) {
  _speed = speed;
  _stepper0->setSpeedInHz(speed);
  _stepper1->setSpeedInHz(speed);
}

void SandMachine::setAcceleration(int32_t acceleration) {
  _acc_speed = acceleration;
  _stepper0->setAcceleration(acceleration);
  _stepper1->setAcceleration(acceleration);
}

bool SandMachine::getStepper0ResetSensor() const {
  return !digitalRead(_stepper0_reset_pin);
}

bool SandMachine::getStepper1ResetSensor() const {
  return !digitalRead(_stepper1_reset_pin);
}

void SandMachine::moveStepper0ToDeg(float degrees) {
  float diff = degrees - _stepper0_last_deg;
  if (abs(diff) > 180) {
    _stepper0_offset = 360 * (diff > 0 ? -1 : 1);
  }
  _stepper0->moveTo((degrees + _stepper0_offset) * _stepper_deg_ratio);
  _stepper0_last_deg = (degrees + _stepper0_offset);
}

void SandMachine::moveStepper1ToDeg(float degrees) {
  float diff = degrees - _stepper1_last_deg;
  if (abs(diff) > 180) {
    _stepper1_offset = 360 * (diff > 0 ? -1 : 1);
  }
  _stepper1->moveTo((degrees + _stepper1_offset) * _stepper_deg_ratio);
  _stepper1_last_deg = (degrees + _stepper1_offset);
}

void SandMachine::home() {
  uint32_t original_speed = this->_speed;

  // Move until sensor is on
  this->_stepper0->setSpeedInHz(_home_speed);
  while (!this->getStepper0ResetSensor())
    _stepper0->runForward();
  _stepper0->forceStop();
  // Keep moving slow until sensor is off
  this->_stepper0->setSpeedInHz(_home_speed / 2);
  while (this->getStepper0ResetSensor())
    _stepper0->runForward();
  _stepper0->forceStop();
  // Move back until sensor is on
  this->_stepper0->setSpeedInHz(_home_speed / 2);
  while (!this->getStepper0ResetSensor())
    _stepper0->runBackward();
  _stepper0->forceStop();
  _stepper0->setCurrentPosition(0);

  // Move until sensor is on
  this->_stepper1->setSpeedInHz(_home_speed);
  while (!this->getStepper1ResetSensor())
    _stepper1->runForward();
  _stepper1->forceStop();
  // Keep moving slow until sensor is off
  this->_stepper1->setSpeedInHz(_home_speed / 2);
  while (this->getStepper1ResetSensor())
    _stepper1->runForward();
  _stepper1->forceStop();
  // Move back until sensor is on
  this->_stepper1->setSpeedInHz(_home_speed / 2);
  while (!this->getStepper1ResetSensor())
    _stepper1->runBackward();
  _stepper1->forceStop();
  _stepper1->setCurrentPosition(180 * _stepper_deg_ratio);
  _stepper1_last_deg = 180;

  this->setSpeed(original_speed);
}

void SandMachine::setPos(const CartesianCoord& pos) {
  PolarCoord polar = Utilities::cartesianToPolar(pos);

  float arm0_theta = polar.theta - acos(polar.r / (2 * _arm_length));
  float arm1_theta = (2 * polar.theta) - arm0_theta;

  this->moveStepper0ToDeg(Utilities::radiansToDegrees(arm0_theta));
  this->moveStepper1ToDeg(Utilities::radiansToDegrees(arm1_theta));
}