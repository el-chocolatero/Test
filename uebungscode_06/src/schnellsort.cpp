#include <misc/schnellsort.hpp>

#include <vector>
#include <algorithm>

namespace misc{

void schnellsort(std::vector<int>& v) {
  // Wir verwenden die Standardbibliothek zum sortieren.
  std::sort(v.begin(), v.end(), [](const int x, const int y) { return x < y; });
}

}
