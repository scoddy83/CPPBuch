/* cppbuch/k6/konstruktorerben/Abgeleiteteklasse.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ABGELEITETEKLASSE_H
#define ABGELEITETEKLASSE_H
#include "Basisklasse.h"

class Abgeleiteteklasse : public Basisklasse {
public:
  using Basisklasse::Basisklasse;  // Basisklassen-Konstruktoren erben

  Abgeleiteteklasse(std::string_view bez, int nr)
    : Basisklasse{bez}, wert{nr} {}

  auto getWert() const {
    return wert; 
  }

private:
  int wert{99};                          // Initialisierung
};

#endif
