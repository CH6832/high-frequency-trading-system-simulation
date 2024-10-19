// mean_reversion.h
#ifndef MEAN_REVERSION_H
#define MEAN_REVERSION_H

#include <vector>
#include <numeric>
#include "logger.h"

class MeanReversionStrategy {
public:
    MeanReversionStrategy(int lookback_period, double entry_threshold, double exit_threshold)
        : lookback_period(lookback_period), entry_threshold(entry_threshold), exit_threshold(exit_threshold) {}

    std::vector<int> generateSignals(const std::vector<double>& prices) {
        std::vector<int> signals(prices.size(), 0);
        for (size_t i = lookback_period; i < prices.size(); ++i) {
            double mean_price = calculateMean(prices, i);
            double std_dev = calculateStdDev(prices, mean_price, i);

            double z_score = (prices[i] - mean_price) / std_dev;

            if (z_score > entry_threshold) {
                signals[i] = -1;  // Sell signal
                Logger::log("Mean Reversion Signal: Sell at price " + std::to_string(prices[i]));
            } else if (z_score < -entry_threshold) {
                signals[i] = 1;   // Buy signal
                Logger::log("Mean Reversion Signal: Buy at price " + std::to_string(prices[i]));
            } else if (std::abs(z_score) < exit_threshold) {
                signals[i] = 0;   // Exit signal
                Logger::log("Mean Reversion Signal: Exit at price " + std::to_string(prices[i]));
            }
        }
        return signals;
    }

private:
    int lookback_period;
    double entry_threshold;
    double exit_threshold;

    double calculateMean(const std::vector<double>& prices, size_t index) {
        double sum = std::accumulate(prices.begin() + index - lookback_period, prices.begin() + index, 0.0);
        return sum / lookback_period;
    }

    double calculateStdDev(const std::vector<double>& prices, double mean, size_t index) {
        double sum = 0.0;
        for (size_t j = index - lookback_period; j < index; ++j) {
            sum += (prices[j] - mean) * (prices[j] - mean);
        }
        return std::sqrt(sum / lookback_period);
    }
};

#endif // MEAN_REVERSION_H
