/* cppbuch/k27/array/stdarrayausgabe2D.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <array>
#include <iostream>

// template <typename Feldtyp>
// void tabellenausgabe2D_stdarray(Feldtyp tabelle) {  // geht auch,
// aber nicht nur f.
// arrays
template <typename T, std::size_t S, std::size_t Z>
void tabellenausgabe2D_stdarray(
    const std::array<std::array<T, S>, Z>& tabelle) {
  for (const auto& vec : tabelle) {
    for (auto wert : vec) {
      std::cout << wert << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

int main() {
  std::array<std::array<int, 3>, 2> feld = {{
      {{1, 2, 3}},  // feld[0]
      {{4, 5, 6}}   // feld[1]
  }};
  tabellenausgabe2D_stdarray(feld);
}
