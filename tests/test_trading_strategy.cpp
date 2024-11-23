// tests/test_trading_strategy.cpp

#include "../trading_strategy/TradingStrategy.hpp"
#include <cassert>
#include <iostream>

class MockStrategy : public TradingStrategy {
public:
    std::vector<Order> generateOrders(const std::vector<Quote>& marketData) override {
        return { Order("AAPL", 150.0, 10, OrderType::BUY) };
    }
};

void testTradingStrategy() {
    MockStrategy strategy;
    std::vector<Quote> marketData = { Quote("AAPL", 150.0, 100) };
    auto orders = strategy.generateOrders(marketData);

    assert(orders.size() == 1);
    assert(orders[0].symbol == "AAPL");
    assert(orders[0].price == 150.0);
    assert(orders[0].volume == 10);

    std::cout << "Trading strategy test passed!" << std::endl;
}

void runTradingStrategyTests() {
    testTradingStrategy();
}
