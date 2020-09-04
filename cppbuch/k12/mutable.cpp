/* cppbuch/k12/mutable.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

int main() {
  const int x=3;
  auto f = [y=x] () mutable { y += x; return y; };
  std::cout <<  f() << '\n';
}
