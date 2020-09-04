/* cppbuch/k27/array/stdarray2d.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <array>
#include <cstddef>
#include <iostream>
using namespace std;

int main() {
  constexpr size_t ZEILEN = 2;
  constexpr size_t SPALTEN = 3;
  // Eine 2-dim. Matrix ist ein \tt{array} von \tt{array}s,
  //   die jeweils drei \tt{int}-Werte enthalten.
  array<array<int, SPALTEN>, ZEILEN> matrix{{
      {{1, 2, 3}},  // matrix[0]
      {{4, 5, 6}}   // matrix[1]
  }};

  for (size_t i = 0; i < ZEILEN; ++i) {
    for (size_t j = 0; j < SPALTEN; ++j) {
      cout << matrix[i][j] << ' ';
    }
    cout << '\n';
  }
  // alternativ
  for (size_t i = 0; i < matrix.size(); ++i) {
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      cout << matrix[i][j] << ' ';
    }
    cout << '\n';
  }
  // alternativ
  for (size_t i = 0; i < matrix.size(); ++i) {
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      cout << matrix.at(i).at(j) << ' ';
    }
    cout << '\n';
  }
  // alternativ
  for (const auto& vec : matrix) {
    for (auto wert : vec) {
      cout << wert << ' ';
    }
    cout << '\n';
  }
}
