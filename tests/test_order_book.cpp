// tests/test_order_book.cpp

#include "../order_book/OrderBook.hpp"
#include <cassert>
#include <iostream>

void testOrderBookFunctionality() {
    OrderBook orderBook;

    Order order1("AAPL", 150.0, 10, OrderType::BUY);
    orderBook.addOrder(order1);

    auto orders = orderBook.getOrders();
    assert(orders.size() == 1);
    assert(orders[0].symbol == "AAPL");
    assert(orders[0].price == 150.0);
    assert(orders[0].volume == 10);

    std::cout << "Order book test passed!" << std::endl;
}

void runOrderBookTests() {
    testOrderBookFunctionality();
}
