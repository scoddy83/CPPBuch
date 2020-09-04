/* cppbuch/k13/variadicTemplate/foldexprkommaOp.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

template <typename... Args> 
void f5(Args&&... args) {
  ((args *= 2), ...);
}

int main() {
  int i1 = 1;
  int i2 = 7;
  f5(i1, i2);
  std::cout << i1 << ' ' << i2 << '\n';  // 2 14
}
