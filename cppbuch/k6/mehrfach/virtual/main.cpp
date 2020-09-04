/* cppbuch/k6/mehrfach/virtual/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "beschriftetesrechteck.h"
#include <vector>

using namespace std;

int main() {
  Rechteck r(Ort(0, 0), 20, 50);

  BeschriftetesRechteck bR(Ort(1, 20), 60, 60, "Mehrfachvererbung");
  r.zeichnen();
  bR.zeichnen();

  BeschriftetesRechteck* zBR = new BeschriftetesRechteck(
      Ort(100, 0), 20, 80, "dynamisches Rechteck");

  zBR->zeichnen();
  delete zBR;
  cout << "Rechteck-Position: ";
  anzeigen(r.bezugspunkt());

  cout << "\n beschriftetes-Rechteck-Position: ";
  //   anzeigen(bR.bezugspunkt());       // Compiler-Fehlermeldung!

  // eindeutig:
  anzeigen(bR.Rechteck::bezugspunkt());

  Rechteck r1(Ort(0, 0), 20, 50);
  Rechteck r2(Ort(0, 100), 10, 40);
  BeschriftetesRechteck bR2(Ort(1, 20), 60, 60, "Mehrfachvererbung");

  // Vektor mit Basisklassenzeigern, initialisiert mit den Adressen der Objekte
  vector<GraphObj*> ZeigerAufGrafischeObjekte {&r1, &r2, &bR2};
  for(auto ptr : ZeigerAufGrafischeObjekte) {
    ptr->zeichnen();
  }
}
