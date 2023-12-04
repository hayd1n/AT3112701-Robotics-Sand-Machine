/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-18 17:39:53
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-12-05 00:22:57
 *  Description: Sand Machine Class
 */

#pragma once

#include <FastAccelStepper.h>

#include "Config.hpp"
#include "Coords.hpp"

class SandMachine {
 private:
  FastAccelStepper* _stepper0 = nullptr;
  FastAccelStepper* _stepper1 = nullptr;
  int _stepper0_reset_pin;
  int _stepper1_reset_pin;
  float _stepper0_offset{0};
  float _stepper1_offset{0};
  float _stepper0_last_deg{0};
  float _stepper1_last_deg{0};
  float _stepper_deg_ratio{STP_DEG_TO_PUL};
  uint32_t _home_speed{STP_HOME_SPEED};
  uint32_t _speed;
  int32_t _acc_speed;
  uint32_t _arm_length{ARM_LENGTH};

 public:
  SandMachine();
  SandMachine(FastAccelStepper* stepper0,
              FastAccelStepper* stepper1,
              int stepper0_reset_pin, int stepper1_reset_pin);

 public:
  inline void setStepper0(FastAccelStepper* stepper) { _stepper0 = stepper; }
  inline void setStepper1(FastAccelStepper* stepper) { _stepper1 = stepper; }
  inline void setStepper0ResetPin(int pin) { _stepper0_reset_pin = pin; }
  inline void setStepper1ResetPin(int pin) { _stepper1_reset_pin = pin; }
  inline FastAccelStepper* getStepper0() { return _stepper0; }
  inline FastAccelStepper* getStepper1() { return _stepper1; }

 public:
  /**
   * @brief 初始化
   *
   */
  void init();

  bool getStepper0ResetSensor() const;

  bool getStepper1ResetSensor() const;

  void setSpeed(uint32_t speed);

  void setAcceleration(int32_t acceleration);

  void moveStepper0ToDeg(float degrees);

  void moveStepper1ToDeg(float degrees);

 public:
  /**
   * @brief 回原點
   *
   */
  void home();

  /**
   * @brief 設置位置
   *
   * @param pos 座標
   */
  void setPos(const CartesianCoord& pos);
};