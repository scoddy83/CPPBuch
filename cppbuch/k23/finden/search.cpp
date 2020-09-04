/* cppbuch/k23/finden/search.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cstdlib>  // \tt{abs()}
#include <iostream>
#include <showContainer.h>
#include <vector>

using namespace std;

int main() {
  vector<int> folge{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  cout << "Folge = ";
  showContainer(folge);

  vector<int> teilfolge(folge.begin() + 5, folge.begin() + 9);  // 5 6 7 8
  cout << "Teilfolge = ";
  showContainer(teilfolge);

  // Teilfolge in Folge suchen
  auto position =
      search(folge.begin(), folge.end(), teilfolge.begin(), teilfolge.end());
  if (position != folge.end()) {
    cout << " Die Teilfolge ist in der Folge ab Position "
         << (position - folge.begin()) << " enthalten.\n";
  } else {
    cout << "Die Teilfolge ist nicht in der Folge enthalten.\n";
  }
  // Fall2: binäres Prädikat. Dafür negative Zahlen setzen
  for (auto& el : teilfolge) {
    el = -el;  // -5 -6 -7 -8
  }
  cout << "Teilfolge = ";
  showContainer(teilfolge);

  // Teilfolge in Folge suchen, dabei Vorzeichen ignorieren
  position = search(folge.begin(), folge.end(), teilfolge.begin(), teilfolge.end(),
                    [](int x, int y) { return abs(x) == abs(y); });
  if (position != folge.end()) {
    cout << " Die Teilfolge ist in der Folge ab Position "
         << (position - folge.begin())
         << " enthalten. Vorzeichen wurden ignoriert.\n";
  } else {
    cout << "Die Teilfolge ist nicht in der Folge enthalten.\n";
  }
}
