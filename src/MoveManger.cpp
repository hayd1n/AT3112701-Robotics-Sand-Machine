/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-19 13:50:46
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-19 13:53:31
 *  Description: Move Manager Class
 */

#include "MoveManager.hpp"

MoveManager::MoveManager(size_t buffer_size) {
  _moves = (Move*)malloc(buffer_size * sizeof(Move));
}