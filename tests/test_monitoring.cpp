// tests/test_monitoring.cpp

#include "../monitoring/Monitoring.hpp"
#include <cassert>
#include <iostream>

void testMonitoring() {
    Monitoring monitor;
    monitor.recordEvent("OrderExecuted", "Order AAPL executed successfully");

    auto events = monitor.getEvents();
    assert(events.size() == 1);
    assert(events[0] == "OrderExecuted: Order AAPL executed successfully");
    std::cout << "Monitoring test passed!" << std::endl;
}

void runMonitoringTests() {
    testMonitoring();
}
