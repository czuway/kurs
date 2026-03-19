#pragma once
#include "Sensor.h"
#include "Generator.h"
#include <array>
#include <mutex>

class TemperatureSensor : public Sensor, public Generator
{
private:
    std::array<uint8_t, 4> value;
    std::mutex mtx;

public:
    TemperatureSensor();
    void generate() override;
    std::array<uint8_t, 4> readValue() override;
    int getType() override;
};
