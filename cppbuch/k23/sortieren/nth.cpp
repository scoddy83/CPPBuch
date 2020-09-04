/* cppbuch/k23/sortieren/nth.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <Random.h>
#include <algorithm>
#include <deque>
#include <showContainer.h>
using namespace std;

int main() {
  deque<int> d;
  Random zufall(100);
  for (unsigned int i = 0; i < 15; ++i) {
    d.push_front(zufall());
  }
  showContainer(d);  // 5 3 83 52 38 94 68 68 4 22 53 46 76 13 0
  deque<int>::iterator nth = d.begin();
  nth_element(d.begin(), nth, d.end());
  cout << "Kleinstes Element: " << (*nth) << '\n';  // 0

  // Das Standard-Vergleichsobjekt \tt{greater} dreht die Reihenfolge um.
  // In diesem Fall steht das größte Objekt an der ersten Position.
  // Hier ist immer noch \tt{nth == d.begin()}.
  nth_element(d.begin(), nth, d.end(), greater<int>());
  cout << "Größtes Element : " << (*nth) << '\n';  // 94

  // Mit dem < -Operator steht das größte Element am Ende:
  nth = d.end();
  --nth;  // zeigt nun auf das letzte Element
  nth_element(d.begin(), nth, d.end());
  cout << "Größtes Element  : " << (*nth) << '\n';  // 94

  // Median
  nth = d.begin() + d.size() / 2;
  nth_element(d.begin(), nth, d.end());
  cout << "Medianwert       :" << (*nth) << '\n';  // 46
}
