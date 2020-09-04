/* cppbuch/k6/abstrakt/rechteck.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef RECHTECK_H
#define RECHTECK_H
#include "graphobj.h"

class Rechteck : public GraphObj {  // von \tt{GraphObj} erben
public:
  Rechteck(Ort ort, int h, int b)
      : GraphObj{ort}, dieHoehe{h}, dieBreite{b} {}

  // wird von \tt{Quadrat} benötigt
  auto hoehe() const { return dieHoehe; }

  auto breite() const { return dieBreite; }

  // Definition der rein virtuellen Methoden
  virtual double flaeche() const override {
    return static_cast<double>(dieHoehe) * dieBreite;
  }

  virtual void zeichnen() const override {
    GraphObj::zeichnen();
    std::cout << "Rechteck (h x b = " << dieHoehe << " x " << dieBreite
              << ") an der Stelle ";
    anzeigen(bezugspunkt());
    std::cout << '\n';
  }

private:
  int dieHoehe;
  int dieBreite;
};
#endif  // RECHTECK_H
