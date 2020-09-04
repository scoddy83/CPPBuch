/* cppbuch/k26/funktionsobjekt/memfn.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../../k6/abstrakt/quadrat.h"
#include <algorithm>
#include <functional>
#include <vector>

int main() {
  Quadrat q(Ort(100, 20), 50);
  Rechteck r(Ort(30, 40), 20, 20);
  std::vector<GraphObj*> objekte = {&q, &r};
  // alle Objekte zeichnen (polymorph)
  std::for_each(objekte.begin(), objekte.end(), std::mem_fn(&GraphObj::zeichnen));

  // etwas umständlicher mit \tt{function}:
  std::function<void(const GraphObj*)> f = &GraphObj::zeichnen;
  std::for_each(objekte.begin(), objekte.end(), f);
}
