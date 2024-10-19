#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include <vector>

class DataProcessor {
public:
    static std::vector<double> normalizeData(const std::vector<double>& data);
};

#endif // DATA_PROCESSOR_H
