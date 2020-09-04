/* cppbuch/k23/sortieren/mergesort_vec.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "mergesort.t"
#include <Random.h>
#include <algorithm>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> v, buffer(20);
  Random zufall(1000);
  for (unsigned int i = 0; i < 20; ++i) {
    v.push_back(zufall());  // pseudo-zufällige Zahlen
  }
  showContainer(v);  // pseudo-zufällige Zahlen
  // sortieren und anzeigen
  mergesort(v.begin(), v.end(), buffer.begin());
  showContainer(v);  // sortierte Zahlen
}
