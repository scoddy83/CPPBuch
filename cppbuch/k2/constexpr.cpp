/* cppbuch/k2/constexpr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

unsigned long fakultaet0(unsigned int zahl) {  // nicht \tt{constexpr}
  unsigned long fak = 1;
  while (zahl > 1) {
    fak *= zahl--;
  }
  return fak;
}

constexpr unsigned long fakultaet1(unsigned int zahl) {  // \tt{constexpr}
  return zahl < 2 ? 1 : zahl * fakultaet1(zahl - 1);
}

unsigned int getWert() { return 3; }  //  nicht-\tt{constexpr}

int main() {

  // \tt{const}, aber nicht \tt{constexpr}
  const unsigned long erg0 = fakultaet0(3);
  std::cout << "Ergebnis = " << erg0 << '\n';

  // \tt{constexpr}-Funktion liefert nicht-\tt{constexpr} Wert
  unsigned int zahl = 4;  // kein \tt{const}
  unsigned long erg1 = fakultaet1(zahl);
  std::cout << "Ergebnis = " << erg1 << '\n';

  // \tt{constexpr}-Funktion liefert nicht-\tt{constexpr} Wert
  const unsigned int czahl1 =
      getWert();  // nicht mit \tt{constexpr} initialisiert
  unsigned long erg2 = fakultaet1(czahl1);
  std::cout << "Ergebnis = " << erg2 << '\n';

  // \tt{constexpr}-Funktion liefert \tt{constexpr} Wert
  const int czahl2 = 3;  // 3 ist Literal
  constexpr unsigned long erg3 = fakultaet1(czahl2);
  std::cout << "Ergebnis = " << erg3 << '\n';

  // \tt{constexpr}-Funktion liefert \tt{constexpr} Wert
  constexpr unsigned long erg4 = fakultaet1(3);  // 3 ist Literal
  std::cout << "Ergebnis = " << erg4 << '\n';
}
