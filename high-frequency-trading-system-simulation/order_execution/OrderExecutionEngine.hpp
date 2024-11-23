#pragma once

#ifndef ORDER_EXECUTION_ENGINE_HPP
#define ORDER_EXECUTION_ENGINE_HPP

#include "../order_book/Order.hpp"
#include <string>
#include <memory>
#include <iostream>

/// The OrderExecutionEngine class handles the execution of orders, simulating order
/// submission, cancellation, and RDMA-based communication.
class OrderExecutionEngine {
public:
    OrderExecutionEngine();
    ~OrderExecutionEngine();

    // Method to submit an order to the market
    bool submitOrder(const Order& order);

    // Method to cancel an existing order
    bool cancelOrder(const std::string& orderId);

    // Connect to the order execution system via RDMA
    bool connectToExchange();

    // Disconnect from the order execution system
    void disconnectFromExchange();

private:
    std::unique_ptr<class RDMAConnection> rdmaConnection; // RDMA connection handler
};

#endif // ORDER_EXECUTION_ENGINE_HPP
