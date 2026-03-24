#pragma once
#include "Generator.h"
#include <vector>
#include <mutex>

class PressureSensor : public Generator {
public:
    PressureSensor() = default;
    ~PressureSensor() override = default;

    void generate() override;
    std::vector<unsigned char> readValue() override;
    int getType() const override;

private:
    float pressure = 1013.25f; // domyœlne ciœnienie
    mutable std::mutex mtx;
};
