/* cppbuch/k27/vector/stdvectorausgabe2D.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <vector>
#include <iostream>

// template <typename Feldtyp>
// void tabellenausgabe2D_stdvector(const Feldtyp& tabelle) {  // geht auch,
// ist aber nicht auf Vektoren beschränkt
template <typename T>
void tabellenausgabe2D_stdvector(
    const std::vector<std::vector<T>>& tabelle) {
  for (const auto& vec : tabelle) {
    for (auto wert : vec) {
      std::cout << wert << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

int main() {
  std::vector<std::vector<int>> feld = {{
      {{1, 2, 3}},  // feld[0]
      {{4, 5, 6}}   // feld[1]
  }};
  tabellenausgabe2D_stdvector(feld);
}
