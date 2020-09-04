/* cppbuch/k3/kopierkonstruktor/ortMitKopierkonstruktor.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ORTMITKOPIERKONSTRUKTOR_H
#define ORTMITKOPIERKONSTRUKTOR_H
#include <cmath>  // wegen \tt{sqrt()}
#include <iostream>

class Ort {
public:
  Ort(int einX = 0, int einY = 0) : xKoordinate(einX), yKoordinate(einY) {}

  Ort(const Ort& orig)  // Kopierkonstruktor
      : xKoordinate(orig.xKoordinate), yKoordinate(orig.yKoordinate) {
    std::cout << "Kopierkonstruktor für (" << xKoordinate << ", "
              << yKoordinate << ") aufgerufen\n";
  }

  int getX() const { return xKoordinate; }
  int getY() const { return yKoordinate; }
  void aendern(int x, int y) {
    xKoordinate = x;
    yKoordinate = y;
  }

private:
  int xKoordinate;
  int yKoordinate;
};

// globale Funktionen

// Berechnung der Entfernung zwischen zwei Orten
inline double entfernung(const Ort& ort1, const Ort& ort2) {
  double dx = static_cast<double>(ort1.getX() - ort2.getX());
  double dy = static_cast<double>(ort1.getY() - ort2.getY());
  return std::sqrt(dx * dx + dy * dy);
}

// Anzeige auf der Standardausgabe
inline void anzeigen(const Ort& O) {
  std::cout << '(' << O.getX() << ", " << O.getY() << ')';
}
#endif
