#include <iostream>
#include <chromo>  //do mierzenia czasu
#include <cstdlib> //do rand() generuje liczby losowe

using namespace std;

//robimy funkcje sortowania



void bubbleSort(int arr[], int n) { //to jest ta moja funckja ktora sortuje tablice o rozmiarze n, porownuje sasiednie elementy i zamienia miejscami, cala idea polega na tym ze duze liczby wyplywaja jak babelki

        for(int i = 0; i < n -1; i++) { //petla ktora wykonuje przejscia przez tablice

            for(int j = 0; j < n - i -1; j++) { //porownuje kolejne elementy

                if(arr[j] > arr[j + 1]) { //dodajemy ta linijke do kodu, jesli element po lewej jest wiekszy od prawego

                    int temp = arr[j]; //zapis pierwszego elementu tymczasowo
                    arr[j] = arr[j + 1]; //zamieniamy elementy miejscami
                    arr[j + 1] = temp; //wstawiamy zapisany element na nowe mioesjce
                }
            }
        }
    }  //jest najlepsza gdy mamy prosta tablice z kilkoma liczbami


void insertionSort(int arr[], int n) { funckja sortujaca tablice   //Wstawia na miejsce, porzadkowanie tablicy po kawalku, albo w lewo albo w prawo

    for(int i = 1; i < n; i++) { //ciachamy od drugiego elementu tablicy

        int key = arr[i]; //zapisujemy element ktory chcemy wstawic w dobre miejsce
        int j = i - 1; //indeks poprzedniego elementu

        while(j >= 0 && arr[j] > key) { //dopoki element jest wiekszy od key

                arr[j + 1] = arr[j]; //przesuwamy element w prawo
                j--; //przesuwamy indeks w lewo
        }

        arr[j + 1] = key; //wstawiamy element w key w odpowiednie meijsce
    }
} //prosty latwy i szybki dla malych danyc, czesto uzywa sie go wewnatrz innych algorytmow



int partition(int arr[], int low, int high) { //to jest natomiast funkcja dzielaca tablice

    if(low < high) { //jesli zakres ma wiecej niz jeden element

        int pi = partition(arr, low, high); //dzielimy tablice

        quickSort(arr, low, pi - 1); //sortujemy lewa czesc

        quickSort(arr, pi + 1, high); //sortujemy prawa czesc
    }
}  //to jest mega spoko quicksort mega szybko sortuje duzo danych dzieli na dwie czesci prawa lewa


void quickSort(int arr[], int low, int high) { funkcja sortujaca quickSort

    if(low < high) { //jesli zakres ma wiecej niz jeden element

        int pi = partition(arr, low, high); //dzielimy tablice

        quickSort(arr, low, pi -1); //sortujemy lewa czesc

        quickSort(arr, pi + 1, high); //sortujemy prawa czesc
    }
} //to samo co wyzej tylko wyzej mielismy podalgorytm partition, tylko ze quicksort sortuje cala tablice rekurencyjnie


void generateArray(int arr[], int size) { funckja ktora wypelnia tablice

    for(int i = 0; i < size; i++) { //przechodzimy przez cala tablice

        arr[i] = rand() % 100000; //tutaj wlasnie generujemy losowa liczbe od 1 do 99999
    }
}



