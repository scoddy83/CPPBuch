/* cppbuch/loesungen/k6/2/prof.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PROF_H
#define PROF_H
#include "person.h"
#include <string>

class ProfessorIn : public Person {
public:
  ProfessorIn(const std::string& nachname, const std::string& vorname,
              const std::string& lgb)
      : Person{nachname, vorname}, lehrgebiet{lgb} {}
  const std::string& getLehrgebiet() const { return lehrgebiet; }
  virtual std::string toString() const override {
    return "Prof. " + Person::toString() + ", Lehrgebiet: " + lehrgebiet;
  }

private:
  std::string lehrgebiet;
};
#endif
