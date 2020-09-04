/* cppbuch/k8/new/eigene/Person.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H_
#define PERSON_H_
#include "Speicherverwaltung.t"
#include <cstddef>
#include <iostream>  // für Testausgaben
#include <string>

namespace {
  bool test{true};  // ggf. auf \tt{false} setzen
}

class Person final {  // nicht ableitbar, kein virtueller Destruktor
 public:
  using Speicher = Speicherverwaltung<Person, 100>;  // Platzbedarf festlegen

  Person(const std::string& n = "N.N.") {
    n.copy(name, sizeof(name) - 1);
    if (test) {
      std::cout << "Person-Konstruktor aufgerufen (" << name
                << ") this=" << this << '\n';
    }
  }
  ~Person() {
    if (test) {
      std::cout << "Person-Destruktor aufgerufen (" << name
                << ") this=" << this << '\n';
    }
  }
  Person(const Person&) = default;
  Person& operator=(const Person&) = default;

  std::string getName() const { return name; }

  static void* operator new(std::size_t size) {
    if (test) {
      std::cout << "new aufgerufen. size=" << size << '\n';
    }
    return Speicher::getMemory(size);
  }
  static void operator delete(void* ptr) {
    if (test) {
      std::cout << "delete aufgerufen. ptr=" << ptr << '\n';
    }
    Speicher::freeMemory(ptr);
  }
  static std::size_t freiePlaetze() { return Speicher::freiePlaetze(); }

 private:
  char name[15]{0};
};

#endif
