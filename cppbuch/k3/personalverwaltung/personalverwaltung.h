/* cppbuch/k3/personalverwaltung/personalverwaltung.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PERSONALVERWALTUNG_H
#define PERSONALVERWALTUNG_H
#include "person.h"
#include <vector>

class Personalverwaltung {
public:
  Personalverwaltung(const std::string& dateiname);

  void ausgeben() const;

  void dialog() const;

private:
  std::vector<Person> personal;
};

#endif
