#pragma once
#include <string>
#include <iostream>
#include "json.hpp" // Libraria externa!

using json = nlohmann::json;

class IDeviceObserver {
public:
    virtual void update(const std::string& event) = 0;
    virtual ~IDeviceObserver() = default;
};

class SmartDevice : public IDeviceObserver {
protected:
    std::string name;
    bool isOn;
    static int totalDevices;

public:
    SmartDevice(const std::string& name);
    virtual ~SmartDevice();

    virtual void performAction() = 0; 
    virtual json toJson() const = 0; // METODĂ NOUĂ: obligă derivatele să se exporte în JSON
    
    void turnOn();
    void turnOff();
    std::string getName() const;

    static int getTotalDevices(); 
};