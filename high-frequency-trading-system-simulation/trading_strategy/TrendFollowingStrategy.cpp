// trading/TrendFollowingStrategy.cpp

#include "TradingStrategy.hpp"
#include "TrendFollowingStrategy.hpp"
#include <iostream>
#include "../historical_data/DataFormats.hpp"


// Implement the constructor if needed
TrendFollowingStrategy::TrendFollowingStrategy() {
    // Initialization code (if any)
}

// Implement the execute method from the TradingStrategy base class
void TrendFollowingStrategy::execute(const std::vector<Quote>& quotes, const std::vector<Trade>& trades) {
    // Simple trend-following logic (for illustration purposes)
    for (const auto& quote : quotes) {
        std::cout << "Trend Following Strategy: Analyzing quote for " << quote.symbol
            << " at price " << quote.price << std::endl;

        // Example logic: buy if the price is below a certain threshold
        if (quote.price < 100.0) {
            std::cout << "Buying " << quote.symbol << " at price " << quote.price << std::endl;
        }
        else {
            std::cout << "No action on " << quote.symbol << std::endl;
        }
    }
}

//std::vector<Order> TrendFollowingStrategy::generateOrders(const std::vector<Quote>& quotes) {
//    std::vector<Order> orders;
//
//    // Simple trend-following example: buy if price is below threshold
//    for (const auto& quote : quotes) {
//        if (quote.price < 100.0) {
//            orders.emplace_back("OrderID1", quote.symbol, quote.price, 100, true);  // Buy order
//        }
//        else {
//            std::cout << "Trend Following Strategy: No action on " << quote.symbol << std::endl;
//        }
//    }
//    return orders;
//}

void TrendFollowingStrategy::updateMarketData(const Quote& quote)
{
}

// Implement generateOrders
std::vector<Order> TrendFollowingStrategy::generateOrders(const std::vector<Quote>& quotes) {
    std::vector<Order> orders;

    for (const auto& quote : quotes) {
        if (quote.price < 100.0) {
            orders.emplace_back("OrderID1", quote.symbol, quote.price, 100, true);  // Example buy order
        }
        else {
            std::cout << "Trend Following Strategy: No action on " << quote.symbol << std::endl;
        }
    }

    return orders;
}

void TrendFollowingStrategy::onMarketData(const MarketData& data)
{
    // Process market data in some way for this strategy
    std::cout << "TrendFollowingStrategy received market data for "
        << data.symbol << " with price " << data.price << std::endl;
}
