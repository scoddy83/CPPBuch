/* cppbuch/k4/matrix2d.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

int main() {
  constexpr unsigned int ZEILEN = 2;
  constexpr unsigned int SPALTEN = 3;
  int matrix[ZEILEN][SPALTEN] = {{1, 2, 3}, {4, 5, 6}};

  for (unsigned int i = 0; i < ZEILEN; ++i) {
    for (unsigned int j = 0; j < SPALTEN; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}
