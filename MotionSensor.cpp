#include "MotionSensor.h"
#include <iostream>

void MotionSensor::addObserver(IDeviceObserver* observer) {
    observers.push_back(observer);
}

void MotionSensor::detectMotion() {
    std::cout << "\n[Senzor] Miscare detectata! Se trimit notificari...\n";
    for (auto obs : observers) {
        obs->update("MotionDetected");
    }
}