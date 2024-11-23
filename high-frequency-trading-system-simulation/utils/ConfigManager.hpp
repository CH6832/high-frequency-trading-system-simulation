#pragma once

// utils/ConfigManager.hpp

#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include <string>
#include <unordered_map>

class ConfigManager {
public:
    // Load configuration from a specified file
    bool loadConfig(const std::string& filename);

    // Get a value associated with a key
    std::string getValue(const std::string& key) const;

private:
    std::unordered_map<std::string, std::string> configData; // Key-value pairs for configuration
};

#endif // CONFIGMANAGER_HPP


