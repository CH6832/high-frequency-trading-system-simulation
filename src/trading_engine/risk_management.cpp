#include "risk_management.h"
#include <iostream>

void RiskManagement::checkRisk(double positionSize) {
    const double maxPositionSize = 10000.0; // Example limit
    if (positionSize > maxPositionSize) {
        std::cout << "Risk warning: Position size exceeds maximum allowed limit." << std::endl;
    }
}
