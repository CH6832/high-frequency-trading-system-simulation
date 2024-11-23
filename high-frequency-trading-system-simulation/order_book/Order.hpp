#pragma once
// order_book/Order.hpp

#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>

/// Structure to represent an order in the order book
struct Order {
    std::string orderID;   // Unique identifier for the order
    std::string symbol;     // Ticker symbol for the asset
    double price;           // Price at which the order is placed
    int volume;             // Volume of the order
    bool isBuy;             // True if it's a buy order, false for sell order

    // Constructor for creating an order
    Order(const std::string& orderID, const std::string& symbol, double price, int volume, bool isBuy)
        : orderID(orderID), symbol(symbol), price(price), volume(volume), isBuy(isBuy) {}
};

#endif // ORDER_HPP
