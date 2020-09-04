/* cppbuch/k23/folgen/sample.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include <showContainer.h>

int main() {
  std::vector<int> menge(49);
  std::iota(menge.begin(), menge.end(), 1);
  std::vector<int> auswahl;
  std::sample(menge.begin(), menge.end(), std::back_inserter(auswahl),
              6, std::mt19937{std::random_device{}()});
  showContainer(auswahl);
}
