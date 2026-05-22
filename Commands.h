#pragma once
#include "SmartDevice.h"

// Interfața Command
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Comenzi concrete
class TurnOnCommand : public Command {
private:
    SmartDevice* device;
public:
    TurnOnCommand(SmartDevice* dev) : device(dev) {}
    void execute() override { device->turnOn(); }
};

class TurnOffCommand : public Command {
private:
    SmartDevice* device;
public:
    TurnOffCommand(SmartDevice* dev) : device(dev) {}
    void execute() override { device->turnOff(); }
};