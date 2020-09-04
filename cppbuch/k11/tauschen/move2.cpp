/* cppbuch/k11/tauschen/move2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../move/movingstring.h"
#include <iostream>
#include <utility>

void vertauschen(StringTyp&& a, StringTyp&& b) {
  StringTyp tmp(std::move(a));  // bewegender Konstruktor
  a = std::move(b);             // bewegender operator=()
  b = std::move(tmp);           // bewegender operator=()
}

template <class T, class U> void tauschen(T&& a, U&& b) {
  if (&a != &b) {
    vertauschen(std::move(a), std::move(b));
  }
}

int main() {
  StringTyp a("einA");
  StringTyp b("einB");
  std::cout << " a = " << a << "   b = " << b << '\n';
  std::cout << "tauschen(&, &):\n";
  tauschen(a, b);
  std::cout << " a = " << a << "   b = " << b << '\n';
  std::cout << "tauschen(&, &&):\n";
  tauschen(a, StringTyp("temporaerB"));
  std::cout << " a = " << a << '\n';
  std::cout << "tauschen(&&, &):\n";
  tauschen(StringTyp("temporaerA"), b);
  std::cout << " b = " << b << '\n';
}
