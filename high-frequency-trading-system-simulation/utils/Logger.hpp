#pragma once

// utils/Logger.hpp

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

class Logger {
public:
    // Log levels
    enum class LogLevel {
        INFO,
        WARNING,
        ERROR
    };

    // Constructor to initialize log file
    Logger(const std::string& filename) : logFile(filename, std::ios::app) {}

    // Log a message with a specific log level
    void log(const std::string& message, LogLevel level = LogLevel::INFO) {
        if (logFile.is_open()) {
            logFile << getCurrentTime() << " [" << toString(level) << "] " << message << std::endl;
        }
    }

private:
    std::ofstream logFile; // Log file stream

    // Get the current time as a string
    std::string getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
        return std::ctime(&nowTime);
    }

    // Convert log level to string
    std::string toString(LogLevel level) {
        switch (level) {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
        }
    }
};

#endif // LOGGER_HPP
