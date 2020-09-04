/* cppbuch/k3/kopierkonstruktor/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "ortMitKopierkonstruktor.h"

namespace {
// Funktion zum Verschieben des Orts um dx und dy
Ort ortsverschiebung(Ort derOrt, int dx, int dy) {
  derOrt.aendern(derOrt.getX() + dx, derOrt.getY() + dy);
  return derOrt;  // Rückgabe des veränderten Orts
}
}

int main() {
  Ort einOrt(10, 300);
  Ort verschobenerOrt = ortsverschiebung(einOrt, 10, -90);  // Zuweisung
  std::cout << " alter Ort: ";
  anzeigen(einOrt);
  std::cout << "\n neuer Ort: ";
  anzeigen(verschobenerOrt);
  std::cout << '\n';
  Ort neu = ortsverschiebung(Ort(0, 20), 10, -90);  // temporäres Objekt
  std::cout << "aus temporärem Objekt erzeugter Ort: ";
  anzeigen(neu);
  std::cout << '\n';
}
