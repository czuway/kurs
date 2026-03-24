#include "JSONGenerator.h"
#include "Utils.h" // bytesToFloat
#include <sstream>
#include <iomanip>

std::string JSONGenerator::generateJSON(int sensorId, const std::vector<std::shared_ptr<Generator>>& sensors)
{
    std::ostringstream oss;
    oss << "{";
    oss << "\"sensorId\":" << sensorId << ",";
    oss << "\"readings\":[";

    for (size_t i = 0; i < sensors.size(); ++i)
    {
        float value = bytesToFloat(sensors[i]->readValue());
        oss << "{";
        oss << "\"type\":" << sensors[i]->getType() << ",";
        oss << "\"value\":" << std::fixed << std::setprecision(2) << value;
        oss << "}";

        if (i != sensors.size() - 1)
            oss << ",";
    }

    oss << "]";
    oss << "}";
    return oss.str();
}
