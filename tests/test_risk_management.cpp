// tests/test_risk_management.cpp

#include "../risk_management/RiskManager.hpp"
#include <cassert>
#include <iostream>

void testRiskManagement() {
    RiskManager riskManager;
    double risk = riskManager.calculateRisk(10000.0, 0.02); // Example calculation

    assert(risk == 200.0); // Assuming this is the expected risk calculation
    std::cout << "Risk management test passed!" << std::endl;
}

void runRiskManagementTests() {
    testRiskManagement();
}
