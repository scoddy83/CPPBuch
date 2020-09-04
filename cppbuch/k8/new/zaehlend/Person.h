/* cppbuch/k8/new/zaehlend/Person.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H_
#define PERSON_H_
#include "ZaehlendesObjekt.h"
#include <iostream>
#include <string_view>

class Person : public ZaehlendesObjekt {
public:
  Person(const std::string_view& n) 
    : name(n) {
  }

  virtual ~Person() {
    std::cout << "Person-Destruktor aufgerufen (" << name << ")" << std::endl;
  }
  Person(const Person&) = default;
  Person& operator=(const Person&) = default;
  auto getName() const { return name; }

private:
  std::string_view name;
};

#endif /*PERSON_H_*/
