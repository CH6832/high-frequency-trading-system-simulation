#pragma once

#ifndef TREND_FOLLOWING_STRATEGY_HPP
#define TREND_FOLLOWING_STRATEGY_HPP

#include "TradingStrategy.hpp"
#include <vector>
#include "../market_data_feed/MarketDataFeed.hpp"
#include "../order_book/Order.hpp"

class TrendFollowingStrategy : public TradingStrategy {
public:
    TrendFollowingStrategy(); // Constructor
    void execute(const std::vector<Quote>& quotes, const std::vector<Trade>& trades) override; // Override method
    std::vector<Order> generateOrders(const std::vector<Quote>& quotes) override;
    void updateMarketData(const Quote& quote) override; // Example additional implementation
    void onMarketData(const MarketData& data) override;  // Add this if it exists in the base class
};

#endif // TREND_FOLLOWING_STRATEGY_HPP
