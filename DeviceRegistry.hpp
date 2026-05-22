#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "json.hpp"

template <typename T>
class DeviceRegistry {
private:
    std::vector<T> registry;
public:
    void add(T item) {
        registry.push_back(item);
    }

    void executeAllActions() {
        for (auto item : registry) {
            item->performAction();
        }
    }

    // NOU: Funcția care exportă tot sistemul într-un fișier fizic
    void saveSystemConfig(const std::string& filename) {
        nlohmann::json jsonArray = nlohmann::json::array();
        
        for (auto item : registry) {
            jsonArray.push_back(item->toJson()); // Apel polimorfic!
        }

        std::ofstream file(filename);
        if (file.is_open()) {
            file << jsonArray.dump(4); // dump(4) adaugă spații ca fișierul să arate frumos și lizibil
            std::cout << "\n[Sistem] Configuratia casei a fost salvata in '" << filename << "'.\n";
        } else {
            std::cerr << "Eroare la deschiderea fisierului!\n";
        }
    }
};