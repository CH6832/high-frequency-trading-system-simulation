# pragma once
// trading/TradingStrategy.hpp

#ifndef TRADINGSTRATEGY_HPP
#define TRADINGSTRATEGY_HPP

#include <vector>
#include "../market_data_feed/MarketDataProtocols.hpp"
#include "../order_book/Order.hpp"
#include "../historical_data/DataFormats.hpp"

/// Base class for trading strategies
class TradingStrategy {
public:
    virtual ~TradingStrategy() = default; // Virtual destructor for cleanup
    void log(const std::string& message);
    virtual void execute(const std::vector<Quote>& quotes, const std::vector<Trade>& trades) = 0; // Pure virtual function
    virtual std::vector<Order> generateOrders(const std::vector<Quote>& quotes) = 0; // Pure virtual
    // virtual std::vector<Order> generateOrders(const std::vector<Quote>& quotes) const = 0;
    virtual void updateMarketData(const Quote& quote) = 0; // Example additional pure virtual function
    virtual void onMarketData(const MarketData& data) = 0; // Example of another pure virtual function
};

#endif // TRADINGSTRATEGY_HPP
