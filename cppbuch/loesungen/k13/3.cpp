/* cppbuch/loesungen/k13/3.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

constexpr unsigned long FibonacciIterativ(unsigned int zahl) {
  unsigned long ergebnis = zahl;
  if (zahl > 1) {
    unsigned long a0 = 0;
    unsigned long a1 = 1;
    for (unsigned int i = 2; i <= zahl; ++i) {
      ergebnis = a0 + a1;
      a0 = a1;
      a1 = ergebnis;
    }
  }
  return ergebnis;
}

// ineffizient, weil viele Werte mehrfach berechnet werden
constexpr unsigned long FibonacciRekursiv(unsigned int zahl) {
  if (zahl < 2) {
    return zahl;
  } else {
    return FibonacciRekursiv(zahl - 1) + FibonacciRekursiv(zahl - 2);
  }
}

int main() {
  std::cout << FibonacciRekursiv(11) << '\n';
  std::cout << FibonacciIterativ(11) << '\n';
}
