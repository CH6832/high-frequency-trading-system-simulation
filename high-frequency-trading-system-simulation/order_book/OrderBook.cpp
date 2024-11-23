// order_book/OrderBook.cpp

#include "OrderBook.hpp"
#include <iostream>

// Add an order to the order book
void OrderBook::addOrder(const Order& order) {
    orders.push_back(order);
    std::cout << "Order added: " << order.orderID << " - " << order.symbol << " "
        << (order.isBuy ? "Buy" : "Sell") << " " << order.volume << " @ "
        << order.price << std::endl;
}

// Remove an order from the order book by order ID
void OrderBook::removeOrder(const std::string& orderID) {
    auto it = std::remove_if(orders.begin(), orders.end(),
        [&orderID](const Order& order) { return order.orderID == orderID; });

    if (it != orders.end()) {
        orders.erase(it, orders.end());
        std::cout << "Order removed: " << orderID << std::endl;
    }
    else {
        std::cout << "Order not found: " << orderID << std::endl;
    }
}

// Display the current state of the order book
void OrderBook::displayOrders() const {
    std::cout << "Current Orders in the Order Book:" << std::endl;
    for (const auto& order : orders) {
        std::cout << "Order ID: " << order.orderID << ", Symbol: " << order.symbol
            << ", Price: " << order.price << ", Volume: " << order.volume
            << ", Type: " << (order.isBuy ? "Buy" : "Sell") << std::endl;
    }
}
