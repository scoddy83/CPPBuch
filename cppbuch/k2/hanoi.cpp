/* cppbuch/k2/hanoi.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

void bewegen(unsigned int n, unsigned int quelle, unsigned int ziel,
             unsigned int zwischen) {
  if (n > 0) {                               // Abbruchbedingung: n == 0
    bewegen(n - 1, quelle, zwischen, ziel);  // rekursiver Aufruf
    std::cout << "Bringe eine Scheibe von " << quelle << " nach " << ziel
              << '\n';
    bewegen(n - 1, zwischen, ziel, quelle);  // rekursiver Aufruf
  }
}

int main() {
  std::cout << "Türme von Hanoi! Anzahl der Scheiben: ";
  unsigned int scheiben;
  // besser nicht 64 eingeben, sondern eine kleinere Zahl,
  // zum Beispiel 4 (Begründung siehe unten).
  std::cin >> scheiben;
  bewegen(scheiben, 1, 2, 3);
}
