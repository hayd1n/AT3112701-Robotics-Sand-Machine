/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-19 13:18:18
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-19 15:48:35
 *  Description: Move Class
 */

#pragma once

#include "Config.hpp"
#include "Coords.hpp"

class Move {
 private:
  CartesianCoord _start;
  CartesianCoord _end;
  CartesianCoord _dis;
  PolarCoord _dis_polar;
  unsigned long _move_time;
  unsigned long _start_time;
  float _speed{MOVE_SPEED};
  bool _started{false};

 public:
  Move();
  Move(const CartesianCoord& end);

 public:
  void setStartPos(const CartesianCoord& start);
  bool isStarted() const;

 public:
  void start();
  CartesianCoord move();
  void end();
  bool isEnd();
};