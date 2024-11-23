// tests/test_backtesting.cpp

#include "../backtesting/BacktestingEngine.hpp"
#include <cassert>
#include <iostream>

void testBacktesting() {
    MockStrategy strategy;
    BacktestingEngine engine(&strategy);
    engine.loadHistoricalData("path/to/historical_data.csv");

    engine.runBacktest();
    std::cout << "Backtesting test passed!" << std::endl;
}

void runBacktestingTests() {
    testBacktesting();
}
