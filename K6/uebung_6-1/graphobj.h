// cppbuch/k6/erben/graphobj.h
#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include <ort.h>

class GraphObj {
public:
    GraphObj(Ort einOrt) // allgemeiner Konstruktor
      : referenzkoordinaten{einOrt} {}
    
    virtual ~GraphObj() = default;                  // virtueller Konstruktor
    GraphObj(const GraphObj&) = default;            // Regel der grossen Drei
    GraphObj& operator=(const GraphObj&) = default; // dito

    // Bezugspunkte ermitteln
    Ort bezugspunkt() const { return referenzkoordinaten; }

    // alten Bezugspunkt ermitteln und gleichzeitig neuen wählen
    Ort bezugspunkt(Ort n0) {
        Ort temp {referenzkoordinaten};
        referenzkoordinaten = n0;
        return temp;
    }

    // Koordintatenabfrage
    int getX() const { return referenzkoordinaten.getX(); }
    int getY() const { return referenzkoordinaten.getY(); }

    // rein virtuellle Methoden
    virtual double flaeche() const = 0;
    virtual void zeichnen() const = 0;

private:
    Ort referenzkoordinaten;
};

// Standardimplementierung einer rein virtuellen Methode
inline void GraphObj::zeichnen() const { std::cout << "Zeichnen: "; }

// Die Entfernung zwischen 2 GraphObj-Objekten ist hier aös Entfernung ihrer
// Bezugspunkte (überladee Funktion) definiert
inline double entfernung(const GraphObj& g1, const GraphObj& g2) {
    return entfernung(g1.bezugspunkt(), g2.bezugspunkt());   // in ort.h
}

#endif // GRAPHOBJ_H