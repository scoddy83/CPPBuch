/* cppbuch/k22/bidirektionaleAssoziation/Person.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <set>
#include <string>

class Person {
public:
  Person(const std::string& name_) 
    : name(name_) {
  }

  virtual ~Person() = default;
  Person(const Person&) = default;
  Person& operator=(const Person&) = default;

  const std::string& getName() const { 
    return name; 
  }

  void lerntkennen(Person& p) {
    bool nichtvorhanden = bekannte.insert(&p).second;
    if (nichtvorhanden) {  // falls unbekannt, auch bei \tt{p} eintragen
      p.lerntkennen(*this);
    }
  }

  void bekannteZeigen() const {
    std::cout << "Die Bekannten von " << getName() << " sind:\n";
    for (auto bekannt : bekannte) {
      std::cout << bekannt->getName() << '\n';
    }
  }

private:
  std::string name;
  std::set<Person*> bekannte;
};

#endif /*PERSON_H*/
