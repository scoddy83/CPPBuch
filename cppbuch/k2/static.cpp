/* cppbuch/k2/static.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

void func() {         // zählt die Anzahl der Aufrufe
  static int anz{0};  // siehe Text
  std::cout << "Anzahl = " << ++anz << '\n';
}

int main() {
  for (int i = 0; i < 3; ++i) {
    func();
  }
}
