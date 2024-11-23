# CMakeList.txt : CMake project for high-frequency-trading-system-simulation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (high-frequency-trading-system-simulation "high-frequency-trading-system-simulation.cpp"  "market_data_feed/MarketDataFeed.cpp" "order_book/OrderBook.cpp" "trading_strategy/MarketMakingStrategy.cpp" "trading_strategy/TradingStrategy.cpp" "trading_strategy/TrendFollowingStrategy.cpp" "order_execution/OrderExecutionEngine.cpp" "risk_management/RiskManager.cpp" "monitoring/Monitoring.cpp" "backtesting/BacktestingEngine.cpp" "backtesting/HistoricalDataLoader.cpp" "historical_data/HistoricalDataStore.cpp" "utils/Logger.cpp" "utils/ConfigManager.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET high-frequency-trading-system-simulation PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
