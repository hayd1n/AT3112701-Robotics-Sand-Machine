/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-19 02:03:13
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-19 02:59:07
 *  Description: Utilities Class
 */

#pragma once

#include <Arduino.h>

#include "Coords.hpp"

class Utilities {
 public:
  inline static PolarCoord cartesianToPolar(const CartesianCoord& cartesian) {
    PolarCoord polar;

    polar.r = std::sqrt(cartesian.x * cartesian.x + cartesian.y * cartesian.y);
    polar.theta = std::atan2(cartesian.y, cartesian.x);

    return polar;
  }

  inline static CartesianCoord polarToCartesian(const PolarCoord& polar) {
    CartesianCoord cartesian;

    cartesian.x = polar.r * std::cos(polar.theta);
    cartesian.y = polar.r * std::sin(polar.theta);

    return cartesian;
  }

  inline static float degreesToRadians(float degrees) {
    return degrees * M_PI / 180.0;
  }

  inline static float radiansToDegrees(float radians) {
    return radians * 180.0 / M_PI;
  }
};