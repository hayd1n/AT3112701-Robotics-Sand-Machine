/**
 *  Author: 張皓鈞(HAO) m831718@gmail.com
 *  Create Date: 2023-06-19 00:23:21
 *  Editor: 張皓鈞(HAO) m831718@gmail.com
 *  Update Date: 2023-06-20 00:11:03
 *  Description: Config
 */

#pragma once

// Steppers
// Stepper drivers set to 800 pul/rev
#define STP0_PUL 23              // 步進馬達0脈衝腳位
#define STP0_DIR 22              // 步進馬達0方向腳位
#define STP1_PUL 32              // 步進馬達1脈衝腳位
#define STP1_DIR 33              // 步機馬達1方向腳位
#define STP_SPEED 12800 * 8      // 步進馬達速度
#define STP_ACC_SPEED 12800 * 8  // 步進馬達加速度
// #define STP_SPEED 4800 * 8        // 步進馬達速度
// #define STP_ACC_SPEED 4800 * 8    // 步進馬達加速度
#define STP_HOME_SPEED 200 * 8    // 步進馬達回原點速度
#define STP_DEG_TO_PUL 44.444444  // 步進馬達角度轉脈衝數

// Sensors
#define STP0_RST_PIN 17  // 手臂0原點
#define STP1_RST_PIN 16  // 手臂1原點

// Machine
#define ARM_LENGTH 90   // 手臂長度(mm)
#define MOVE_SPEED 100  // 移動速度(mm/s)