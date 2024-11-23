// utils/ConfigManager.cpp

#include "ConfigManager.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool ConfigManager::loadConfig(const std::string& filename) {
    std::ifstream configFile(filename);
    if (!configFile.is_open()) {
        std::cerr << "Could not open config file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream iss(line);
        std::string key, value;

        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            configData[key] = value; // Store key-value pairs
        }
    }
    configFile.close();
    return true;
}

std::string ConfigManager::getValue(const std::string& key) const {
    auto it = configData.find(key);
    if (it != configData.end()) {
        return it->second; // Return the value associated with the key
    }
    return ""; // Return empty string if key not found
}
