/* cppbuch/k28/iteratorMitInitListe.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <initializer_list>
#include <iostream>
#include <iterator>

void f(std::initializer_list<int> liste) {
  auto anfang = std::begin(liste);
  while (anfang != std::end(liste)) {
    std::cout << *anfang++ << '\n';
  }
}

int main() { f({9, 8, 7}); }
