#pragma
#include "Sensor.h"
#include "Generator.h"
#include <array>
#include <mutex>

class WaveSensor : public Sensor, public Generator
{
private:
    std::array<uint8_t, 4> value; // wartoœæ w bajtach
    std::mutex mtx;

public:
    WaveSensor():
        void generate() override;
        std::array<uint8_t, 4> readValue() override;
        int getType() override;
};
