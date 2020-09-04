/* cppbuch/k6/privateVirtualFunctions/rechteck.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef RECHTECK_H
#define RECHTECK_H
#include "graphobj.h"

class Rechteck : public GraphObj {  // von \tt{GraphObj} erben
public:
  Rechteck(const Ort& ort, int h, int b)
      : GraphObj{ort}, dieHoehe{h}, dieBreite{b} {}

  // wird von \tt{Quadrat} benötigt
  auto hoehe() const { return dieHoehe; }
  auto breite() const { return dieBreite; }

private:
  // Definition der rein virtuellen Methoden
  virtual double flaeche_impl() const override {
    return static_cast<double>(dieHoehe) * dieBreite;
  }

  virtual void zeichnen_impl() const override {
    GraphObj::zeichnen_impl();
    std::cout << "Rechteck (h x b = " << dieHoehe << " x " << dieBreite
              << ") an der Stelle ";
    anzeigen(bezugspunkt());
    std::cout << '\n';
  }

  int dieHoehe;
  int dieBreite;
};
#endif  // RECHTECK_H
