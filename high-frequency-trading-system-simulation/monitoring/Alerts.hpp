#pragma once

// monitoring/Alerts.hpp

#ifndef ALERTS_HPP
#define ALERTS_HPP

#include <string>
#include <ostream> // Include <ostream> for the << operator

// Define the severity levels for alerts
enum class Severity {
    LOW,
    MEDIUM,
    HIGH
};

// Alert class definition
struct Alert {
    std::string message;   // Message of the alert
    Severity severity;     // Severity level of the alert

    // Constructor
    Alert(const std::string& msg, Severity sev)
        : message(msg), severity(sev) {}
};

// Overload the << operator for Severity
inline std::ostream& operator<<(std::ostream& os, const Severity& severity) {
    switch (severity) {
    case Severity::LOW:
        os << "LOW";
        break;
    case Severity::MEDIUM:
        os << "MEDIUM";
        break;
    case Severity::HIGH:
        os << "HIGH";
        break;
    }
    return os;
}

#endif // ALERTS_HPP