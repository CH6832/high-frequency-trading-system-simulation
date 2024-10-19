import unittest
from trading_engine.order_matching import Order, OrderMatching

class TestOrderMatching(unittest.TestCase):
    def setUp(self):
        self.engine = OrderMatching()

    def test_order_matching(self):
        order1 = Order("1", 100, 10, True)
        order2 = Order("2", 90, 5, False)
        self.engine.addOrder(order1)
        self.engine.addOrder(order2)
        self.engine.matchOrders()  # Should execute trade

    def test_order_quantity_zero(self):
        with self.assertRaises(ValueError):
            order = Order("3", 100, 0, True)
            self.engine.addOrder(order)

if __name__ == "__main__":
    unittest.main()
