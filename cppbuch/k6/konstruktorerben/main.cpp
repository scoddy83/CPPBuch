/* cppbuch/k6/konstruktorerben/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Abgeleiteteklasse.h"
#include <iostream>
using namespace std;

int main() {
  Abgeleiteteklasse a1("Moin!", 42);  // allgemeiner Konstruktor
  cout << a1.getAttribut() << " " << a1.getWert() << '\n';

  Abgeleiteteklasse a2("Hallo Welt!");  // geerbter Konstruktor
  cout << a2.getAttribut() << " " << a2.getWert() << '\n';
}
