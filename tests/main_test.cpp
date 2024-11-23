// tests/main_test.cpp

#include <iostream>

// Function declarations for running tests
void runMarketDataFeedTests();
void runOrderBookTests();
void runTradingStrategyTests();
void runOrderExecutionTests();
void runRiskManagementTests();
void runMonitoringTests();
void runBacktestingTests();

int main() {
    runMarketDataFeedTests();
    runOrderBookTests();
    runTradingStrategyTests();
    runOrderExecutionTests();
    runRiskManagementTests();
    runMonitoringTests();
    runBacktestingTests();

    std::cout << "All tests completed successfully!" << std::endl;
    return 0;
}
