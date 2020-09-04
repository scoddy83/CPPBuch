/* cppbuch/k6/konstruktorerben/Basisklasse.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef BASISKLASSE_H
#define BASISKLASSE_H
#include <string_view>

class Basisklasse {
public:
  Basisklasse(std::string_view bezeichner) 
    : attribut{bezeichner} {
  }

  auto getAttribut() const {
    return attribut; 
  }

private:
  std::string_view attribut;
};
#endif
