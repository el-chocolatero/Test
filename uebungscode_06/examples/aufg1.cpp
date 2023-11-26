#include <mergesort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <vector>
#include <iostream>

int main() {
  std::vector<int> bsp_zahlen(4000);
  misc::fuelle_zufaellig(bsp_zahlen);
  misc::drucke_array(bsp_zahlen);
  
}
