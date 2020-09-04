/* cppbuch/k5/stringansicht/stringansicht.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef STRINGANSICHT_H
#define STRINGANSICHT_H
#include <cassert>
#include <cstddef>                          // size_t
#include <iostream>                         // ostream

// constrexpr_strlen() gibt es, weil std::strlen() nicht constexpr ist.
constexpr auto constexpr_strlen(const char* str) {
  std::size_t anzahl = 0;
  while(*str++) { ++anzahl; }
  return anzahl;
}

class StringAnsicht {
public:
  constexpr StringAnsicht(const char* str = "")
      : zeiger(str), anzahl(constexpr_strlen(str)) {}

  constexpr auto at(std::size_t position) const {
    assert(position < anzahl);
    return zeiger[position];
  }
  constexpr auto length() const { return anzahl; }
  constexpr auto data() const { return zeiger; }
  constexpr auto begin() const { return zeiger; }
  constexpr auto end() const { return zeiger + anzahl; }

private:
  const char* zeiger;
  std::size_t anzahl;
};

inline void anzeigen(std::ostream& os, StringAnsicht m) {
  os << m.data();
}
#endif
