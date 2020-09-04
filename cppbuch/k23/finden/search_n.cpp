/* cppbuch/k23/finden/search_n.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> folge{0, 1, 3, 4, 4, 4, 5, 6, 7, 8, 1, 3};  
  // Die Folge einthält drei aufeinanderfolgende gleiche Werte
  cout << "Folge = ";
  showContainer(folge);

  constexpr int wert = 4;
  constexpr int wieoft = 3;
  auto position = search_n(folge.begin(), folge.end(), wieoft, wert);
  if (position != folge.end()) {
    cout << wert << " wurde " << wieoft << "-mal nacheinander ab Position "
         << (position - folge.begin()) << " gefunden.\n";
  } else {
    cout << wert << " wurde nicht " << wieoft << "-mal nacheinander gefunden.\n";
  }
  position = search_n(folge.begin(), folge.end(), wieoft, wert, greater<int>());
  if (position != folge.end()) {
    cout << "Ab Position " << (position - folge.begin()) << " wurden " << wieoft
         << "-mal nacheinander Werte größer als " << wert << " gefunden.\n";
  } else {
    cout << wieoft << "-mal nacheinander Werte größer als " << wert
         << " sind nicht vorhanden.\n";
  }
}
