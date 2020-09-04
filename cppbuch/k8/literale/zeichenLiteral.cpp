/* cppbuch/k8/literale/zeichenLiteral.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

char operator"" _upper(char c) {
  if (c >= 'a' && c <= 'z') {
    c -= 32;
  }
  return c;
}

int main() {
  auto c = 'a'_upper;
  std::cout << c << '\n';
}
