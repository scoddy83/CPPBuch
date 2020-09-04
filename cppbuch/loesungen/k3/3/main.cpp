/* cppbuch/loesungen/k3/3/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "IntMenge.h"
#include <iostream>
using namespace std;

int main() {
  cout << "Test einer Menge für int-Werte\n";
  IntMenge menge;
  for (int i = 5; i > -3; --i) {
    menge.hinzufuegen(i);
  }
  menge.anzeigen();
  for (int i = 3; i < 8; ++i) {
    menge.hinzufuegen(i);
  }
  menge.anzeigen();
  cout << "menge.istMitglied(3) " << menge.istMitglied(3) << '\n';
  cout << "menge.istMitglied(-11) " << menge.istMitglied(-11) << '\n';
  menge.hinzufuegen(-11);
  menge.anzeigen();
  cout << "menge.istMitglied(-11) " << menge.istMitglied(-11) << '\n';
  cout << "menge.getMin() =  " << menge.getMin() << '\n';
  cout << "menge.getMax() =  " << menge.getMax() << '\n';
  int k = menge.getMin();
  // menge.loeschen();
  while (menge.size() > 0) {  // leeren und anzeigen
    size_t vorher = menge.size();
    menge.entfernen(k++);
    if (vorher != menge.size()) {  // 1 Element gelöscht
      menge.anzeigen();
    }
  }
}
