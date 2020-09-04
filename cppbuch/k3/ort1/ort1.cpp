/* cppbuch/k3/ort1/ort1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "ort1.h"
#include <iostream>

int Ort1::getX() const { return xKoordinate; }

int Ort1::getY() const { return yKoordinate; }

void Ort1::aendern(int x, int y) {
  xKoordinate = x;
  yKoordinate = y;
  std::cout << "Ort1-Objekt geändert! x = " << xKoordinate
            << " y = " << yKoordinate << '\n';
}
