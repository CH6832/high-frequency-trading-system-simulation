// tests/test_market_data_feed.cpp

#include "../market_data_feed/MarketDataProtocols.hpp"
#include <cassert>
#include <iostream>

void testQuoteCreation() {
    Quote q("AAPL", 150.0, 100);
    assert(q.symbol == "AAPL");
    assert(q.price == 150.0);
    assert(q.volume == 100);
    std::cout << "Quote creation test passed!" << std::endl;
}

void testTradeCreation() {
    Trade t("AAPL", 150.0, 10, "TRD123");
    assert(t.symbol == "AAPL");
    assert(t.price == 150.0);
    assert(t.volume == 10);
    assert(t.tradeID == "TRD123");
    std::cout << "Trade creation test passed!" << std::endl;
}

void runMarketDataFeedTests() {
    testQuoteCreation();
    testTradeCreation();
}
