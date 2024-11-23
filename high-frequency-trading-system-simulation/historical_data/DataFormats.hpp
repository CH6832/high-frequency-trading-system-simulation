#pragma once
// historical_data/DataFormats.hpp

#ifndef DATAFORMATS_HPP
#define DATAFORMATS_HPP

#include <string>
#include <vector>

// Structure to represent a market data entry
struct MarketData {
    std::string timestamp; // Timestamp of the data entry
    std::string symbol;    // Ticker symbol
    double price;          // Price of the asset
    int volume;            // Volume of trades

    // Default constructor
    MarketData() : timestamp(""), symbol(""), price(0.0), volume(0) {}

    // Parameterized constructor
    MarketData(const std::string& timestamp, const std::string& symbol, double price, int volume)
        : timestamp(timestamp), symbol(symbol), price(price), volume(volume) {}
};


// Structure to represent a single historical data entry
struct HistoricalDataEntry {
    std::string date;    // Date of the data entry
    std::string symbol;  // Ticker symbol
    double openPrice;    // Opening price
    double closePrice;   // Closing price
    double highPrice;    // Highest price
    double lowPrice;     // Lowest price
    int volume;          // Volume of trades

    HistoricalDataEntry(const std::string& date, const std::string& symbol,
        double openPrice, double closePrice,
        double highPrice, double lowPrice, int volume)
        : date(date), symbol(symbol), openPrice(openPrice),
        closePrice(closePrice), highPrice(highPrice),
        lowPrice(lowPrice), volume(volume) {}
};

// Type alias for a collection of historical data entries
using HistoricalData = std::vector<HistoricalDataEntry>;

#endif // DATAFORMATS_HPP
