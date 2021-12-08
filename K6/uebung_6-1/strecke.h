// cppbuch/k6/erben/strecke.h
#ifndef STRECKE_H
#define STRECKE_H
#include "graphobj.h"

class Strecke : public GraphObj { // erben von GraphObj
public:
    // Initialisierung mit Initialisierungsliste
    Strecke(Ort ort1, Ort ort2) 
      : GraphObj{ort1},         // initialisierung des Subobjekts, siehe Kap. 6.1
        endpunkt{ort2} {        // Initialisierung des Attributs
        }                       // leerer Code-Block

    double laenge() const {
        return entfernung(bezugspunkt(), endpunkt);
    }

    // Definition der rein virtuellen Methoden
    virtual double flaeche() const override {
        return 0.0;
    }

    virtual void zeichnen() const override {
        GraphObj::zeichnen();
        std::cout << "Strecke_ von ";
        anzeigen(bezugspunkt());
        std::cout << " bis ";
        anzeigen(endpunkt);
        std::cout << '\n';
    }
 
private:
    Ort endpunkt;   // zusätzlich: 2. Punkt der Strecke
    // (der erste ist GraphObj::Referenzkoordinaten)
};

#endif // STRECKE_H