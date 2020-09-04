/* cppbuch/k23/zufallszahlen/gleichverteilungReal.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <random>

int main() {
  std::mt19937 zufall;
  std::uniform_real_distribution<double> verteilung(0.0, 1.0);
  constexpr std::size_t ITERATIONEN = 1000000u;
  double summe = 0.0;
  for (std::size_t i = 0; i < ITERATIONEN; ++i) {
    summe += verteilung(zufall);
  }
  std::cout << "Mittelwert: " << summe / ITERATIONEN << '\n';
}
