#ifndef EXECUTION_H
#define EXECUTION_H

#include <string>
#include <iostream>
#include <stdexcept>

class Execution {
public:
    void executeOrder(const std::string& orderId, double price, int quantity);
};

#endif // EXECUTION_H
