#pragma once
// market_data_feed/MarketDataProtocols.hpp

#ifndef MARKETDATAPROTOCOLS_HPP
#define MARKETDATAPROTOCOLS_HPP

#include <string>
#include <iostream>
#include <vector>

/// Enum class to specify the type of market data protocol
enum class MarketDataProtocol {
    FIX,    // Financial Information Exchange
    ITCH,   // ITCH Protocol
    CUSTOM  // Custom Protocol
};

/// Structure to represent a simple market data quote
struct Quote {
    std::string symbol;   // Ticker symbol of the asset
    double price;         // Quote price
    int volume;           // Volume at this price level

    // Constructor for ease of use
    Quote(const std::string& symbol, double price, int volume)
        : symbol(symbol), price(price), volume(volume) {}
};

/// Structure to represent a trade event in the market data
struct Trade {
    std::string symbol;   // Ticker symbol of the asset
    double price;         // Trade price
    int volume;           // Trade volume
    // std::string tradeID;  // Unique trade identifier

    Trade(const std::string& symbol, double price, int volume, const std::string& tradeID)
        : symbol(symbol), price(price), volume(volume) {}
};

/// Abstract base class for parsing different market data protocols
class MarketDataParser {
public:
    virtual ~MarketDataParser() = default;

    /// Parse a market data message and populate the appropriate data structures
    virtual bool parseMessage(const std::string& message) = 0;

    /// Get the latest quotes from the market data
    virtual std::vector<Quote> getQuotes() const = 0;

    /// Get the latest trades from the market data
    virtual std::vector<Trade> getTrades() const = 0;
};

/// Parser for the FIX protocol
class FIXParser : public MarketDataParser {
public:
    bool parseMessage(const std::string& message) override {
        // Simulate FIX message parsing
        std::cout << "Parsing FIX message: " << message << std::endl;
        // Actual parsing logic goes here
        return true;
    }

    std::vector<Quote> getQuotes() const override {
        // Ensure to provide all required arguments for the Quote constructor
        return { Quote("AAPL", 150.5, 20), Quote("GOOGL", 2800.0, 15) }; // Example volumes
    }

    std::vector<Trade> getTrades() const override {
        // Provide the required parameters: symbol, price, volume, and tradeID
        return { Trade("AAPL", 150.5, 20, "TRD123"), Trade("GOOGL", 2800.0, 5, "TRD456") }; // Example trades
    }
};

/// Parser for the ITCH protocol
class ITCHParser : public MarketDataParser {
public:
    bool parseMessage(const std::string& message) override {
        // Simulate ITCH message parsing
        std::cout << "Parsing ITCH message: " << message << std::endl;
        // Actual parsing logic goes here
        return true;
    }

    std::vector<Quote> getQuotes() const override {
        return { Quote("MSFT", 300.25, 20), Quote("NFLX", 600.0, 20) };
    }

    std::vector<Trade> getTrades() const override {
        return { Trade("AAPL", 300.5, 20, "TRD123"), Trade("GOOGL", 2800.0, 5, "TRD456") };
    }
};

/// Factory function to create a market data parser for a specific protocol
inline MarketDataParser* createParser(MarketDataProtocol protocol) {
    switch (protocol) {
    case MarketDataProtocol::FIX:
        return new FIXParser();
    case MarketDataProtocol::ITCH:
        return new ITCHParser();
        // Uncomment and implement a custom parser if needed
        // case MarketDataProtocol::CUSTOM:
        //     return new CustomParser();
    default:
        std::cerr << "Unsupported protocol!" << std::endl;
        return nullptr;
    }
}

#endif // MARKETDATAPROTOCOLS_HPP
