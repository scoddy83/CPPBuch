/* cppbuch/k4/carrayIterieren.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <iterator>  // begin() und end()

int main() {
  int carray[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto anfang = std::begin(carray);
  while (anfang != std::end(carray)) {
    std::cout << *anfang++ << '\n';
  }
}
