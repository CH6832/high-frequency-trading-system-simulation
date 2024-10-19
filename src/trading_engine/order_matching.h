#ifndef ORDER_MATCHING_H
#define ORDER_MATCHING_H

#include <string>
#include <queue>
#include <unordered_map>
#include <stdexcept>
#include "execution.h"

class Order {
public:
    std::string id;      ///< Unique identifier for the order
    double price;        ///< Price of the order
    int quantity;        ///< Quantity of the order
    bool isBuy;          ///< True if buy order, false if sell order

    Order(const std::string& id, double price, int quantity, bool isBuy);
    bool operator<(const Order& other) const; // For priority queue comparison
};

class OrderMatching {
public:
    void addOrder(const Order& order);
    void matchOrders();

private:
    std::priority_queue<Order> buyOrders;   ///< Max heap for buy orders
    std::priority_queue<Order, std::vector<Order>, std::greater<Order>> sellOrders; // Min heap for sell orders

    void executeTrade(const Order& buyOrder, const Order& sellOrder);
};

#endif // ORDER_MATCHING_H
