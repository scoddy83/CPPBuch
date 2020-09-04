/* cppbuch/loesungen/k3/4/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "rational.h"

int main() {
  constexpr Rational r1(2, 3);
  ausgabe(r1);
  constexpr Rational r2(3, 2);
  ausgabe(r2);
  constexpr Rational radd = add(r1, r2);
  ausgabe(radd);
  constexpr Rational rsub = sub(r1, r2);
  ausgabe(rsub);
  constexpr Rational rmult = mult(r1, r2);
  ausgabe(rmult);
  constexpr Rational rdiv = div(r1, r2);
  ausgabe(rdiv);
}
