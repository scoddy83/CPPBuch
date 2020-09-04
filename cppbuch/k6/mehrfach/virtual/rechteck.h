/* cppbuch/k6/mehrfach/virtual/rechteck.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef RECHTECK_H
#define RECHTECK_H
#include "../../abstrakt/graphobj.h"

class Rechteck : virtual public GraphObj {  // von \tt{GraphObj} erben
public:
  Rechteck(Ort ort, int h, int b)
    : GraphObj(ort), dieHoehe{h}, dieBreite{b} {}

  auto hoehe() const { return dieHoehe; }
  auto breite() const { return dieBreite; }

  // Definition der rein virtuellen Methoden
  virtual double flaeche() const override { return double(dieHoehe) * dieBreite; }

  virtual void zeichnen() const override {
    GraphObj::zeichnen();
    std::cout << "Rechteck (h x b = " << dieHoehe << " x " << dieBreite
              << ") an der Stelle ";
    anzeigen(bezugspunkt());
    std::cout << '\n';
  }

private:
  int dieHoehe, dieBreite;
};
#endif  // RECHTECK_H
