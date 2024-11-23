#include "RiskManager.hpp"
#include <iostream>
#include "../order_book/Order.hpp"

RiskManager::RiskManager(const RiskPolicies& policies) : policies(policies) {}

bool RiskManager::evaluateOrder(const Order& order) const {
    if (!checkPositionLimit(order)) {
        std::cerr << "Order rejected: Position limit exceeded for " << order.symbol << std::endl;
        return false;
    }
    if (!checkOrderSizeLimit(order)) {
        std::cerr << "Order rejected: Order size limit exceeded for " << order.symbol << std::endl;
        return false;
    }
    if (!checkPriceLimit(order)) {
        std::cerr << "Order rejected: Price limit breached for " << order.symbol << std::endl;
        return false;
    }
    return true;
}

void RiskManager::updatePolicies(const RiskPolicies& newPolicies) {
    policies = newPolicies;
}

bool RiskManager::checkPositionLimit(const Order& order) const {
    // Placeholder: Checks total position limit for the asset
    return order.volume <= policies.maxPositionLimit;
}

bool RiskManager::checkOrderSizeLimit(const Order& order) const {
    // Placeholder: Checks if order size does not exceed allowed size
    return order.volume <= policies.maxOrderSize;
}

bool RiskManager::checkPriceLimit(const Order& order) const {
    // Placeholder: Ensures the price is within acceptable range
    return order.price >= policies.minOrderPrice && order.price <= policies.maxOrderPrice;
}
