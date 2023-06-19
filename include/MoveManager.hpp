/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-19 13:48:36
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-19 13:51:33
 *  Description: Move Manager Class
 */

#pragma once

#include <Arduino.h>

#include "Move.hpp"

class MoveManager {
 private:
  Move *_moves;

 public:
  MoveManager(size_t buffer_size = 512);
};