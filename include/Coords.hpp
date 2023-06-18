/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-19 02:53:31
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-19 02:56:25
 *  Description: Coords Class
 */

#pragma once

class PolarCoord {
 public:
  float r;
  float theta;

 public:
  PolarCoord(float r = 0, float theta = 0) : r(r), theta(theta) {}
};

class CartesianCoord {
 public:
  float x;
  float y;

 public:
  CartesianCoord(float x = 0, float y = 0) : x(x), y(y) {}

 public:
  friend CartesianCoord operator+(const CartesianCoord& a, const CartesianCoord& b) {
    return CartesianCoord(a.x + b.x, a.y + b.y);
  }

  friend CartesianCoord operator-(const CartesianCoord& a, const CartesianCoord& b) {
    return CartesianCoord(a.x - b.x, a.y - b.y);
  }

  friend bool operator==(const CartesianCoord& a, const CartesianCoord& b) {
    return (a.x == b.x && a.y == b.y);
  }

  friend bool operator!=(const CartesianCoord& a, const CartesianCoord& b) {
    return (a.x != b.x || a.y != b.y);
  }
};