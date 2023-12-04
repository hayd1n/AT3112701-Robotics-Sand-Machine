#include "Watchdog.hpp"

#include "Config.hpp"

void Watchdog::watch(SandMachine& machine) {
  FastAccelStepper* stp0 = machine.getStepper0();
  FastAccelStepper* stp1 = machine.getStepper1();

  bool error = false;

  if (stp0 != nullptr) {
    if (stp0->getCurrentSpeedInMilliHz() > STP_MAX_SPEED)
      error |= true;
  }

  if (stp1 != nullptr) {
    if (stp1->getCurrentSpeedInMilliHz() > STP_MAX_SPEED)
      error |= true;
  }

  if (error) {
    // Emergency stop if abnormal stepper motor speed is detected
    if (stp0 != nullptr)
      stp0->forceStop();

    if (stp1 != nullptr)
      stp1->forceStop();

    Serial.println("= Watchdog =================================");
    Serial.println("Abnormal stepper motor speed is detected.");
    Serial.println("Emergency stop the machine.");
    Serial.println("= Watchdog =================================");

    // Shutdown ESP32
    esp_err_t esp_sleep_disable_wakeup_source();
    esp_deep_sleep_start();
  }
}