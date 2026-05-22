#pragma once
#include "SmartDevice.h"

class SmartLight : public SmartDevice {
public:
    SmartLight(const std::string& name);
    void performAction() override;
    void update(const std::string& event) override;
    
    // TREBUIE ADĂUGATĂ ACEASTĂ LINIE
    json toJson() const override; 
};

class SmartThermostat : public SmartDevice {
private:
    int temperature;
public:
    SmartThermostat(const std::string& name, int temp);
    void performAction() override;
    void update(const std::string& event) override;
    
    // TREBUIE ADĂUGATĂ ACEASTĂ LINIE
    json toJson() const override; 
};