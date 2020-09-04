/* cppbuch/k2/qsum.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

int qsum(long z) {  // Parameter per Wert übergeben (Grunddatentyp)
  if (z != 0) {
    int letzteZiffer = z % 10;
    return letzteZiffer + qsum(z / 10);  // Rekursion
  } else {                               // Abbruchbedingung \tt{z == 0}
    return 0;
  }
}

int main() {
  std::cout << "Zahl: ";
  long zahl;
  std::cin >> zahl;
  std::cout << "Quersumme = " << qsum(zahl) << '\n';
}
