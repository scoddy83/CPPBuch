/* cppbuch/k23/sortieren/merge1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <showContainer.h>
#include <vector>

int main() {
  std::vector<int> v(16);  // gerade Zahl
  auto middle = v.size() / 2;
  for (unsigned int i = 0; i < middle; ++i) {
    v[i] = 2 * i;               // gerade
    v[middle + i] = 2 * i + 1;  // ungerade
  }
  showContainer(v);
  std::inplace_merge(v.begin(), v.begin() + middle, v.end());
  showContainer(v);
}
