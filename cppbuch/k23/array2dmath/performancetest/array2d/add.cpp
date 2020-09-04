/* cppbuch/k23/array2dmath/performancetest/array2d/add.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../../array2d.h"
#include <chrono>
#include <iostream>
using namespace std;

int main() {
  constexpr size_t SIZE = 1000;
  constexpr size_t LOOPS = 1000;
  // Array2d
  Array2d<double> a1(SIZE, SIZE, 3.14159);
  Array2d<double> a2(SIZE, SIZE, 2.7182);
  Array2d<double> a3(SIZE, SIZE, 1.11111);
  Array2d<double> aerg(SIZE, SIZE);
  cout << "Array " << SIZE << "x" << SIZE << '\n';
  auto anfang = std::chrono::system_clock::now();
  double temp = 0.0;
  for (size_t i = 0; i < LOOPS; ++i) {
    aerg = -a1 + 2.0 * a2 + a3;
    aerg[0][0] = aerg[1][1];  // Änderung von aerg und Benutzung von
    temp += aerg[1][1];       // temp verhindert Weg-Optimierung der Schleife
  }
  auto ende = std::chrono::system_clock::now();
  std::cout << temp << "dummy-Ausgabe\n";  // nur um temp zu benutzen
  auto dauer = std::chrono::duration_cast<std::chrono::milliseconds>(ende - anfang);
  cout << " Array2d Dauer pro Addition aerg = -a1 + 2.0 *a2 + a3; : "
       << dauer.count() / static_cast<double>(LOOPS) << " Millisekunden\n\n";
}
