#pragma once

#ifndef RISKMANAGER_HPP
#define RISKMANAGER_HPP

#include "RiskPolicies.hpp"
#include "../order_book/Order.hpp"
#include <string>

/// Class to handle risk management checks before order execution
class RiskManager {
public:
    /// Constructor with risk policy initialization
    RiskManager(const RiskPolicies& policies);

    /// Evaluate whether an order passes all risk checks
    bool evaluateOrder(const Order& order) const;

    /// Update risk policies dynamically
    void updatePolicies(const RiskPolicies& newPolicies);

private:
    RiskPolicies policies;  // Holds the set of risk policies to enforce
    bool checkPositionLimit(const Order& order) const;
    bool checkOrderSizeLimit(const Order& order) const;
    bool checkPriceLimit(const Order& order) const;
};

#endif // RISKMANAGER_HPP
