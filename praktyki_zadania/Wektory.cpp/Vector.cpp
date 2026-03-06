#inlude "Vector.h"

//robimy funkcje teraz ktora powieksza tablice jesli zabraknie nam miejsca
void Vector::resize(){
    capacity *= 2;  //podwojmy sobie pojemnosc indeksu
    int* new_data = new int[capacity]  //tworzymy nowa tablice
     for (int i = 0; i < lenght; i++)
     new_data[i] = data[i]  //Kopiujemy stare elementy
     delete[] data; //usuwamy stara tablice. A robimy to wszystko czyli dodajemy nowa tablice, kopiujemy stare, usuwamy stara tablice tylko dla tego ze c++ nie pozwala na poszerzenie starej tablicy
     data = new_data; //ustawiamy wskaznik na nowa juz szersza tablice
}


//Konstruktor
Vector::Vector(int initial_size) {
    capacity = initial_size; //ustawiamy pojemnosc
    lenght = 0; // 0 bo ne mamy na start elementow
    data = new int[capacity]; //tworzymy dynamiczna tablice. czyli ta nasza tablica z d anymi ktora bedzie sie zmieniala w zaleznosci od ilosci elementow i danych
}

//Destruktor
Vector::~Vector() {
delete[] data;  //Nasz glowny bohater bez ktorego crushowalo by projekt, czyli dzieki temu na biezoca usuwaja sie z ramu niepotrzebne juz dane w starych zapelnionych tablicach
}


//Dodawanie elementu
void Vector::add_to_end(int value) [
    if(lenght == capacity) resize(); // angielski prosty jezyk(jesli zabraknie miejsca powiekszamy tablice
    data[lenght++] = value;  //dodajemy element na koncu i zwiekszamy licznik
]

//pobieranie elementu
int& Vector::at(int index) [
    if (index < 0 || index >= length)
        throw std::out_of_range("Index out of range"); //rzucamy wyj¹tek, jesli indeks niepoprawny
    return data[index]; //zwracamy referencje do elementu
]

//rozmiar
int Vector::size() {
return lenght; //ile jest realnie elementow
}

//Wypisywanie
void Vector::print() {
for (int i = 0; i < lenght; i++)
    std::cout << data[i] << " "; //wypisze wszystkie elementy
std::cout << std::endl; //nowa linia po wypisaniu
}


//Vector.cpp Implementuje funkcje takie jak konstruktor, destruktor, dodawanie elementow, powiekszanie tablicy, usuwanie elementow, pobieranie elementow, rozmiar, wypisywanie,
