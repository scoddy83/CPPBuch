/* cppbuch/k1/union.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

union IntFloat {
  int intzahl;
  float floatzahl;
};

union Union2 {
  int wert;
  IntFloat einIntFloat;
};

int main() {
  IntFloat eineUnion;
  eineUnion.intzahl = 42;               // Speicherplatz belegen
  cout << eineUnion.intzahl << '\n';    // gespeicherten Wert verwenden
  eineUnion.floatzahl = 0.987f;         // denselben Speicherplatz belegen
  cout << eineUnion.floatzahl << '\n';  // ... und verwenden

  // Ausgabe der Adressen
  cout << &eineUnion.intzahl << '\n'
       << &eineUnion.floatzahl << '\n';  // muss gleich sein

  // Fehler: Missbrauch zur Typumwandlung
  cout << eineUnion.intzahl
       << '\n';  // Interpretation eines float-Bitmusters als int-Zahl

  //  gemeinsame Folge gleicher Typen am Anfang (hier nur int)
  Union2 u2;
  u2.wert = 99;
  cout << u2.einIntFloat.intzahl << '\n';  // ok
}
