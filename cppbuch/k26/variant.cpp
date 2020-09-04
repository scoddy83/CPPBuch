/* cppbuch/k26/variant.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <variant>

int main() {
  std::variant<int, float> v;
  v = 10;                                   // v enthält ein int
  std::cout << std::get<int>(v) << '\n';
  std::cout << std::get<0>(v) << '\n';
  v = 12.3f;                                // v enthält jetzt ein float
  std::cout << std::get<float>(v) << '\n';
  std::cout << std::get<1>(v) << '\n';
  // jetzt ungültig, weil v ein float enthält:
  //std::cout << std::get<int>(v) << '\n';
  //std::cout << std::get<0>(v) << '\n';
}
