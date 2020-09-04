/* cppbuch/k23/zufallszahlen/wuerfel.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

int main() {
  std::mt19937 zufall;
  std::bernoulli_distribution verteilung(1.0 / 6.0);
  constexpr std::size_t ITERATIONEN = 1000000u;
  std::size_t anzahl_der_Sechsen = 0u;  // oder Einsen, oder Zweien ...
  for (std::size_t i = 0; i < ITERATIONEN; ++i) {
    if (verteilung(zufall)) {  // 6 Augen?
      anzahl_der_Sechsen++;
    }
  }
  std::cout << "Bei " << ITERATIONEN << " Wuerfen wurde "
            << anzahl_der_Sechsen << " mal die 6 geworfen ("
            << (100.0 * anzahl_der_Sechsen / ITERATIONEN) << " %).\n";
}
