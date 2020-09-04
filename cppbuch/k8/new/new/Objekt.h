/* cppbuch/k8/new/new/Objekt.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef OBJEKT_H_
#define OBJEKT_H_
#include <cstddef>
#include <iostream>

class Objekt {
public:
  virtual ~Objekt() {
    std::cout << "Objekt-Destruktor aufgerufen (" << this << ")\n";
  }
  Objekt() = default;
  Objekt(const Objekt&) = default;
  Objekt& operator=(const Objekt&) = default;

  static void* operator new(std::size_t size) {
    std::cout << "new aufgerufen. size=" << size << '\n';
    return ::operator new(size);
  }
  static void operator delete(void* ptr, std::size_t size) {
    std::cout << "delete aufgerufen. size=" << size << '\n';
    ::operator delete(ptr);
  }
  static void* operator new[](std::size_t size) {
    std::cout << "new[] aufgerufen. size=" << size << '\n';
    return ::operator new[](size);
  }
  static void operator delete[](void* ptr, std::size_t size) {
    std::cout << "delete[] aufgerufen. size=" << size << '\n';
    ::operator delete[](ptr);
  }
};

#endif
