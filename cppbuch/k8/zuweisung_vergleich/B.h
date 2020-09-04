/* cppbuch/k8/zuweisung_vergleich/B.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef B_H
#define B_H
#include "A.h"

class B : public A {
public:
  B(int a_, int b_)
      : A(a_),                              // Oberklassenkonstruktor
        b{b_} {                             // lokale Daten
  }

  virtual B& assign(const A& rhs) {
    std::cout << "virtual B& B::assign=(const A&)\n";
    if (typeid(*this) != typeid(rhs)) {
      throw std::bad_typeid();
    }
    B temp(static_cast<const B&>(rhs));
    swap(temp);
    return *this;
  }

  B& operator=(const B& rhs) {
    std::cout << "B& operator=(const B& rhs)\n";
    return assign(rhs);
  }

  virtual void ausgabe() const {
    A::ausgabe();
    std::cout << "B.b = " << b << ' ';
  }

  void swap(B& rhs) {
    A::swap(rhs);                           // Oberklassendaten
    std::swap(b, rhs.b);                    // lokale Daten
  }

  bool operator==(const A& arg) const {
    return A::operator==(arg) && b == static_cast<const B&>(arg).b;
  }

private:
  int b;
};
#endif
