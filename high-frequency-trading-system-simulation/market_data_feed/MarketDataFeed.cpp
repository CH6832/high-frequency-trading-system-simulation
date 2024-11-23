#pragma once
// src/market_data_feed/MarketDataFeed.cpp

#include "MarketDataFeed.hpp"
#include "MarketDataProtocols.hpp"
#include "MarketDataSubscriber.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>

// Assume this header provides MarketDataParser and createParser function
// #include "parser.h"  

// Constructor: Initialize parser and running status
MarketDataFeed::MarketDataFeed(MarketDataProtocol protocol)
    : running(false), parser(createParser(protocol)) {
    if (!parser) {
        throw std::runtime_error("Failed to create a market data parser!");
    }
}

// Destructor: Clean up allocated parser
MarketDataFeed::~MarketDataFeed() {
    delete parser;
}

// Initialize connection (if needed)
void MarketDataFeed::initialize(const std::string& connection_string) {
    // Implement connection initialization if necessary
    std::cout << "Initializing connection with: " << connection_string << std::endl;
}

// Start the data feed
void MarketDataFeed::start() {
    if (!parser) {
        std::cerr << "Parser not initialized. Cannot start feed." << std::endl;
        return;
    }

    std::cout << "Starting market data feed..." << std::endl;
    running = true;

    // Start a separate thread to handle data feed processing
    feedThread = std::thread(&MarketDataFeed::processDataFeed, this);
}

// Stop the data feed
void MarketDataFeed::stop() {
    running = false;
    if (feedThread.joinable()) {
        feedThread.join();  // Wait for the thread to complete
    }
    std::cout << "Market data feed stopped." << std::endl;
}

// Process data feed (runs in a separate thread)
void MarketDataFeed::processDataFeed() {
    while (running) {
        // Simulate receiving a market data message
        std::string message = simulateIncomingMessage();

        // Parse the incoming message
        if (!parser->parseMessage(message)) {
            std::cerr << "Failed to parse message: " << message << std::endl;
            continue;
        }

        // Retrieve parsed quotes and trades
        std::vector<Quote> quotes = parser->getQuotes();
        std::vector<Trade> trades = parser->getTrades();

        // Notify subscribers with the parsed data
        notifySubscribers(quotes, trades);

        // Sleep to simulate delay between receiving messages
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

// Add a new subscriber to the feed
void MarketDataFeed::subscribe(MarketDataSubscriber* subscriber) {
    subscribers.push_back(subscriber);
}

// Notify subscribers with updated quotes and trades
void MarketDataFeed::notifySubscribers(const std::vector<Quote>& quotes, const std::vector<Trade>& trades) {
    for (auto* subscriber : subscribers) {
        subscriber->onQuoteUpdate(quotes);   // Notify each subscriber with new quotes
        subscriber->onTradeUpdate(trades);   // Notify each subscriber with new trades
    }
}

// Simulate an incoming market data message (for testing)
std::string MarketDataFeed::simulateIncomingMessage() const {
    return "FIX message: Sample trade data";
}
