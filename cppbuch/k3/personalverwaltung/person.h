/* cppbuch/k3/personalverwaltung/person.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
public:
  Person(const std::string& name_, const std::string& personalnummer_)
      : name{name_}, personalnummer{personalnummer_} {}
  const auto& getName() const { return name; }
  const auto& getPersonalnummer() const { return personalnummer; }

private:
  std::string name;
  std::string personalnummer;
};

#endif
