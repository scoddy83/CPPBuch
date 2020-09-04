/* cppbuch/k23/folgen/unique.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <showContainer.h>
#include <vector>

int main() {
  // sortierte Folge mit benachbarten gleichen Elementen:
  std::vector<int> v{0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6};
  showContainer(v);                         // 0 0 0 1 1 1 2 2 2 3 3 3 4 4 4 5 5 5 6 6
  auto last = std::unique(v.begin(), v.end());   // Voraussetzung: Container ist sortiert
  showContainer(v);                         // 0 1 2 3 4 5 6 2 2 3 3 3 4 4 4 5 5 5 6 6
  v.erase(last, v.end());
  showContainer(v);                         // 0 1 2 3 4 5 6
}
