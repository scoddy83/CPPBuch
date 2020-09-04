/* cppbuch/k8/zuweisung_vergleich/A.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef A_H
#define A_H
#include <algorithm>                       // \tt{swap()}
#include <iostream>
#include <typeinfo>

class A {
public:
  A(int a_) : a{a_} {}
  virtual ~A() = default;

  virtual A& assign(const A& rhs) {
    std::cout << "virtual A& A::assign(const A&)\n";
    if (typeid(*this) != typeid(rhs)) {     // siehe Text unten
      throw std::bad_typeid();
    }
    A temp(rhs);
    swap(temp);
    return *this;
  }

  A& operator=(const A& rhs) {
    std::cout << "A& operator=(const A& rhs)\n";
    return assign(rhs);
  }

  virtual void ausgabe() const { std::cout << "A.a = " << a << ' '; }

  void swap(A& rhs) { std::swap(a, rhs.a); }

  virtual bool operator==(const A& arg) const {
    return typeid(*this) == typeid(arg)     // siehe Text unten
           && a == arg.a;
  }

private:
  int a;
};
#endif
