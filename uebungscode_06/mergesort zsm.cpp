// Hier kommt die Deklaration (und Beschreibung) von mergesort hin

#pragma once
#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>

namespace mergesort {
    void merge(std::vector<int>& arr, int left, int mid, int right);
    void sort(std::vector<int>& arr, int left, int right);
}

#endif /* MERGESORT_HPP */



// Hier wird mergesort implementiert

#include mergesort.hpp
#include <iostream>
#include <vector>

namespace mergesort {
    // Mergt 2 sortierte Subarrays [left...mid] und [mid+1...right]
    void merge(std::vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Temporäre Arrays
        std::vector<int> leftArr(n1);
        std::vector<int> rightArr(n2);

        // Daten werden zu den temporären Arrays leftArr[] und rightArr[] kopiert
        for (int i = 0; i < n1; ++i)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; ++j)
            rightArr[j] = arr[mid + 1 + j];

        // Merge die temporären Arrays mit arr[left...right]
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                ++i;
            } else {
                arr[k] = rightArr[j];
                ++j;
            }
            ++k;
        }

        // Kopiert die letzten Elemente von rightArr[], wenn noch welche da sind
        while (j < n2) {
            arr[k] = rightArr[j];
            ++j;
            ++k;
        }
    }

    // Hauptfunktion, um Merge Sort zu implementieren
    void sort(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Sortiert erste und zweite Hälfte
            sort(arr, left, mid);
            sort(arr, mid + 1, right);

            // Mergt die sortierten Hälften
            merge(arr, left, mid, right);
        }
    }
}

#include <misc/hilfsfunktionen.hpp>
#include <vector>
#include <functional>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>

namespace misc {

    // Die Funktion befüllt ein Array mit zufälligen Zahlen
    void fuelle_zufaellig(std::vector<int>& in) {
        // Konfiguriere den Zufallszahlengenerator
        std::srand(unsigned(std::time(nullptr)));
        // Erstelle ein Funktionsobjekt welches Zufallszahlen zwischen 0 und 10000 generiert
        std::function<size_t(void)> zufallsgenerator = [] (void) -> size_t { return std::rand() % 10000; };
        // Befülle das Array mithilfe des Funktionsobjekts
        std::generate(in.begin(), in.end(), zufallsgenerator);
    }

    // Die Funktion druckt ein Array aus
    void drucke_array(const std::vector<int>& in) {
        for(const int& zahl: in) {
        std::cout << std::setw(5) << zahl;
        }
        std::cout << std::endl;
    }

}

#include <mergesort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> bsp_zahlen(4000);
    misc::fuelle_zufaellig(bsp_zahlen);
    misc::drucke_array(bsp_zahlen);

    // Sortiert mit Merge Sort
    mergesort::sort(bsp_zahlen, 0, bsp_zahlen.size() -  1);

    std::cout << "Sorted Array:\n";
    misc::drucke_array(bsp_zahlen);

    return 0;
}