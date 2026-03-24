#pragma once
#include <vector>
#include <cstring>

inline std::vector<unsigned char> floatToBytes(float value)
{
    std::vector<unsigned char> bytes(sizeof(float));
    std::memcpy(bytes.data(), &value, sizeof(float));
    return bytes;
}

inline float bytesToFloat(const std::vector<unsigned char>& bytes)
{
    float value;
    std::memcpy(&value, bytes.data(), sizeof(float));
    return value;
}
