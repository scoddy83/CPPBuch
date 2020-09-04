/* cppbuch/k23/folgen/shuffle.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <random>
#include <showContainer.h>
#include <vector>

int main() {
  std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

  // Benutzung eines Generators der C++-Library
  std::shuffle(v.begin(), v.end(), std::mt19937());
  showContainer(v);
}
