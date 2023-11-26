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
