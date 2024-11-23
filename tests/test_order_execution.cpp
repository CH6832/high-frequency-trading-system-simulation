// tests/test_order_execution.cpp

#include "../order_execution/OrderExecutionEngine.hpp"
#include <cassert>
#include <iostream>

void testOrderExecution() {
    OrderExecutionEngine engine;
    Order order("AAPL", 150.0, 10, OrderType::BUY);
    bool executed = engine.executeOrder(order);

    assert(executed == true);
    std::cout << "Order execution test passed!" << std::endl;
}

void runOrderExecutionTests() {
    testOrderExecution();
}
