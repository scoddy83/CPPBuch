/* cppbuch/loesungen/k2/11/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "betrag.t"
#include <iostream>
using namespace std;

int main() {
  int i = -1;
  cout << "Der Betrag von " << i << " ist " << betrag(i) << '\n';
  double d = -2.345;
  cout << "Der Betrag von " << d << " ist " << betrag(d) << '\n';
  // Fehlermeldung provozieren
  bool b = true;
  cout << "Der Betrag von " << b << " ist " << betrag(b) << '\n';
}
