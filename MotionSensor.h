#pragma once
#include <vector>
#include <string>
#include "SmartDevice.h"

class MotionSensor {
private:
    std::vector<IDeviceObserver*> observers;
public:
    void addObserver(IDeviceObserver* observer);
    void detectMotion();
};