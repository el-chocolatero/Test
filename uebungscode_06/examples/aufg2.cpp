#include <misc/zeitmesser.hpp>
#include <misc/schnellsort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <iostream>
#include <algorithm>


int main() {
  std::vector<int> bsp_zahlen(4000);
  misc::fuelle_zufaellig(bsp_zahlen);
  misc::drucke_array(bsp_zahlen);
  misc::schnellsort(bsp_zahlen);
  misc::drucke_array(bsp_zahlen);
}
