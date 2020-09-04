/* cppbuch/k6/erben/graphobj.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include "ort.h"

class GraphObj {  // Version 1
public:
  GraphObj(Ort einOrt)  // allgemeiner Konstruktor
    : referenzkoordinaten{einOrt} {}

  // Bezugspunkt ermitteln
  Ort bezugspunkt() const { 
    return referenzkoordinaten; 
  }

  // alten Bezugspunkt ermitteln und gleichzeitig neuen wählen
  Ort bezugspunkt(Ort nO) {
    Ort temp {referenzkoordinaten}; 
    referenzkoordinaten = nO;
    return temp;
  }

  // Koordinatenabfrage
  int getX() const { 
    return referenzkoordinaten.getX(); 
  }
  int getY() const { 
    return referenzkoordinaten.getY(); 
  }

  // Standardimplementation
  double flaeche() const {
    return 0.0; 
  }

private:
  Ort referenzkoordinaten;
};

// Die Entfernung zwischen 2 GraphObj-Objekten ist hier als Entfernung ihrer
//  Bezugspunkte (überladene Funktion) definiert.
inline double entfernung(GraphObj g1, GraphObj g2) {
  return entfernung(g1.bezugspunkt(), g2.bezugspunkt());
}
#endif  // GRAPHOBJ_H
