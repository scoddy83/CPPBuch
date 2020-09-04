/* cppbuch/loesungen/k13/2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

template <int n> struct Fibonacci {
  enum { wert = Fibonacci<n - 1>::wert + Fibonacci<n - 2>::wert };
};

template <> struct Fibonacci<0> {
  enum { wert = 0 };
};

template <> struct Fibonacci<1> {
  enum { wert = 1 };
};

int main() { 
  std::cout << Fibonacci<11>::wert << '\n'; 
}
