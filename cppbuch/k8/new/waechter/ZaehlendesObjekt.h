/* cppbuch/k8/new/waechter/ZaehlendesObjekt.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ZAEHLENDESOBJEKT_H
#define ZAEHLENDESOBJEKT_H
#include <cstddef>
#include <iostream>
#include <set>

class ZaehlendesObjekt {
public:
  friend class Waechter;
  ZaehlendesObjekt() {
    ++gesamt;
    istHeapObjekt = (1 == objekte.count(this));
    std::cout << (istHeapObjekt ? "Heap" : "Stack") << "-Objekt " << this
              << " erzeugt.\n";
  }
  virtual ~ZaehlendesObjekt() {
    --gesamt;
    std::cout << (istHeapObjekt ? "Heap" : "Stack") << "-Objekt " << this
              << " zerstört.\n";
  }
  static void status() {
    std::cout << "Es gibt " << gesamt << " Objekt(e), davon "
              << objekte.size() << " Heap-Objekt(e)\n";
  }
  static void* operator new(std::size_t size) {
    void* ptr = ::operator new(size);
    objekte.insert(ptr);
    return ptr;
  }
  static void operator delete(void* ptr) {
    objekte.erase(ptr);
    ::operator delete(ptr);
  }

private:
  bool istHeapObjekt;
  static std::set<void*> objekte;
  static int gesamt;
};

#endif
