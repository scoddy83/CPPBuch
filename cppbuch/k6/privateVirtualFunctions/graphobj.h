/* cppbuch/k6/privateVirtualFunctions/graphobj.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include <ort.h>

class GraphObj {  // Version 3
public:
  GraphObj(const Ort& einOrt)  // allg. Konstruktor
      : referenzkoordinaten{einOrt} {}

  virtual ~GraphObj() = default;  // virtueller Destruktor
  GraphObj(const GraphObj&) = default;  // Regel der großen Drei
  GraphObj& operator=(const GraphObj&) = default; // dito

  // Bezugspunkt ermitteln
  const Ort& bezugspunkt() const { return referenzkoordinaten; }

  // alten Bezugspunkt ermitteln und gleichzeitig neuen wählen
  Ort bezugspunkt(const Ort& nO) {
    Ort temp{referenzkoordinaten};
    referenzkoordinaten = nO;
    return temp;
  }

  // Koordinatenabfrage
  int getX() const { return referenzkoordinaten.getX(); }
  int getY() const { return referenzkoordinaten.getY(); }

  double flaeche() const {  // die neue Schnittstelle
    return flaeche_impl();  // polymorpher Aufruf der Implementierung
  }
  void zeichnen() const {  // die neue Schnittstelle
    // hier ggf. Vorbedingungen prüfen
    zeichnen_impl();  // polymorpher Aufruf der Implementierung
                      // hier ggf. Nachbedingungen prüfen
  }

  // rein virtuelle Methoden
protected:
  virtual void zeichnen_impl() const = 0;

private:
  virtual double flaeche_impl() const = 0;
  Ort referenzkoordinaten;
};

// Standardimplementierung einer rein virtuellen Methode
inline void GraphObj::zeichnen_impl() const { std::cout << "Zeichnen: "; }

// Die Entfernung zwischen 2 \tt{GraphObj}-Objekten ist hier als
// Entfernung ihrer
// Bezugspunkte (überladene Funktion) definiert.
inline double entfernung(const GraphObj& g1, const GraphObj& g2) {
  return entfernung(g1.bezugspunkt(), g2.bezugspunkt());
}
#endif  // GRAPHOBJ_H
