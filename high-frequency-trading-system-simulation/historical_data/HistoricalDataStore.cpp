// historical_data/HistoricalDataStore.cpp

#include "HistoricalDataStore.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool HistoricalDataStore::loadFromCSV(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filePath << std::endl;
        return false;
    }

    std::string line;
    // Skip the header line (if present)
    std::getline(file, line);

    while (std::getline(file, line)) {
        HistoricalDataEntry entry = parseCSVLine(line);
        dataStore[entry.symbol].push_back(entry);
    }

    file.close();
    std::cout << "Loaded historical data from " << filePath << std::endl;
    return true;
}

HistoricalData HistoricalDataStore::getHistoricalData(const std::string& symbol) const {
    auto it = dataStore.find(symbol);
    if (it != dataStore.end()) {
        return it->second;
    }
    return {}; // Return empty data if symbol not found
}

HistoricalDataEntry HistoricalDataStore::parseCSVLine(const std::string& line) {
    std::stringstream ss(line);
    std::string date, symbol;
    double openPrice, closePrice, highPrice, lowPrice;
    int volume;

    std::getline(ss, date, ',');
    std::getline(ss, symbol, ',');
    ss >> openPrice;
    ss.ignore(1, ',');
    ss >> closePrice;
    ss.ignore(1, ',');
    ss >> highPrice;
    ss.ignore(1, ',');
    ss >> lowPrice;
    ss.ignore(1, ',');
    ss >> volume;

    return HistoricalDataEntry(date, symbol, openPrice, closePrice, highPrice, lowPrice, volume);
}
