#include "execution.h"

void Execution::executeOrder(const std::string& orderId, double price, int quantity) {
    if (quantity <= 0) {
        throw std::invalid_argument("Order quantity must be greater than zero");
    }
    std::cout << "Order executed: " << orderId << " | Price: " << price << " | Quantity: " << quantity << std::endl;
}
