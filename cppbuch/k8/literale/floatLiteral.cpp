/* cppbuch/k8/literale/floatLiteral.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cmath>
#include <iostream>
#include <pi.h>

constexpr long double operator"" _pi(long double d) {
  return d * pi<long double>;
}

int main() {
  auto z = 2.0_pi;         // Suffix _pi
  std::cout << z << '\n';  // 6.28...
}
