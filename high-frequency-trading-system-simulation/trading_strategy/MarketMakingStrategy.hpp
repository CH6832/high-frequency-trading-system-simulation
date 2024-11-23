#pragma once
// trading_strategy/MarketMakingStrategy.hpp

#include "TradingStrategy.hpp"
#include <vector>

class MarketMakingStrategy : public TradingStrategy {
public:
    // Implementation of the pure virtual function
    // std::vector<Order> generateOrders(const std::vector<Quote>& quotes) const override;
    std::vector<Order> generateOrders(const std::vector<Quote>& quotes);
    // std::vector<Order> generateOrders(const std::vector<Quote>& quotes) override;
};
