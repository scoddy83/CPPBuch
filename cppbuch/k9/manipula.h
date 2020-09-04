/* cppbuch/k9/manipula.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef MANIPULA_H
#define MANIPULA_H
#include <iostream>

class Leerzeilen {
public:
  Leerzeilen(int i = 1) : anzahl{i} {}
  std::ostream& operator()(std::ostream& os) const {
    for (int i = 0; i < anzahl; ++i) {
      os << '\n';
    }
    os.flush();
    return os;
  }

private:
  int anzahl;
};

inline std::ostream& operator<<(std::ostream& os, const Leerzeilen& leerz) {
  return leerz(os);  // Funktoraufruf
}
#endif
