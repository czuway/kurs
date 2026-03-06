#pragma once          // dzieki temu plik bedzie sie kompliowal tylko raz zeby nic sie nie rozwalilo
#include <iostream>
#include <stdexcept>
class Vector{

    private:  //cos co widzimy i mozemy sie zajmowac tylko w tym pliku zeby nic sie nie zmienilo w innym i nam sie popsuje
        int* data;  //Wskaznik do tablicy z liczbami, dzieki *<- wiemy ze nie przychowujemy wartosci a adres gdzie sie znajduje nasza wartosc
        int capacity; //Maksymalna liczba elementow ktore mozemy przechowywac jak sama nazwa mowi capacity(pojemnosc)
        int lenght;  //Ile elementow jest w wektorze
        void resize(); //dzieki resizowi tej pomocniczej funkcji mozemy powiekszac tablice


    public:  //moge sobie z publica wszystko zmieniac w innych plikach takich jak nasze main.cpp, vector.cpp
        Vector(int initial_size = 4); //konstrulujemy rozmiar, dalismy 4
        ~Vector(); //jak dla mnie najwazniejszy element w wektorach, bez tego mielibysmy crusha, ram zapchany i ciul

        void add_to_end(int value); //najprostsze funckje wektorow kazda dodana liczba dodaje sie po prawo od ostatniej
        void remove(int index);   //usuwa element pod danym indeksem
        int& at(int index);   //zwraca zmienialny element pod indeksem
        int size();  //zwraca liczbe elemtow np widzimy dzieki temu ilosc graczy na mapie
        void print();  //wypisuje wszystkie elementy

};


//VECTOR.H jest naszym dekleratorem klasy
