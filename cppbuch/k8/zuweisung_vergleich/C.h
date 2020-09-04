/* cppbuch/k8/zuweisung_vergleich/C.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef C_H
#define C_H
#include "B.h"

class C : public B {
public:
  C(int a_, int b_, int c_)
      : B(a_, b_),                          // Oberklassen-Subobjekt
        c{c_} {                             // lokale Daten
  }

  virtual C& assign(const A& rhs) {
    std::cout << "virtual C& C::assign=(const A&)\n";
    if (typeid(*this) != typeid(rhs)) {
      throw std::bad_typeid();
    }
    C temp(static_cast<const C&>(rhs));
    swap(temp);
    return *this;
  }

  C& operator=(const C& rhs) {
    std::cout << "C& operator=(const C& rhs)\n";
    return assign(rhs);
  }

  virtual void ausgabe() const {
    B::ausgabe();
    std::cout << "C.c = " << c << ' ';
  }

  void swap(C& rhs) {
    B::swap(rhs);                           // Oberklassendaten
    std::swap(c, rhs.c);                    // lokale Daten
  }

  bool operator==(const A& arg) const {
    return B::operator==(arg) && c == static_cast<const C&>(arg).c;
  }

private:
  int c;
};
#endif
