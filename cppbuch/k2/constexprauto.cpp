/* cppbuch/k2/constexprauto.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

auto fakultaet0(unsigned int zahl) {  // nicht \tt{constexpr}
  unsigned long fak = 1;
  while (zahl > 1) {
    fak *= zahl--;
  }
  return fak;
}

constexpr unsigned long fakultaet1(unsigned int zahl) {  // \tt{constexpr}
  return zahl < 2 ? 1 : zahl * fakultaet1(zahl - 1);
}

auto getWert() { return 3u; }  //  nicht-\tt{constexpr}

int main() {
  // \tt{const}, aber nicht \tt{constexpr}
  const auto erg0 = fakultaet0(3);
  std::cout << "Ergebnis = " << erg0 << '\n';

  // \tt{constexpr}-Funktion liefert nicht-\tt{constexpr} Wert
  auto zahl = 4u;  // kein \tt{const}
  auto erg1 = fakultaet1(zahl);
  std::cout << "Ergebnis = " << erg1 << '\n';

  // \tt{constexpr}-Funktion liefert nicht-\tt{constexpr} Wert
  const auto czahl1 = getWert();  // nicht mit \tt{constexpr} initialisiert
  auto erg2 = fakultaet1(czahl1);
  std::cout << "Ergebnis = " << erg2 << '\n';

  // \tt{constexpr}-Funktion liefert \tt{constexpr} Wert
  const auto czahl2 = 3;  // 3 ist Literal
  constexpr auto erg3 = fakultaet1(czahl2);
  std::cout << "Ergebnis = " << erg3 << '\n';

  // \tt{constexpr}-Funktion liefert \tt{constexpr} Wert
  constexpr auto erg4 = fakultaet1(3);  // 3 ist Literal
  std::cout << "Ergebnis = " << erg4 << '\n';
}
