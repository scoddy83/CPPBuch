/* cppbuch/k23/finden/binarysearch.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <showContainer.h>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> staedte{"Bremen", "Paris", "Mailand", "Hamburg"};
  sort(staedte.begin(), staedte.end());  // Wichtige Vorbedingung!
  showContainer(staedte);

  string stadt;
  cout << "Welche Stadt eintragen/suchen? ";
  cin >> stadt;

  if (binary_search(staedte.begin(), staedte.end(), stadt)) {
    cout << stadt << " existiert.\n";
  } else {
    cout << stadt << " existiert noch nicht.\n";
  }
  // an der richtigen Stelle einfügen
  cout << stadt << " wird eingefügt:\n";
  auto i = lower_bound(staedte.begin(), staedte.end(), stadt);
  staedte.insert(i, stadt);
  showContainer(staedte);

  // Bereich gleicher Werte
  // auto statt pair<vector<string>::const_iterator,
  // vector<string>::const_iterator>
  auto p = equal_range(staedte.begin(), staedte.end(), stadt);

  // Die zwei Iteratoren des Paars p begrenzen den Bereich, in dem
  // stadt vorkommt.
  auto n = distance(p.first, p.second);
  cout << stadt << " ist " << n << " mal im Vector enthalten\n";
}
