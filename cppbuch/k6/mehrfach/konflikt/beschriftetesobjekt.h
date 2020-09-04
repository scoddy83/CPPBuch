/* cppbuch/k6/mehrfach/konflikt/beschriftetesobjekt.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef BESCHRIFTETESOBJEKT_H
#define BESCHRIFTETESOBJEKT_H
#include "../../abstrakt/graphobj.h"
#include <string_view>

class BeschriftetesObjekt : public GraphObj {  // erben
public:
  BeschriftetesObjekt(Ort ort, std::string_view b)
    : GraphObj(ort), beschriftung{b} {}

  virtual double flaeche() const override { return 0.0; }

  virtual void zeichnen() const override {
    GraphObj::zeichnen();
    std::cout << "Beschriftung bei ";
    anzeigen(bezugspunkt());
    std::cout << beschriftung << '\n';
  }

private:
  std::string_view beschriftung;
};
#endif  // BESCHRIFTETESOBJEKT_H
