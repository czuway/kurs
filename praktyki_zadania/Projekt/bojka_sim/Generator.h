#pragma once
#include <vector>

class Generator {
public:
    virtual ~Generator() = default;

    // metoda czysto wirtualna do generowania danych
    virtual void generate() = 0;

    // metoda czysto wirtualna do odczytu wartoœci jako bajty
    virtual std::vector<unsigned char> readValue() = 0;

    // metoda do pobrania typu sensora
    virtual int getType() const = 0;
};
