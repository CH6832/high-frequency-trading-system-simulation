#include "order_matching.h"
#include <iostream>
#include <stdexcept>

// Order constructor
Order::Order(const std::string& id, double price, int quantity, bool isBuy)
    : id(id), price(price), quantity(quantity), isBuy(isBuy) {}

// Comparison operator for ordering
bool Order::operator<(const Order& other) const {
    return (isBuy) ? price < other.price : price > other.price; // Buy orders are max heap, sell orders are min heap
}

void OrderMatching::addOrder(const Order& order) {
    if (order.quantity <= 0) {
        throw std::invalid_argument("Order quantity must be greater than zero");
    }
    if (order.isBuy) {
        buyOrders.push(order);
    } else {
        sellOrders.push(order);
    }
}

void OrderMatching::matchOrders() {
    while (!buyOrders.empty() && !sellOrders.empty()) {
        const Order& buyOrder = buyOrders.top();
        const Order& sellOrder = sellOrders.top();

        // Check if the buy order can match with the sell order
        if (buyOrder.price >= sellOrder.price) {
            executeTrade(buyOrder, sellOrder);
        } else {
            break; // No more matches possible
        }
    }
}

void OrderMatching::executeTrade(const Order& buyOrder, const Order& sellOrder) {
    int tradeQuantity = std::min(buyOrder.quantity, sellOrder.quantity);
    std::cout << "Executing trade: " << tradeQuantity << " units at price " << sellOrder.price << std::endl;

    // Update quantities
    int updatedBuyQuantity = buyOrder.quantity - tradeQuantity;
    int updatedSellQuantity = sellOrder.quantity - tradeQuantity;

    // Remove orders if fully executed
    if (updatedBuyQuantity == 0) {
        buyOrders.pop();
    }
    if (updatedSellQuantity == 0) {
        sellOrders.pop();
    }
}
