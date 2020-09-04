/* cppbuch/k26/tuple/tupleIterator.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Iterieren über alle Tupel-Elemente
#include <iostream>
#include <string>
#include <tuple>

template <typename T> 
void anzeigen(const T& was) {
  std::cout << was << '\n';
}

template <unsigned int I, class Tupel> 
constexpr void zeigeElemente(const Tupel& tupel) {
  if constexpr(I > 0) {
      zeigeElemente<I-1, Tupel>(tupel);
      anzeigen(std::get<I-1>(tupel));
  }
}

int main() {
  auto tupel = std::make_tuple("Donald", "Duck", 17);
  zeigeElemente<std::tuple_size<decltype(tupel)>::value, decltype(tupel)>(tupel);
}
