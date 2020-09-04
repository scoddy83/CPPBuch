/* cppbuch/loesungen/k13/1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

template <int n> struct Fakultaet {
  enum { wert = n * Fakultaet<n - 1>::wert };
};

template <> struct Fakultaet<0> {
  enum { wert = 1 };
};

int main() { std::cout << Fakultaet<8>::wert << '\n'; }
