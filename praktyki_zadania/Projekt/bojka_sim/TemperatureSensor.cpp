#include "TemperatureSensor.h"
#include "Utils.h"  // floatToBytes / bytesToFloat
#include <random>
#include <chrono>

void TemperatureSensor::generate()
{
    std::lock_guard<std::mutex> lock(mtx);

    // generowanie losowej temperatury 20-30 stopni
    static std::default_random_engine eng(
        std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_real_distribution<float> dist(20.0f, 30.0f);

    temp = dist(eng);
}

std::vector<unsigned char> TemperatureSensor::readValue()
{
    std::lock_guard<std::mutex> lock(mtx);
    return floatToBytes(temp);
}

int TemperatureSensor::getType() const
{
    return 1; // typ 1 = temperatura
}
