/* cppbuch/k13/rekursiveTemplates/zweihoch.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

template <int n> struct Zweihoch {
  static const int wert{2 * Zweihoch<n - 1>::wert};
};

template <> struct Zweihoch<0> { 
  static const int wert{1}; 
};

int main() { 
  std::cout << Zweihoch<11>::wert << '\n'; 
}
