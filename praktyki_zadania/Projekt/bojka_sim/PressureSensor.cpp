#include "PressureSensor.h"
#include "Utils.h"
#include <random>
#include <chrono>

void PressureSensor::generate()
{
    std::lock_guard<std::mutex> lock(mtx);

    static std::default_random_engine eng(
        std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_real_distribution<float> dist(980.0f, 1050.0f);

    pressure = dist(eng);
}

std::vector<unsigned char> PressureSensor::readValue()
{
    std::lock_guard<std::mutex> lock(mtx);
    return floatToBytes(pressure);
}

int PressureSensor::getType() const
{
    return 3; // typ 3 = ciśnienie
}
