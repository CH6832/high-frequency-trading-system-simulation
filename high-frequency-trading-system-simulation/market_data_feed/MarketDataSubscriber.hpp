// market_data_feed/MarketDataSubscriber.hpp
#pragma once

#ifndef MARKETDATASUBSCRIBER_HPP
#define MARKETDATASUBSCRIBER_HPP

#include <vector>
// #include "MarketDataFeed.hpp"

class MarketDataSubscriber {
public:
    virtual void onQuoteUpdate(const std::vector<Quote>& quotes) = 0;
    virtual void onTradeUpdate(const std::vector<Trade>& trades) = 0;
    virtual ~MarketDataSubscriber() = default;
};

#endif // MARKETDATASUBSCRIBER_HPP
