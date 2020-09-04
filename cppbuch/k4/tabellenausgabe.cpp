/* cppbuch/k4/tabellenausgabe.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

void tabellenausgabe2D(int (*T)[3], unsigned int n) {
  // alternativ: void tabellenausgabe(int T[][3], size_t n)
  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned int j = 0; j < 3; ++j) {
      std::cout << T[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

template <typename Feldtyp>
void tabellenausgabe2DT(Feldtyp tabelle,
                        unsigned int zeilen) {  // int (*)[3]
  constexpr unsigned int SPALTEN = sizeof tabelle[0] / sizeof tabelle[0][0];
  for (unsigned int i = 0; i < zeilen; ++i) {
    for (unsigned int j = 0; j < SPALTEN; ++j) {
      std::cout << tabelle[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

template <typename Feldtyp>
void tabellenausgabe2DT(Feldtyp& tabelle) {  // int [2][3]
  constexpr unsigned int ZEILEN = sizeof(Feldtyp) / sizeof(tabelle[0]);
  constexpr unsigned int SPALTEN = sizeof tabelle[0] / sizeof tabelle[0][0];
  for (unsigned int i = 0; i < ZEILEN; ++i) {
    for (unsigned int j = 0; j < SPALTEN; ++j) {
      std::cout << tabelle[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

// alternativ:
template <typename Feldtyp, std::size_t ZEILEN>  // int[3], 2
void tabellenausgabe2DTx(Feldtyp (&tabelle)[ZEILEN]) {
  constexpr unsigned int SPALTEN = sizeof tabelle[0] / sizeof tabelle[0][0];
  for (unsigned int i = 0; i < ZEILEN; ++i) {
    for (unsigned int j = 0; j < SPALTEN; ++j) {
      std::cout << tabelle[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

int main() {
  int feld1[][3] = {{1, 2, 3}, {4, 5, 6}};
  tabellenausgabe2D(feld1, 2);
  // Templates
  tabellenausgabe2DT(feld1, 2);
  tabellenausgabe2DT(feld1);
  tabellenausgabe2DTx(feld1);
}
