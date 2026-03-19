#pragma once
#include <array>
#include <cstring>

inline std::array<uint8_t, 4> floatToBytes(float value)
{
    std::array<uint8_t, 4> data;
    std::memcpy(data.data(), &value, sizeof(float));
    return data;
}

inline float bytesToFloat(const std::array<uint8_t, 4>& data)
{
    float value;
    std::memcpy(&value, data.data(), sizeof(float));
    return value;
}
