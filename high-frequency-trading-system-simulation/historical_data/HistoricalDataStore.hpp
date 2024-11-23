#pragma once

// historical_data/HistoricalDataStore.hpp

#ifndef HISTORICALDATASTORE_HPP
#define HISTORICALDATASTORE_HPP

#include "DataFormats.hpp"
#include <string>
#include <unordered_map>

class HistoricalDataStore {
public:
    HistoricalDataStore() = default;
    ~HistoricalDataStore() = default;

    // Load historical data from a CSV file
    bool loadFromCSV(const std::string& filePath);

    // Get historical data for a specific symbol
    HistoricalData getHistoricalData(const std::string& symbol) const;

private:
    // Internal storage of historical data by symbol
    std::unordered_map<std::string, HistoricalData> dataStore;

    // Helper function to parse a CSV line
    HistoricalDataEntry parseCSVLine(const std::string& line);
};

#endif // HISTORICALDATASTORE_HPP
