#include <iostream>
#include <string>
#include <limits>
#include "json.hpp"
#include "SmartDevice.h"
#include "ConcreteDevices.h"
#include "MotionSensor.h"
#include "Commands.h"
#include "DeviceRegistry.hpp"

class Application {
public:
    void run() {
        DeviceRegistry<SmartDevice*> houseRegistry;
        MotionSensor sensor;
        int choice = 0;

        std::cout << "=== Sistem Centralizat Smart Home ===\n";

        while (choice != 5) {
            std::cout << "\n--- Meniu Principal ---\n";
            std::cout << "1. Adauga Bec Inteligent\n";
            std::cout << "2. Adauga Termostat\n";
            std::cout << "3. Declanseaza Senzorul de Miscare (Test Observer)\n";
            std::cout << "4. Afiseaza Status Dispozitive\n";
            std::cout << "5. Salveaza Configurat1ia in JSON si Iesi\n";
            std::cout << "Alege o optiune (1-5): ";
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Eroare: Te rog introdu un numar valid!\n";
                continue;
            }

            if (choice == 1) {
                std::string name;
                std::cout << "Introdu numele becului (ex: Lumina Bucatarie): ";
                std::cin >> std::ws;
                std::getline(std::cin, name);
                
                SmartLight* light = new SmartLight(name);
                houseRegistry.add(light);
                sensor.addObserver(light);
                std::cout << "[Succes] Becul '" << name << "' a fost adaugat.\n";
            } 
            else if (choice == 2) {
                std::string name;
                int temp;
                std::cout << "Introdu numele termostatului: ";
                std::cin >> std::ws;
                std::getline(std::cin, name);
                std::cout << "Introdu temperatura setata: ";
                std::cin >> temp;

                SmartThermostat* thermo = new SmartThermostat(name, temp);
                houseRegistry.add(thermo);
                sensor.addObserver(thermo);
                std::cout << "[Succes] Termostatul '" << name << "' a fost adaugat.\n";
            }
            else if (choice == 3) {
                sensor.detectMotion();
            }
            else if (choice == 4) {
                std::cout << "\nTotal dispozitive in sistem: " << SmartDevice::getTotalDevices() << "\n";
                houseRegistry.executeAllActions();
            }
            else if (choice == 5) {
                houseRegistry.saveSystemConfig("stare_casa.json");
                std::cout << "Se inchide sistemul...\n";
            } 
            else {
                std::cout << "Optiune invalida! Incearca din nou.\n";
            }
        }
    }
};

int main() {
    Application app;
    app.run();
    return 0;
}