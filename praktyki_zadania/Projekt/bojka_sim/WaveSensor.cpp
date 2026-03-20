#include "WaveSensor.h"
#include "Utils.h"
#include <cstdlib>

WaveSensor::WaveSensor()
{
    value = {0, 0, 0, 0};
}

void WaveSensor::generate()
{
    std::lock_guard<std::mutex> lock(mtx);

    float wave = (rand() % 500) / 100.0f;


    value = floatToBytes(wave);
}

std::array<uint8_t, 4> WaveSensor::readValue()
{
    std::lock_guard<std::mutex> lock(mtx);
    return value;
}

int WaveSensor::getType()
{
    return 2;
