#pragma once

#ifndef BACKTESTINGENGINE_HPP
#define BACKTESTINGENGINE_HPP

#include <vector>
#include "../trading_strategy/TradingStrategy.hpp"
#include "../market_data_feed/MarketDataProtocols.hpp" // Ensure this includes the definition of MarketData
#include "../historical_data/DataFormats.hpp"

class BacktestingEngine {
public:
    BacktestingEngine(TradingStrategy* strategy);
    void loadHistoricalData(const std::string& filepath);
    void addMarketData(const MarketData& data);
    void runBacktest();

private:
    TradingStrategy* strategy;
    double accountBalance;
    std::vector<MarketData> historicalData; // Ensure this is declared properly
};

#endif // BACKTESTINGENGINE_HPP
