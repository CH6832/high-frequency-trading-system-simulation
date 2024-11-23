// monitoring/Monitoring.cpp

#include "Monitoring.hpp"
#include <iostream>

void Monitoring::logEvent(const std::string& event) {
    // Log the event to the console or to a file (basic console output here)
    std::cout << "[EVENT LOG]: " << event << std::endl;
}

void Monitoring::triggerAlert(const Alert& alert) {
    // Log alert details and display alert message
    logAlert(alert.message);
    std::cerr << "[ALERT]: " << alert.message << " | Severity: " << alert.severity << std::endl;
}

void Monitoring::logAlert(const std::string& alertMessage) {
    // Placeholder for logging alert to an external system (basic console output here)
    std::cout << "[ALERT LOG]: " << alertMessage << std::endl;
}

