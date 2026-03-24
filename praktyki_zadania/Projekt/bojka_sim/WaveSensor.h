#pragma once
#include "Generator.h"
#include <vector>
#include <mutex>

class WaveSensor : public Generator {
public:
    WaveSensor() = default;
    ~WaveSensor() override = default;

    void generate() override;
    std::vector<unsigned char> readValue() override;
    int getType() const override;

private:
    float wave = 0.0f;
    mutable std::mutex mtx;
};
