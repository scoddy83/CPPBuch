/* cppbuch/k6/abstrakt/strecke.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef STRECKE_H
#define STRECKE_H
#include "graphobj.h"

class Strecke : public GraphObj {  // erben von \tt{GraphObj}
public:
  // Initialisierung mit Initialisierungsliste
  Strecke(Ort ort1, Ort ort2)
      : GraphObj{ort1},   // Initialisierung des Subobjekts
        endpunkt{ort2} {  // Initialisierung des Attributs
  }                       // leerer Code-Block

  auto laenge() const { return entfernung(bezugspunkt(), endpunkt); }

  // Definition der rein virtuellen Methoden
  virtual double flaeche() const override {  // \tt{override}: siehe Text unten
    return 0.0;
  }

  virtual void zeichnen() const override {
    GraphObj::zeichnen();
    std::cout << "Strecke von ";
    anzeigen(bezugspunkt());
    std::cout << " bis ";
    anzeigen(endpunkt);
    std::cout << '\n';
  }

private:
  Ort endpunkt;  // zusätzlich: 2. Punkt der Strecke
  // (der erste ist \tt{GraphObj::Referenzkoordinaten})
};
#endif  // STRECKE_H
