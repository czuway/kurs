#pragma once
#include <array>
#include <cstdint>

//interfejs bazowy dla wszystkich sensorow
class Sensor
{
public:
    virtual std::array<uint8_t, 4> readValue() = 0;

    virtual int getType() = 0;

    virtual ~Sensor() = default;
};
