#include "ConcreteDevices.h"

// --- SmartLight ---
SmartLight::SmartLight(const std::string& name) : SmartDevice(name) {}

void SmartLight::performAction() {
    std::cout << "[Actiune] Becul '" << name << "' isi schimba intensitatea.\n";
}

void SmartLight::update(const std::string& event) {
    if (event == "MotionDetected") turnOn();
}

// Transformare in JSON
json SmartLight::toJson() const {
    return json{
        {"Tip", "SmartLight"},
        {"Nume", name},
        {"Stare", isOn ? "Pornit" : "Oprit"}
    };
}

// --- SmartThermostat ---
SmartThermostat::SmartThermostat(const std::string& name, int temp) : SmartDevice(name), temperature(temp) {}

void SmartThermostat::performAction() {
    std::cout << "[Actiune] Termostatul '" << name << "' mentine " << temperature << " grade.\n";
}

void SmartThermostat::update(const std::string& event) {
    if (event == "NightMode") temperature = 20;
}

// Transformare in JSON
json SmartThermostat::toJson() const {
    return json{
        {"Tip", "SmartThermostat"},
        {"Nume", name},
        {"Stare", isOn ? "Pornit" : "Oprit"},
        {"Temperatura", temperature}
    };
}