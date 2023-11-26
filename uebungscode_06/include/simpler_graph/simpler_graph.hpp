#pragma once

#include <vector>
#include <cstddef>

namespace SimplerGraph{
  
  class SimplerGraph{
  public:
    // Erstellt einen Graph mit einer festen Knotenanzahl
    SimplerGraph(size_t knoten_anzahl);
    

  private:
    const size_t knoten_anz;
  };
}
