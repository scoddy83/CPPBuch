/* cppbuch/k6/privateVirtualFunctions/strecke.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef STRECKE_H
#define STRECKE_H
#include "graphobj.h"

class Strecke : public GraphObj {  // erben von \tt{GraphObj}
public:
  // Initialisierung mit Initialisierungsliste
  Strecke(const Ort& ort1, const Ort& ort2)
      : GraphObj{ort1},   // Initialisierung des Subobjekts
        endpunkt{ort2} {  // Initialisierung des Attributs
  }                       // leerer Code-Block

  double laenge() const { return entfernung(bezugspunkt(), endpunkt); }

private:
  // Definition der rein virtuellen Methoden
  virtual double
  flaeche_impl() const override {  // \tt{override}: siehe Text unten
    return 0.0;
  }

  virtual void zeichnen_impl() const override {
    GraphObj::zeichnen_impl();  // Aufruf der
                                // Standard-Implementierung
    std::cout << "Strecke von ";
    anzeigen(bezugspunkt());
    std::cout << " bis ";
    anzeigen(endpunkt);
    std::cout << '\n';
  }

  Ort endpunkt;  // zusätzlich: 2. Punkt der Strecke
  // (der erste ist \tt{GraphObj::Referenzkoordinaten})
};
#endif  // STRECKE_H
