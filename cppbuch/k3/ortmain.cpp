/* cppbuch/k3/ortmain.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../include/ort.h"

using namespace std;

// Funktion zum Verschieben des Orts um dx und dy
Ort ortsverschiebung(Ort derOrt, int dx, int dy) {
  derOrt.aendern(derOrt.getX() + dx, derOrt.getY() + dy);
  return derOrt;  // Rückgabe des neuen Orts
}

int main() {
  Ort einOrt(10, 300);
  Ort verschobenerOrt = ortsverschiebung(einOrt, 10, -90);
  cout << " alter Ort: ";
  anzeigen(einOrt);
  cout << "\n neuer Ort: ";
  anzeigen(verschobenerOrt);

  cout << "\n mit Typwandlungskonstruktor:\n";
  Ort nochEinOrt(string("21 99"));  // mögliches Format
  anzeigen(nochEinOrt);
  cout << '\n';
  Ort einWeitererOrt("(55, 8)");  // weiteres mögliches Format
  anzeigen(einWeitererOrt);

  cout << "\n Typumwandlung eines Parameters:\n";
  string wo("20,400");
  verschobenerOrt = ortsverschiebung(Ort(wo), 10, -90);
  cout << "\n verschobener Ort: ";
  anzeigen(verschobenerOrt);
  cout << '\n';
  Ort o1(0, 0);
  //   o1 = wo;              // jetzt ein Fehler!
  o1 = Ort(wo);  // erlaubte explizite Typumwandlung
}
