/* cppbuch/k23/vergleich/mismatch.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <set>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> v{0, 2, 4, 6, 8, 10, 12, 14};  // sortierte Folge
  set<int> s(v.begin(), v.end());            // Set mit v initialisieren
  v[3] = 7;                                  // Nichtübereinstimmung erzeugen
  showContainer(v);                          // Anzeige
  showContainer(s);

  // Prüfung mit Iterator Paar 'wo'
  // auto: pair<vector<int>::iterator, set<int>::iterator>
  auto wo = mismatch(v.begin(), v.end(), s.begin());
  if (wo.first == v.end()) {
    cout << "Inhalt der Container stimmt überein.\n";
  } else {
    cout << "Der erste Unterschied (" << *wo.first << " != " << *wo.second
         << ") wurde an Position " << (wo.first - v.begin())
         << " gefunden.\n";
  }
}
