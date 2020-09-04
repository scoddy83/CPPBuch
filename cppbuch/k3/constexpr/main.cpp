/* cppbuch/k3/constexpr/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "kreis.h"
#include <iostream>
#include <limits>

int main() {
  constexpr Kreis ck(100.0);  // const und constexpr
  constexpr double cr = ck.getRadius();
  constexpr double cf = ck.getFlaeche();
  std::cout << "Radius = " << cr << ". Fläche =  " << cf << '\n';

  const Kreis k(10.0);  // const
  const double r = k.getRadius();
  const double f = k.getFlaeche();
  std::cout << "Radius = " << r << ". Fläche =  " << f << '\n';

  Kreis k1(210.0);  // nicht const
  k1.setRadius(9.07);
  std::cout << "Radius = " << k1.getRadius()
            << ". Fläche =  " << k1.getFlaeche() << '\n';

  constexpr Kreis skaliert = skalieren(ck, 0.5);
  std::cout << "Radius = " << skaliert.getRadius()
            << ". Fläche =  " << skaliert.getFlaeche() << '\n';

  const Kreis skaliert1 = skalieren(k, 0.5);
  std::cout << "Radius = " << skaliert1.getRadius()
            << ". Fläche =  " << skaliert1.getFlaeche() << '\n';

  // mit negativem Radius Fehler provozieren:
  Kreis falsch1(-3.0);  // Fehlermeldung zur Laufzeit
  // constexpr Kreis falsch2(-3.0);        // Fehlermeldung zur
  // Compilationszeit
}
