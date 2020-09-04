/* cppbuch/k23/finden/adjacent_find.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> v{0,  2, 4,  6, 99,
                99, 8, 10, 12};  // 2 gleiche benachbarte Elemente (99)
  showContainer(v);
  auto iter = adjacent_find(v.begin(), v.end());  // finde gleiche Nachbarn
  if (iter != v.end()) {
    cout << "Die ersten gleichen benachbarten Zahlen (" << *iter
         << ") wurden an Position " << (iter - v.begin()) << " gefunden.\n";
  } else {
    cout << "Keine gleichen Nachbarn gefunden.\n";
  }
}
