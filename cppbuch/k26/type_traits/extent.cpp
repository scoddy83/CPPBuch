/* cppbuch/k26/type_traits/extent.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <type_traits>

int main() {
  // Ausgabe der Grenze der N-ten Dimension (Zählung ab 0)
  std::cout << std::extent<int[2][3][4]>::value << '\n';     // 2
  std::cout << std::extent<int[2][3][4], 1>::value << '\n';  // 3
  std::cout << std::extent<int[2][3][4], 2>::value << '\n';  // 4

  // Dimension 3 existiert nicht (Zählung ab 0!)
  std::cout << std::extent<int[2][3][4], 3>::value << '\n';  // 0
  // keine grenze für die 0.te Dimension:
  std::cout << std::extent<int[][8]>::value << '\n';  // 0
}
