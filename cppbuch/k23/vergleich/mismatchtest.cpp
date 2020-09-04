/* cppbuch/k23/vergleich/mismatchtest.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cassert>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> v1{0, 2, 4, 6, 8, 10, 12};
  vector<int> v2 = v1;
  v2.push_back(14);
  showContainer(v1);  // Anzeige
  showContainer(v2);
  // Annahme: v1, v2 stimmen überein, soweit bei verschiedener Länge
  // möglich
  auto wo = mismatch(v1.begin(), v1.end(), v2.begin(), v2.end());
  if (v1.size() <= v2.size()) {
    assert(wo.first == v1.end());
    assert(wo.second == v2.begin() + v1.size());
  } else {  // v1 > v2
    assert(wo.first == v1.begin() + v2.size());
    assert(wo.second == v2.end());
  }
}
