/* cppbuch/k26/tuple/tupleIteratorstruct.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Iterieren über alle Tupel-Elemente
#include <iostream>
#include <string>
#include <tuple>

template <unsigned int I, class Tupel> 
struct zeigeElement {
  zeigeElement(Tupel tupel) {
    if constexpr(I > 0) {
      zeigeElement<I - 1, Tupel> x(tupel);
      std::cout << std::get<I - 1>(tupel) << '\n';
    }
  }
};

template <typename Tupel> 
void tupelAnzeigen(const Tupel& tupel) {
  zeigeElement<std::tuple_size<Tupel>::value, Tupel> x(tupel);
}

int main() {
  auto tupel = std::make_tuple("Donald", "Duck", 17);
  tupelAnzeigen(tupel);
}
