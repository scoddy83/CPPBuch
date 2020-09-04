/* cppbuch/k23/sortieren/mergesort_list.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "mergesort.t"
#include <Random.h>
#include <algorithm>
#include <list>
#include <showContainer.h>

int main() {  // mit Liste statt Vektor
  std::list<int> liste;
  Random zufall(1000);
  for (unsigned int i = 0; i < 20; ++i) {
    liste.push_front(zufall());  // pseudo-zufällige Zahlen
  }
  showContainer(liste);
  auto buffer = liste;
  mergesort(liste.begin(), liste.end(), buffer.begin());
  showContainer(liste);  // sortierte Zahlen
}
