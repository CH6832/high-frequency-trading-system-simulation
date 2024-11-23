#pragma once
// market_data_feed/MarketDataFeed.hpp

#ifndef MARKETDATAFEED_HPP
#define MARKETDATAFEED_HPP

#include <string>
#include <vector>
#include <thread>
#include "MarketDataProtocols.hpp"

// Forward declarations of classes for parser and subscriber
class MarketDataParser;
class MarketDataSubscriber;

// Quote structure
//struct Quote {
//    double price;
//    int size;
//};

// Trade structure
//struct Trade {
//    double price;
//    int volume;
//};

// MarketDataFeed class
class MarketDataFeed {
public:
    // Constructor and Destructor
    MarketDataFeed(MarketDataProtocol protocol);
    ~MarketDataFeed();

    // Core methods
    void initialize(const std::string& connection_string);
    void start();
    void stop();
    void subscribe(MarketDataSubscriber* subscriber);

private:
    // Private methods
    void processDataFeed();
    void notifySubscribers(const std::vector<Quote>& quotes, const std::vector<Trade>& trades);
    std::string simulateIncomingMessage() const;

    // Member variables
    bool running;
    MarketDataParser* parser;
    std::thread feedThread;
    std::vector<MarketDataSubscriber*> subscribers;
};

#endif // MARKETDATAFEED_HPP