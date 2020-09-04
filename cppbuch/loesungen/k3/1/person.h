/* cppbuch/loesungen/k3/1/person.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H
#define PERSON_H
#include <string>

enum class Geschlecht { m, w };

class Person {
public:
  Person(const std::string& name_, unsigned int alter_, Geschlecht g)
      : name{name_}, alter{alter_}, geschlecht{g} {}
  const std::string& getName() const { return name; }
  void setName(const std::string& neuerName) { name = neuerName; }
  unsigned int getAlter() const { return alter; }
  void setAlter(unsigned int neuesAlter) { alter = neuesAlter; }
  bool istFrau() const { return geschlecht == Geschlecht::w; }
  bool istMann() const { return geschlecht == Geschlecht::m; }

private:
  std::string name;
  unsigned int alter;
  Geschlecht geschlecht;
};
#endif
