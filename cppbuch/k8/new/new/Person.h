/* cppbuch/k8/new/new/Person.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H_
#define PERSON_H_
#include "Objekt.h"
#include <iostream>
#include <string_view>

class Person : public Objekt {
public:
  Person(const std::string_view& n = "N.N.") 
    : name{n} {
    std::cout << "sizeof name = " << sizeof name << '\n';
    std::cout << "sizeof *this = " << sizeof *this << '\n';
  }
  ~Person() {
    std::cout << "Person-Destruktor aufgerufen (" << name << ")\n";
  }
  Person(const Person&) = default;
  Person& operator=(const Person&) = default;
  auto getName() const { return name; }

private:
  std::string_view name;
};

#endif
