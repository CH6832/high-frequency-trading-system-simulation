#include "HistoricalDataLoader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<MarketData> HistoricalDataLoader::load(const std::string& filepath) {
    std::vector<MarketData> data;
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
        return data; // Return empty if file can't be opened
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string timestamp, symbol;
        double price;
        int volume;

        // Assume CSV format: timestamp,symbol,price,volume
        if (std::getline(iss, timestamp, ',') &&
            std::getline(iss, symbol, ',') &&
            iss >> price && iss.ignore() &&
            iss >> volume) {
            // Create MarketData object and add it to the vector
            MarketData marketData(timestamp, symbol, price, volume);
            data.push_back(marketData);
        }
    }

    file.close(); // Close the file
    return data; // Return the populated vector
}
