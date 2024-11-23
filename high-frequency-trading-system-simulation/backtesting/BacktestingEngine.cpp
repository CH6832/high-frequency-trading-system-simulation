#include "BacktestingEngine.hpp"
#include <iostream>
#include "../trading_strategy/TradingStrategy.hpp"
#include "../market_data_feed/MarketDataFeed.hpp"
#include "../order_book/Order.hpp"
#include "../backtesting/HistoricalDataLoader.hpp"  // Ensure this is included

// Constructor
BacktestingEngine::BacktestingEngine(TradingStrategy* strategy)
    : strategy(strategy), accountBalance(100000.0) // Initialize with a default balance
{
}

void BacktestingEngine::loadHistoricalData(const std::string& filepath) {
    HistoricalDataLoader loader;
    historicalData = loader.load(filepath);
    std::cout << "Loaded " << historicalData.size() << " data points from " << filepath << std::endl;
}

// Add market data directly to the historical data vector
void BacktestingEngine::addMarketData(const MarketData& data) {
    historicalData.push_back(data); // Ensure data type matches
}

// Updated method to use quotes correctly
void BacktestingEngine::runBacktest() {
    for (const auto& marketData : historicalData) {
        // Create a Quote from the MarketData to generate orders
        Quote quote(marketData.symbol, marketData.price, marketData.volume);

        // Generate orders based on the strategy
        auto orders = strategy->generateOrders({ quote }); // Pass vector with one Quote

        // Process each order as part of the backtest
        for (const auto& order : orders) {
            std::cout << "Order generated - Symbol: " << order.symbol
                << ", Quantity: " << order.volume
                << ", Price: " << order.price << std::endl;

            // Logic to simulate order execution in backtest environment
            // (such as updating a virtual order book or portfolio)
        }
    }
}
