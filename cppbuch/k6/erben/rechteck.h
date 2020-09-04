/* cppbuch/k6/erben/rechteck.h
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

  double flaeche() const {
    // \tt{int}-Überlauf vermeiden
    return static_cast<double>(dieHoehe) * dieBreite;
  }

private:
  int dieHoehe;
  int dieBreite;
};
#endif  // RECHTECK_H
