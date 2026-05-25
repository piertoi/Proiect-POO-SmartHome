#include "ConcreteDevices.h"

SmartLight::SmartLight(const std::string& name) : SmartDevice(name) {}

void SmartLight::performAction() {
    std::cout << "[Actiune] Becul '" << name << "' isi schimba intensitatea.\n";
}

void SmartLight::update(const std::string& event) {
    if (event == "MotionDetected") turnOn();
}

json SmartLight::toJson() const {
    return json{
        {"Tip", "SmartLight"},
        {"Nume", name},
        {"Stare", isOn ? "Pornit" : "Oprit"}
    };
}

SmartThermostat::SmartThermostat(const std::string& name, int temp) : SmartDevice(name), temperature(temp) {}

void SmartThermostat::performAction() {
    std::cout << "[Actiune] Termostatul '" << name << "' mentine " << temperature << " grade.\n";
}

void SmartThermostat::update(const std::string& event) {
    if (event == "NightMode") temperature = 20;
}

json SmartThermostat::toJson() const {
    return json{
        {"Tip", "SmartThermostat"},
        {"Nume", name},
        {"Stare", isOn ? "Pornit" : "Oprit"},
        {"Temperatura", temperature}
    };
}