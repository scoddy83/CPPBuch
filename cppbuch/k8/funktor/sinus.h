/* cppbuch/k8/funktor/sinus.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef SINUS_H
#define SINUS_H
#include <cmath>  //  sin()
#include <pi.h>

class Sinus {
public:
  enum class Modus { bogenmass, grad };
  Sinus(Modus m = Modus::bogenmass) 
: berechnungsart{m} {
}

  double operator()(double arg) const {
    double erg;
    switch (berechnungsart) {
    case Modus::bogenmass:
      erg = std::sin(arg);
      break;
    case Modus::grad:
      erg = std::sin(arg / 180.0 * pi<double>);
      break;
    }
    return erg;
  }
private:
  Modus berechnungsart;
};

#endif
