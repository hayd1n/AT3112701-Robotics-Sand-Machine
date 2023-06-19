/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-19 13:24:40
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-19 13:44:09
 *  Description: Move Class
 */

#include "Move.hpp"

#include <Arduino.h>

#include "Utilities.hpp"

Move::Move(const CartesianCoord& end) : _end(end) {}

void Move::setStartPos(const CartesianCoord& start) {
  _start = start;
}

void Move::start() {
  _start_time = millis();
  _dis = _end - _start;
  _dis_polar = Utilities::cartesianToPolar(_dis);
  _move_time = (_dis_polar.r / _speed) * 1000;
}

CartesianCoord Move::move() {
  unsigned long elapsed = millis() - _start_time;

  float current_r = _dis_polar.r * min((float)elapsed / (float)_move_time, 1.0f);
  PolarCoord move_polar = _dis_polar;
  move_polar.r = current_r;
  CartesianCoord move = Utilities::polarToCartesian(move_polar) + _start;
  // Serial.printf("%f %f\n", move.x, move.y);

  return move;
}

void Move::end() {
}

bool Move::isEnd() {
  return (millis() - _start_time < _move_time);
}