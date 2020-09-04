/* cppbuch/k6/privateVirtualFunctions/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Hauptprogramm
#include "quadrat.h"  // schliesst {\em rechteck.h} ein
#include "strecke.h"
#include <vector>

int main() {
  //  GraphObj g;   Fehler!
  // Instanzen abstrakter Klassen gibt es nicht.

  Rechteck r(Ort(0, 0), 20, 50);
  Strecke s(Ort(1, 20), Ort(200, 0));
  Quadrat q(Ort(122, 99), 88);

  // Vektor mit Basisklassenzeigern, initialisiert mit den Adressen
  // der Objekte
  std::vector<GraphObj*> graphObjZeiger{&r, &s, &q};

  // Ausgabe der Fläche aller Objekte
  for (auto graphObjPtr : graphObjZeiger) {
    std::cout << "Fläche = " << graphObjPtr->flaeche() << '\n';
  }
  // Zeichnen aller Objekte
  for (auto graphObjPtr : graphObjZeiger) {
    graphObjPtr->zeichnen();
  }
  std::cout << "Auch Referenzen sind polymorph:\n";
  GraphObj& r_ref = r;  // Der statische Typ ist derselbe,
  GraphObj& s_ref = s;
  GraphObj& q_ref = q;
  r_ref.zeichnen();  // der dynamische nicht.
  s_ref.zeichnen();
  q_ref.zeichnen();
}
