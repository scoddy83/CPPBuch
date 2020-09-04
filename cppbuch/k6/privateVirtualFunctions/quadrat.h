/* cppbuch/k6/privateVirtualFunctions/quadrat.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef QUADRAT_H
#define QUADRAT_H
#include "rechteck.h"

class Quadrat : public Rechteck {  // siehe Text
public:
  Quadrat(const Ort& ort, int seite) : Rechteck(ort, seite, seite) {}

private:
  // Definition der rein virtuellen Methode zeichnen
  virtual void zeichnen_impl() const override {
    GraphObj::zeichnen_impl();  // Aufruf der
                                // Standard-Implementierung

    std::cout << "Quadrat (Seitenlaenge = " << hoehe() << ") an der Stelle ";

    anzeigen(bezugspunkt());
    std::cout << '\n';
  }
  /*  Die Methoden  \tt{bezugspunkt()}, \tt{flaeche()},
  \tt{hoehe()},
  \tt{breite()} werden geerbt. */
};
#endif  // QUADRAT_H
