// momentum.h
#ifndef MOMENTUM_H
#define MOMENTUM_H

#include <vector>
#include "logger.h"

class MomentumStrategy {
public:
    MomentumStrategy(double threshold) : threshold(threshold) {}

    std::vector<int> generateSignals(const std::vector<double>& prices) {
        std::vector<int> signals(prices.size(), 0);
        for (size_t i = 1; i < prices.size(); ++i) {
            double momentum = prices[i] - prices[i - 1];

            if (momentum > threshold) {
                signals[i] = 1;  // Buy signal
                Logger::log("Momentum Signal: Buy at price " + std::to_string(prices[i]));
            } else if (momentum < -threshold) {
                signals[i] = -1; // Sell signal
                Logger::log("Momentum Signal: Sell at price " + std::to_string(prices[i]));
            }
        }
        return signals;
    }

private:
    double threshold;
};

#endif // MOMENTUM_H
