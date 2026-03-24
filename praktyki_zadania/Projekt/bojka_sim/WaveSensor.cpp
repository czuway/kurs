#include "WaveSensor.h"
#include "Utils.h"
#include <random>
#include <chrono>

void WaveSensor::generate()
{
    std::lock_guard<std::mutex> lock(mtx);

    static std::default_random_engine eng(
        std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_real_distribution<float> dist(0.0f, 3.0f);

    wave = dist(eng);
}

std::vector<unsigned char> WaveSensor::readValue()
{
    std::lock_guard<std::mutex> lock(mtx);
    return floatToBytes(wave);
}

int WaveSensor::getType() const
{
    return 2; // typ 2 = fale
}
