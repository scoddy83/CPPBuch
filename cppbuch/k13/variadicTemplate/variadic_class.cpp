/* cppbuch/k13/variadicTemplate/variadic_class.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

template <typename... Args> struct Anzahl {
  static int anzahlDerTypen() { return sizeof...(Args); }
};

int main() {
  std::cout << "Anzahl der Typen von von Anzahl<char*, int, double>: "
            << Anzahl<char*, int, double>::anzahlDerTypen() << '\n';
}
