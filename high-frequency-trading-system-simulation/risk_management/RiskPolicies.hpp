#pragma once

#ifndef RISKPOLICIES_HPP
#define RISKPOLICIES_HPP

/// Struct defining the risk policies for the trading system
struct RiskPolicies {
    int maxPositionLimit;   // Maximum allowable position size for any asset
    int maxOrderSize;       // Maximum allowable size for a single order
    double minOrderPrice;   // Minimum allowable price for an order
    double maxOrderPrice;   // Maximum allowable price for an order

    /// Default constructor with example policy values
    RiskPolicies(int posLimit = 1000, int orderSize = 100, double minPrice = 1.0, double maxPrice = 10000.0)
        : maxPositionLimit(posLimit), maxOrderSize(orderSize), minOrderPrice(minPrice), maxOrderPrice(maxPrice) {}
};

#endif // RISKPOLICIES_HPP
