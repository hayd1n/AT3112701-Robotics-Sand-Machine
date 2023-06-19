/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-19 13:50:46
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-19 23:42:18
 *  Description: Move Manager Class
 */

#include "MoveManager.hpp"

MoveManager::MoveManager(size_t buffer_size) : _buffer_size(buffer_size) {}

void MoveManager::clear() {
  _moves.clear();
}

size_t MoveManager::getSize() const {
  return _moves.size();
}

size_t MoveManager::getBufferSpace() const {
  return _buffer_size - _moves.size();
}

Move& MoveManager::getCurrentMove() {
  return _moves[_current_index];
}

void MoveManager::addMove(const Move& move) {
  if (_moves.size() >= _buffer_size)
    return;

  _moves.push_back(move);
}

CartesianCoord MoveManager::move() {
  // Serial.printf("current_index=%d, size=%d\n", _current_index, _moves.size());
  // 如果沒有移動
  if (_moves.size() == 0)
    return _current_pos;

  // 如果當前移動未開始
  if (!this->getCurrentMove().isStarted()) {
    // 開始新的移動
    this->getCurrentMove().setStartPos(_current_pos);
    this->getCurrentMove().start();
  }

  CartesianCoord move = _current_pos;

  // 如果當前移動已經結束
  if (this->getCurrentMove().isEnd()) {
    // 結束原來的移動
    this->getCurrentMove().end();
    _moves.erase(_moves.begin() + _current_index);
    // // 切換到下一個移動
    // if (_current_index < _moves.size() - 1)
    //   _current_index += 1;
  } else {
    move = this->getCurrentMove().move();
    _current_pos = move;
  }

  // 回收已經結束的移動
  // this->collect();

  return move;
}

void MoveManager::collect() {
  for (auto it = _moves.begin(); it != _moves.end(); ++it) {
    bool is_end = (*it).isEnd();
    if (is_end) {
      _moves.erase(it);
      if (_current_index > 0)
        _current_index -= 1;
    }
  }
}