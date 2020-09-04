/* cppbuch/k23/vermischtes/gcd_lcm.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <numeric>

int main() {
  short a = 6;
  int b = 9;
  std::cout << "gcd("   << a << ", " << b << ") = " << std::gcd(a, b)
            << "\nlcm(" << a << ", " << b << ") = " << std::lcm(a, b)
            << '\n';
}
