/* cppbuch/include/ort.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ORT_H
#define ORT_H
#include <cassert>
#include <cctype>
#include <cmath>  // wegen \tt{sqrt()}
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

class Ort {
public:
  // Typumwandlungskonstruktor. Format: 2 Folgen von Ziffern
  explicit Ort(const std::string& str) {
    size_t pos = 0;  // Position einer Ziffer im String \tt{str}
    for (unsigned int j = 0; j < 2; j++) {  // für jede Koordinate
      while (pos < str.size() && !isdigit(str[pos])) {  // erste Ziffer suchen
        ++pos;
      }
      assert(pos < str.size());  // Ziffer gefunden? Abbruch, falls nicht
      bool negativ =
          pos > 0 && str[pos - 1] == '-';  // Minuszeichen gefunden?
      // Zahl bilden
      int koordinate = 0;
      while (pos < str.size() && isdigit(str[pos])) {
        // implizite Typumwandlung \tt{char} $\rightarrow$ \tt{int}
        koordinate = 10 * koordinate + str[pos] - '0';
        ++pos;
      }
      if (negativ) {
        koordinate = -koordinate;
      }
      switch (j) {
      case 0:
        xKoordinate = koordinate;
        break;
      case 1:
        yKoordinate = koordinate;
        break;
      default:
        assert(false);  // andere Werte kann es hier nicht geben
      }
    }
  }
  Ort(int einX = 0, int einY = 0) : xKoordinate{einX}, yKoordinate{einY} {}

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
inline auto entfernung(Ort ort1, Ort ort2) {
  double dx = static_cast<double>(ort1.getX() - ort2.getX());
  double dy = static_cast<double>(ort1.getY() - ort2.getY());
  return std::sqrt(dx * dx + dy * dy);
}

// Anzeige auf der Standardausgabe
inline void anzeigen(Ort O) {
  std::cout << '(' << O.getX() << ", " << O.getY() << ')';
}

// Gleichheitsoperator
inline bool operator==(Ort ort1, Ort ort2) {
  return (ort1.getX() == ort2.getX() && ort1.getY() == ort2.getY());
}

// Überladen des Ausgabeoperators zur Ausgabe eines Ortes
inline std::ostream& operator<<(std::ostream& os, Ort einOrt) {
  os << " (" << einOrt.getX() << ", " << einOrt.getY() << ')';
  return os;
}
#endif
