#include <iostream>
#include <vector>
#include <thread>
#include <memory> // <--- bardzo wa¿ne!
#include <chrono>

#include "TemperatureSensor.h"
#include "Utils.h"

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        std::cout << "Usage: ./app <server> <port> <sensor_id>\n";
        return 1;
    }

    std::string server = argv[1];
    int port = std::stoi(argv[2]);
    int sensorId = std::stoi(argv[3]);

    // wektor sensorów
    std::vector<std::shared_ptr<Sensor>> sensors;

    auto tempSensor = std::make_shared<TemperatureSensor>();
    sensors.push_back(tempSensor);

    // … reszta kodu …
}
