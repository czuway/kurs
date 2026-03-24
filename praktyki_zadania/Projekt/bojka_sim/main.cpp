#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include <chrono>
#include "NetworkClient.h"
#include "TemperatureSensor.h"
#include "WaveSensor.h"
#include "PressureSensor.h"
#include "JSONGenerator.h"
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

    NetworkClient client(server, port);

    std::vector<std::shared_ptr<Generator>> sensors;
    sensors.push_back(std::make_shared<TemperatureSensor>());
    sensors.push_back(std::make_shared<WaveSensor>());
    sensors.push_back(std::make_shared<PressureSensor>());

    std::thread generatorThread([&]()
    {
        while (true)
        {
            for (auto& s : sensors)
                s->generate();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    std::thread readerThread([&]()
    {
        while (true)
        {
            std::string json = JSONGenerator::generateJSON(sensorId, sensors);

            if (!client.send(json))
                std::cout << "[ERROR] Failed to send data.\n";
            else
                std::cout << "[INFO] Data sent: " << json << "\n";

            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    });

    generatorThread.join();
    readerThread.join();

    return 0;
}
