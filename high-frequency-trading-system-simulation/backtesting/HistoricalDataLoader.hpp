#pragma once

#ifndef HISTORICALDATALOADER_HPP
#define HISTORICALDATALOADER_HPP

#include <string>
#include <vector>
#include "../market_data_feed/MarketDataFeed.hpp"
#include "../historical_data/DataFormats.hpp"

/// Class responsible for loading historical market data from a file
class HistoricalDataLoader {
public:
    /// Load historical market data from the specified file
    std::vector<MarketData> load(const std::string& filepath);
};

#endif // HISTORICALDATALOADER_HPP
