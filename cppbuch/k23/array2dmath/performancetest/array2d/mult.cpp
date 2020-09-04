/* cppbuch/k23/array2dmath/performancetest/array2d/mult.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../../array2d.h"
#include <chrono>
#include <iostream>
#include <random>

template <typename T> void zufallswerte(Array2d<T>& array, size_t z, size_t s) {
  std::uniform_real_distribution<T> verteilung(T(-100), T(100));
  std::mt19937 generator;
  for (size_t i = 0; i < z; ++i) {
    for (size_t j = 0; j < s; ++j) {
      array[i][j] = static_cast<T>(verteilung(generator));
    }
  }
}

int main() {
  constexpr size_t SIZE = 500;
  constexpr size_t LOOPS = 20;
  Array2d<double> a1(SIZE, SIZE);
  Array2d<double> a2(a1);
  zufallswerte(a1, SIZE, SIZE);
  zufallswerte(a2, SIZE, SIZE);
  Array2d<double> aerg(SIZE, SIZE);
  std::cout << "Array2d " << SIZE << "x" << SIZE << '\n';
  auto anfang = std::chrono::system_clock::now();
  double temp = 0.0;
  for (size_t i = 0; i < LOOPS; ++i) {
    aerg = a1 * a2;
    aerg[0][0] = aerg[1][1];  // Änderung von aerg und Benutzung von
    temp += aerg[1][1];       // temp verhindert Weg-Optimierung der Schleife
  }
  auto ende = std::chrono::system_clock::now();
  std::cout << temp << " dummy-Ausgabe\n";  // nur um temp zu benutzen
  auto dauer = std::chrono::duration_cast<std::chrono::milliseconds>(ende - anfang);
  std::cout << " Array2d Dauer pro Multiplikation und Zweisung aerg = a1*a2 : \n"
            << 0.001 * dauer.count() / LOOPS << " Sekunden\n\n";


}
