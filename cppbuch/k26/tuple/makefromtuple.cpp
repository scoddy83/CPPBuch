/* cppbuch/k26/tuple/makefromtuple.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <ort.h>          // cppbuch/include/ort.h
#include <iostream>
#include <tuple>
#include <utility>

int main() {
  auto tupel = std::make_tuple(1, 2);
  Ort ort = std::make_from_tuple<Ort>(tupel);
  anzeigen(ort);                            // anzeigen() ist in ort.h definiert
  std::cout << '\n';
}
