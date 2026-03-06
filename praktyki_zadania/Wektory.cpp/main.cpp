#include "Header/Vector.h"

int main() {
Vector v;  //tworzy wektor v o domyslnym rozmiarze 4

v.add_to_end(10) //dodajemy dyszke i potem kolejne liczbt do tablicy
v.add_to_end(20)
v.add_to_end(30)

std::cout << "Zawartosc wektora: ";
v.print(); //wypisze nam nasze liczby z wectora te add to end czyli od lewej do prawej 10 20 30

v.remove(1);  //teraz usuwamy sobie element pod indeksem 1 (czyli 20)
std::cout << "Po usunieciu indeksu 1: ";
v.print();  //wypisze nam 10 i 30

v.at(0) = 100;   //zmieniamy pierwszy element na 100
std::cout << "Po zmianie pierwszego elementu: ";
v.print();   //Wypisze: 100 i 30

return 0;

}
