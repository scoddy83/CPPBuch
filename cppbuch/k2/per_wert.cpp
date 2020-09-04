/* cppbuch/k2/per_wert.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

int addiere_5(int);  // Deklaration (Funktionsprototyp)

int main() {
  int i{0};
  std::cout << i << " = Wert von i\n";
  auto erg = addiere_5(i);  // Aufruf
  std::cout << erg << " = Ergebnis von addiere_5\n";
  std::cout << i << " = i unverändert!\n";
}

int addiere_5(int x) {  // Definition
  x += 5;
  return x;
}
