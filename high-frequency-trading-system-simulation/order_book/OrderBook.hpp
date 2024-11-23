#pragma once
// order_book/OrderBook.hpp

#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include <vector>
#include <string>
#include "Order.hpp"

/// Class to manage an order book
class OrderBook {
public:
    // Add an order to the order book
    void addOrder(const Order& order);

    // Remove an order from the order book by order ID
    void removeOrder(const std::string& orderID);

    // Display the current state of the order book
    void displayOrders() const;

private:
    std::vector<Order> orders;  // Container for all orders
};

#endif // ORDERBOOK_HPP
