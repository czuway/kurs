#include "TemperatureSensor.h"
#include "Utils.h"
#include <cstdlib>

// Konstruktor
TemperatureSensor::TemperatureSensor()
{
    value = {0, 0, 0, 0};
}

// Generowanie danych
void TemperatureSensor::generate()
{
    std::lock_guard<std::mutex> lock(mtx);
    float temp = 10.0f + (rand() % 150) / 10.0f;
    value = floatToBytes(temp); // poprawna nazwa
}

// Odczyt danych
std::array<uint8_t, 4> TemperatureSensor::readValue()
{
    std::lock_guard<std::mutex> lock(mtx);
    return value;
}

// Typ sensora
int TemperatureSensor::getType()
{
    return 4;
}
