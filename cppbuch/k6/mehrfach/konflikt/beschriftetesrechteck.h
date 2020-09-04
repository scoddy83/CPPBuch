/* cppbuch/k6/mehrfach/konflikt/beschriftetesrechteck.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef BESCHRIFTETESRECHTECK_H
#define BESCHRIFTETESRECHTECK_H
#include "beschriftetesobjekt.h"
#include "../../abstrakt/rechteck.h"

// Mehrfachvererbung
class BeschriftetesRechteck 
  : public BeschriftetesObjekt, public Rechteck {  // Mehrfachvererbung
public:
  BeschriftetesRechteck(Ort ort, int h, int b,
                        std::string_view beschriftung)
    : BeschriftetesObjekt(ort, beschriftung), Rechteck(ort, h, b) {}

  // Definition der rein virtuellen Methoden
  virtual double flaeche() const override {
    // Definition ist notwendig, damit die Klasse nicht abstrakt ist 
    // (durch Vererbung über \tt{BeschriftetesObjekt} und \tt{GraphObj}))
    return Rechteck::flaeche();
  }

  virtual void zeichnen() const override {
    Rechteck::zeichnen();
    BeschriftetesObjekt::zeichnen();
  }
};
#endif  // BESCHRIFTETESRECHTECK_H
