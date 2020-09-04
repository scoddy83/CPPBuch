/* cppbuch/k6/erben/strecke.h
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

  double laenge() const { 
    return entfernung(bezugspunkt(), endpunkt); 
  }

private:
  Ort endpunkt;  // zusätzlich: 2. Punkt der Strecke
  // (der erste ist \tt{GraphObj::Referenzkoordinaten})
};
#endif  // STRECKE_H
