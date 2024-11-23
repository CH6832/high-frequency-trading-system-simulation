#pragma once
// trading/StrategyFactory.hpp

#ifndef STRATEGYFACTORY_HPP
#define STRATEGYFACTORY_HPP

#include "TradingStrategy.hpp"
#include <memory>
#include "TrendFollowingStrategy.cpp"
#include "MarketMakingStrategy.cpp"

/// Enum to specify different trading strategies
enum class StrategyType {
    TREND_FOLLOWING,
    MARKET_MAKING
};

/// Factory class for creating trading strategies
class StrategyFactory {
public:
    static std::unique_ptr<TradingStrategy> createStrategy(StrategyType type) {
        switch (type) {
        case StrategyType::TREND_FOLLOWING:
            return std::make_unique<TrendFollowingStrategy>();
        case StrategyType::MARKET_MAKING:
            return std::make_unique<MarketMakingStrategy>();
        default:
            return nullptr; // or throw an exception
        }
    }
};

#endif // STRATEGYFACTORY_HPP
