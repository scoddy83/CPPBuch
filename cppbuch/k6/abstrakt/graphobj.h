/* cppbuch/k6/abstrakt/graphobj.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include <ort.h>                            // enthält #include<iostream>

class GraphObj {                            // Version 2
public:
  GraphObj(Ort einOrt)                      // allgemeiner Konstruktor
      : referenzkoordinaten{einOrt} {
}

  virtual ~GraphObj() = default;            // virtueller Destruktor
  GraphObj(const GraphObj&) = default;  // Regel der großen Drei
  GraphObj& operator=(const GraphObj&) = default; // dito

  // Bezugspunkt ermitteln
  Ort bezugspunkt() const { return referenzkoordinaten; }

  // alten Bezugspunkt ermitteln und gleichzeitig neuen wählen
  Ort bezugspunkt(Ort nO) {
    Ort temp{referenzkoordinaten};
    referenzkoordinaten = nO;
    return temp;
  }

  // Koordinatenabfrage
  int getX() const { return referenzkoordinaten.getX(); }
  int getY() const { return referenzkoordinaten.getY(); }

  // rein virtuelle Methoden
  virtual double flaeche() const = 0;
  virtual void zeichnen() const = 0;

private:
  Ort referenzkoordinaten;
};

// Standardimplementierung einer rein virtuellen Methode
inline void GraphObj::zeichnen() const { std::cout << "Zeichnen: "; }

// Die Entfernung zwischen 2 \tt{GraphObj}-Objekten ist hier als Entfernung ihrer
// Bezugspunkte (überladene Funktion) definiert.
inline double entfernung(const GraphObj& g1, const GraphObj& g2) {
  return entfernung(g1.bezugspunkt(), g2.bezugspunkt());
}
#endif  // GRAPHOBJ_H
