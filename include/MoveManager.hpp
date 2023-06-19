/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-19 13:48:36
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-19 23:41:53
 *  Description: Move Manager Class
 */

#pragma once

#include <Arduino.h>

#include <vector>

#include "Move.hpp"

class MoveManager {
 private:
  std::vector<Move> _moves;
  size_t _buffer_size;
  size_t _current_index{0};
  CartesianCoord _current_pos;

 public:
  MoveManager(size_t buffer_size = 512);

 public:
  size_t getSize() const;
  size_t getBufferSpace() const;
  Move& getCurrentMove();
  void clear();
  void addMove(const Move& move);

  CartesianCoord move();

  /**
   * @brief 回收已完成的移動
   *
   */
  void collect();
};