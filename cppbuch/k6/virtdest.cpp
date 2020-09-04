/* cppbuch/k6/virtdest.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

#define PRINT(X) std::cout << (#X) << " = " << (X) << '\n'

class Basis {
  double bWert;
public:
  Basis(double b = 0.0) 
    : bWert(b) {
  }
  virtual ~Basis() {  // virtueller Destruktor!
    std::cout << "Objekt " << bWert << " Basis-Destruktor aufgerufen!\n";
  }

  Basis(const Basis&) = default;  // Regel der großen Drei, siehe Seite \pageref{bigthree1}
  Basis& operator=(const Basis&) = default; // dito
};

class Abgeleitet : public Basis {
  double aWert;
public:
  Abgeleitet(double b = 0.0, double a = 0.0) 
    : Basis(b), aWert(a) {
  }

  ~Abgeleitet() {
    std::cout << "Objekt " << aWert << " Abgeleitet-Destruktor aufgerufen!\n";
  }
  Abgeleitet(const Abgeleitet&) = default;  // Regel der großen Drei, siehe Seite \pageref{bigthree1}
  Abgeleitet& operator=(const Abgeleitet&) = default;   // dito
};

int main() {
  Basis* pb = new Basis(1.0);
  PRINT(sizeof(*pb));

  Abgeleitet* pa = new Abgeleitet(2.0, 2.2);
  PRINT(sizeof(*pa));

  Basis* pba = new Abgeleitet(3.0, 3.3);
  PRINT(sizeof(*pba));

  std::cout << "pb löschen:\n";
  delete pb;  // ok

  std::cout << "pa löschen:\n";
  delete pa;  // ok

  std::cout << "pba löschen:\n";
  delete pba;  // ok nur mit virtuellem Destruktor!
}
