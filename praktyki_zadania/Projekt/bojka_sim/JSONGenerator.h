#pragma once

#include <vector>     // vector sensorów
#include <memory>     // shared_ptr
#include <iostream>   // cout
#include "Sensor.h"
#include "Utils.h"

class JSONGenerator
{
public:
    static void generateJSON(int sensorID, std::vector<std::shared_ptr<Sensor>>& sensor)
    {
        std::cout << "{\n"; // pocz¹tek JSON
        std::cout << "  \"sensor_id\": " << sensorId << ",\n"; // ID sensora
        std::cout << "  \"data\": [\n"; // tablica danych

        for (size_t i = 0; i < sensor.size(); i++)
        {
            int type = sensors[i]->getType();

            float value = bytesToFloat(sensors[i]->readValue());

            std::cout << "    { \"type\": " << type
                      << ", \"value\": " << value << " }";

             if (i != sensors.size() - 1)
                std::cout << ","; // przecinek miêdzy elementami

             std::cout << "\n";
        }
        std::cout << "  ]\n"; // koniec tablicy
        std::cout << "}\n\n"; // koniec JSON
    }
};
