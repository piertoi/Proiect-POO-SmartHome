#include "SmartDevice.h"

int SmartDevice::totalDevices = 0;

SmartDevice::SmartDevice(const std::string& name) : name(name), isOn(false) {
    totalDevices++;
}

SmartDevice::~SmartDevice() {
    totalDevices--;
}

void SmartDevice::turnOn() {
    isOn = true;
    std::cout << name << " este acum PORNIT.\n";
}

void SmartDevice::turnOff() {
    isOn = false;
    std::cout << name << " este acum OPRIT.\n";
}

std::string SmartDevice::getName() const {
    return name;
}

int SmartDevice::getTotalDevices() {
    return totalDevices;
}