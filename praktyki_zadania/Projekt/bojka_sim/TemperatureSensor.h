#pragma once
#include "Generator.h"
#include <vector>
#include <mutex>

class TemperatureSensor : public Generator {
public:
    TemperatureSensor() = default;
    ~TemperatureSensor() override = default;

    void generate() override;
    std::vector<unsigned char> readValue() override;
    int getType() const override;

private:
    float temp = 25.0f;
    mutable std::mutex mtx;
};
