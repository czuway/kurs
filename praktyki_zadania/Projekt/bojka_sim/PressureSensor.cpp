#include "PressureSensor.h
#include "Utils.h"
#include <cstdlib>

PressureSensor::PressureSensor()
{
    value = {0, 0, 0, 0}; // 4 bajty = 0
}

void PressureSensor::generate()
{
    std::lock_guard<std::mutex> lock(mtx);
    // blokujemy mutex – żeby drugi wątek nie czytał w trakcie zapisu

    float pressure = 980.0f + (rand() % 700) / 10.0f;
    // losujemy wartość 980.0 – 1050.0

    value = floatToBytes(pressure);
    // zamieniamy float → 4 bajty (symulacja sprzętu)
}

// Odczyt danych
std::array<uint8_t, 4> PressureSensor::readValue()
{
    std::lock_guard<std::mutex> lock(mtx);
    // blokujemy mutex – żeby nie czytać w trakcie zapisu

    return value; // zwracamy aktualną wartość
}

// Typ sensora
int PressureSensor::getType()
{
    return 3; // zgodnie z mapowaniem: 3 = pressure
}
