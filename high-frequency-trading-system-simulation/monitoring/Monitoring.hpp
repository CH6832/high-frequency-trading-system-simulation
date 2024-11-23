#pragma once

#ifndef MONITORING_HPP
#define MONITORING_HPP

#include "Alerts.hpp"
#include <string>

/// Class to monitor system activities and trigger alerts based on conditions
class Monitoring {
public:
    /// Log trading activity or system event
    void logEvent(const std::string& event);

    /// Trigger an alert based on a specified alert type
    void triggerAlert(const Alert& alert);

private:
    /// Helper function to log an alert message
    void logAlert(const std::string& alertMessage);
};

#endif // MONITORING_HPP
