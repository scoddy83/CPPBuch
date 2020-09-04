/* cppbuch/k3/constexpr/kreis.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef KREIS_H
#define KREIS_H
#include <iostream>
#include <pi.h>

class Kreis {
public:
  constexpr Kreis(double r) : radius(r) {
    if (radius < 0) {
      std::cerr << "Fehler: negativer Radius" << std::endl;
      exit(1);
    }
  }

  constexpr double getRadius() const { return radius; }

  constexpr double getFlaeche() const { return radius * radius * pi<double>; }

  constexpr void setRadius(double r) { radius = r; }

private:
  double radius;
};

constexpr Kreis skalieren(const Kreis& k, double faktor) {
  Kreis temp = k;
  temp.setRadius(k.getRadius() * faktor);
  return temp;
}

#endif
