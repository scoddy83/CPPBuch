/* cppbuch/k23/finden/find_first_of.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> folge{0, 2, 4, 6, 8, 10, 12, 14};
  vector<int> menge{1, 5, 7};
  // Zwei Tests:
  for (int testNummer = 0; testNummer < 2; ++testNummer) {
    if (testNummer == 1) {
      menge[1] = 6;
      cout << "\nMenge modifiziert:\n";
    }
    cout << "Ist eines der Elemente der Menge (";
    showContainer(menge, "");
    cout << ") in der Folge\n";
    showContainer(folge, "");
    cout << " enthalten?\n";

    // Suche nach Element, das auch in der Menge enthalten ist
    auto iter = find_first_of(folge.begin(), folge.end(), menge.begin(), menge.end());
    if (iter != folge.end()) {
      cout << "Ja. Element " << *iter
           << " ist in beiden Bereichen vorhanden. Sein erstes "
              "Vorkommen"
              " in der Folge ist Position "
           << (iter - folge.begin()) << ".\n";
    } else {
      cout << "Nein.\n";
    }
  }
}
