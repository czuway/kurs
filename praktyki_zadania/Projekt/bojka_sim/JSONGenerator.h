#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Generator.h"

class JSONGenerator {
public:
    // Generuje JSON z listy sensorów
    static std::string generateJSON(int sensorId, const std::vector<std::shared_ptr<Generator>>& sensors);
};
