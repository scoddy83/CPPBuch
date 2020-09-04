/* cppbuch/k27/array/stdarrayausgabe.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <array>
#include <iostream>

// template <typename Feldtyp>
// void tabellenausgabe_stdarray(Feldtyp tabelle) {  // geht auch,
// erzwingt aber keinen
// std::array-Parameter. Dann wäre z.B. auch vector möglich
template <typename T, std::size_t Z>
void tabellenausgabe_stdarray(const std::array<T, Z>& tabelle) {
  for (auto wert : tabelle) {
    std::cout << wert << ' ';
  }
  std::cout << '\n';
  // alternativ
  for (unsigned int i = 0; i < tabelle.size(); ++i) {
    std::cout << tabelle[i] << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::array<int, 6> feld{{1, 2, 3, 4, 5, 6}};
  tabellenausgabe_stdarray(feld);
}
