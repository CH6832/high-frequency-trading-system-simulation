// main.cpp
#include <iostream>
#include <vector>
#include "mean_reversion.h"
#include "momentum.h"

int main() {
    // Sample price data
    std::vector<double> prices = {100.0, 101.0, 102.0, 100.0, 98.0, 99.0, 97.0, 98.5, 100.0, 101.5};

    // Mean Reversion Strategy
    MeanReversionStrategy meanReversion(3, 1.0, 0.0); // lookback, entry threshold, exit threshold
    std::vector<int> meanReversionSignals = meanReversion.generateSignals(prices);

    // Momentum Strategy
    MomentumStrategy momentum(1.0); // threshold
    std::vector<int> momentumSignals = momentum.generateSignals(prices);

    // Output signals for each strategy
    std::cout << "Mean Reversion Signals: ";
    for (const auto& signal : meanReversionSignals) {
        std::cout << signal << " ";
    }
    std::cout << std::endl;

    std::cout << "Momentum Signals: ";
    for (const auto& signal : momentumSignals) {
        std::cout << signal << " ";
    }
    std::cout << std::endl;

    return 0;
}
