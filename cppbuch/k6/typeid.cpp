/* cppbuch/k6/typeid.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <typeinfo>
#define PRINT(X) std::cout << (#X) << " = " << std::boolalpha << (X) << '\n'

class Basis {
public:
  virtual ~Basis() = default;               // für polymorphe Klasse sorgen
  Basis() = default;
  Basis(const Basis&) = default;
  Basis& operator=(const Basis&) = default;
};

class Abgeleitet : public Basis {};

int main() {
  Abgeleitet Objekt1;
  Abgeleitet Objekt2;
  Basis* p = &Objekt1;
  std::cout << typeid(Objekt1).name() << '\n';
              // \tt{name()}: (compilerabhängiger) Klassenname 
  PRINT(typeid(Objekt2) == typeid(*p));     // \tt{*p} ist polymorph

  Basis einBasisObjekt;
  std::cout << typeid(einBasisObjekt).name() << '\n';
  PRINT(typeid(Objekt1) == typeid(einBasisObjekt));

  Basis* pNull = nullptr;
  PRINT(typeid(Objekt1) == typeid(*pNull)); // Exception
}
