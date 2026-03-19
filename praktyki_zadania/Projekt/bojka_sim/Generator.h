#pragma once

//to jest interfejs odpowiedzialny za generowanie danych
class Generator
{
public:
    //a to nasza funckja ktora generuje nowe dane
    virtual void generate() = 0;

    virtual ~Generator() = default;
};
