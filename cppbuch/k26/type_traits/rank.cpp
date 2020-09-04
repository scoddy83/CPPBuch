/* cppbuch/k26/type_traits/rank.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <type_traits>

int main() {
  std::cout << std::rank<int[2][3][4]>::value << '\n';  // 3
  std::cout << std::rank<char>::value << '\n';          // 0
}
