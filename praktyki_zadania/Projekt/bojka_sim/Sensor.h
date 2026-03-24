#include <vector>
#include <memory>
#include "TemperatureSensor.h"
#include "PressureSensor.h"
#include "WaveSensor.h"

std::vector<std::shared_ptr<Generator>> sensors;
sensors.push_back(std::make_shared<TemperatureSensor>());
sensors.push_back(std::make_shared<PressureSensor>());
sensors.push_back(std::make_shared<WaveSensor>());

class TemperatureSensor : public Sensor
{
private:
    float temp = 20.0f;

public:
    void generate() override
    {
        temp += (rand() % 100 - 50) / 100.0f; // losowa zmiana
    }

    std::vector<uint8_t> readValue() override
    {
        std::vector<uint8_t> bytes(sizeof(float));
        std::memcpy(bytes.data(), &temp, sizeof(float));
        return bytes;
    }

    int getType() const override { return 0; }
};
