// main.cpp

#include <iostream>
#include <vector>
#include "order_book/OrderBook.hpp"
#include "market_data_feed/MarketDataProtocols.hpp"
#include "trading_strategy/StrategyFactory.hpp"
#include "backtesting/BacktestingEngine.hpp"
#include "order_execution/OrderExecutionEngine.hpp"

// Function to generate dummy historical market data for the simulation
std::vector<MarketData> generateDummyMarketData(int numTrades) {
    std::vector<MarketData> marketData;

    // Generate sample market data
    for (int i = 0; i < numTrades; ++i) {
        // Simulate some market data: timestamp, symbol, price, volume
        MarketData data = {
            "2024-11-04 10:00:00",  // Simulated timestamp
            (i % 2 == 0) ? "AAPL" : "GOOGL",  // Alternate between two symbols
            150.0 + (rand() % 1000) / 100.0, // Random price between 150.0 and 1600.0
            rand() % 1000 + 1  // Random volume between 1 and 1000
        };
        marketData.push_back(data);
    }

    return marketData;
}

int main() {
    // Set the number of trades for the simulation
    const int NUM_TRADES = 1000000;

    // Create an instance of a trend-following strategy
    TrendFollowingStrategy trendStrategy; // Ensure this is correctly defined

    // Initialize the backtesting engine with the chosen strategy
    BacktestingEngine backtestingEngine(&trendStrategy);

    // Generate dummy historical market data
    std::vector<MarketData> historicalData = generateDummyMarketData(NUM_TRADES);

    // Load the generated historical data into the backtesting engine
    for (const auto& data : historicalData) {
        backtestingEngine.addMarketData(data);  // Assuming addMarketData method exists
    }

    // Run the backtest with the generated data
    backtestingEngine.runBacktest();

    // Initialize OrderBook to manage orders
    OrderBook orderBook;

    // Simulate the creation of buy and sell orders
    orderBook.addOrder(Order("ORD001", "AAPL", 150.0, 100, true));   // Buy order
    orderBook.addOrder(Order("ORD002", "GOOGL", 2800.0, 50, false)); // Sell order

    // Display the orders in the order book
    std::cout << "Current Orders in the Order Book:" << std::endl;
    orderBook.displayOrders();

    // Remove an order from the order book
    orderBook.removeOrder("ORD001");

    // Display orders after removal
    std::cout << "Orders after removal:" << std::endl;
    orderBook.displayOrders();

    // Create an example market-making strategy and execute it with the generated quotes
    auto marketMakingStrategy = StrategyFactory::createStrategy(StrategyType::MARKET_MAKING);
    std::vector<Quote> quotes = { Quote("AAPL", 150.0, 100), Quote("GOOGL", 2800.0, 50) };
    std::vector<Trade> trades; // Assuming trades will be populated by other components
    marketMakingStrategy->execute(quotes, trades);

    // Final output message to indicate successful completion
    std::cout << "Simulation completed successfully with " << NUM_TRADES << " trades." << std::endl;

    return 0;
}
