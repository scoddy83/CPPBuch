/* cppbuch/k23/zufallszahlen/mt19937.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <random>

int main() {
  std::mt19937 zufall;
  for (std::size_t i = 0; i < 10u; ++i) {
    std::cout << zufall() << '\n';
  }
}
