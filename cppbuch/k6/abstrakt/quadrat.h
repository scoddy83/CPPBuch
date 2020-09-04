/* cppbuch/k6/abstrakt/quadrat.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef QUADRAT_H
#define QUADRAT_H
#include "rechteck.h"

class Quadrat : public Rechteck {  // siehe Text
public:
  Quadrat(Ort ort, int seite) 
    : Rechteck(ort, seite, seite) {
  }

  // Überschreiben der virtuellen Methode
  virtual void zeichnen() const override {
    GraphObj::zeichnen();
    std::cout << "Quadrat (Seitenlaenge = " << hoehe() << ") an der Stelle ";
    anzeigen(bezugspunkt());
    std::cout << '\n';
  }
  //  Die Methoden  \tt{bezugspunkt()}, \tt{flaeche()}, \tt{hoehe()}, \tt{breite()} werden geerbt. 
};
#endif  // QUADRAT_H
