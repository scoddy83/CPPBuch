/* cppbuch/k26/type_traits/isArithmetic.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <list>
#include <string>
#include <type_traits>
#include <vector>

template <typename Container>
typename Container::value_type summe(const Container& cont) {
  static_assert(std::is_arithmetic<typename Container::value_type>::value,
                "Die Elemente des Containers muessen Zahlen sein!");
  typename Container::value_type ergebnis{};
  for (auto wert : cont) {
    ergebnis += wert;
  }
  return ergebnis;
}

int main() {
  const std::vector<int> vektor{3, 6, 8, 9, 1, 3, 0};
  std::cout << "Summe vector<int>  = " << summe(vektor) << '\n';
  const std::list<double> liste{3, 6, 8, 9, 1, 3, 0};
  std::cout << "Summe list<double> = " << summe(liste) << '\n';

  const std::list<std::string> strings{"abc", "def"};
  // Fehler:
  // std::cout << "Summe list<string> = " << summe(strings) << '\n';
}
