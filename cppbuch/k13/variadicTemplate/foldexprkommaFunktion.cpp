/* cppbuch/k13/variadicTemplate/foldexprkommaFunktion.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

void verdoppeln(int& x) { x *= 2; }

template <typename... Args> 
void f4(Args&&... args) {
  (verdoppeln(args), ...);
}

int main() {
  int i1 = 1;
  int i2 = 7;
  f4(i1, i2);
  std::cout << i1 << ' ' << i2 << '\n';  // 2 14
}
