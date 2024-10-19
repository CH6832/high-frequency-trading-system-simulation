#include "data_processor.h"
#include <stdexcept>
#include <algorithm>

std::vector<double> DataProcessor::normalizeData(const std::vector<double>& data) {
    if (data.empty()) {
        throw std::invalid_argument("Data vector is empty");
    }

    double min = *std::min_element(data.begin(), data.end());
    double max = *std::max_element(data.begin(), data.end());

    std::vector<double> normalized(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        normalized[i] = (data[i] - min) / (max - min);
    }
    return normalized;
}
