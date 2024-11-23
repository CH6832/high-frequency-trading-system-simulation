#include "OrderExecutionEngine.hpp"
#include "RDMAConnection.hpp"
#include "../order_book/Order.hpp"

OrderExecutionEngine::OrderExecutionEngine()
    : rdmaConnection(std::make_unique<RDMAConnection>()) {}

OrderExecutionEngine::~OrderExecutionEngine() {
    disconnectFromExchange();
}

bool OrderExecutionEngine::connectToExchange() {
    std::cout << "Connecting to exchange via RDMA..." << std::endl;
    return rdmaConnection->connect();
}

void OrderExecutionEngine::disconnectFromExchange() {
    std::cout << "Disconnecting from exchange..." << std::endl;
    rdmaConnection->disconnect();
}

bool OrderExecutionEngine::submitOrder(const Order& order) {
    if (!rdmaConnection->isConnected()) {
        std::cerr << "Not connected to exchange. Cannot submit order." << std::endl;
        return false;
    }
    std::cout << "Submitting order ID " << order.orderID << " for " << order.symbol
        << " with quantity " << order.volume << std::endl;
    // Simulate order submission logic
    return true;
}

bool OrderExecutionEngine::cancelOrder(const std::string& orderId) {
    if (!rdmaConnection->isConnected()) {
        std::cerr << "Not connected to exchange. Cannot cancel order." << std::endl;
        return false;
    }
    std::cout << "Cancelling order ID " << orderId << std::endl;
    // Simulate order cancellation logic
    return true;
}
