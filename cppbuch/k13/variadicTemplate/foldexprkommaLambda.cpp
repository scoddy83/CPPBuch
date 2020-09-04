/* cppbuch/k13/variadicTemplate/foldexprkommaLambda.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

template <typename... Args, typename Func> 
void f6(Func f, Args&&... args) {
  (f(args), ...);
}

int main() {
  int i1 = 1;
  int i2 = 7;
  f6( [](auto& el) { el *= 2;}, i1, i2);
  std::cout << i1 << ' ' << i2 << '\n';  // 2 14
}
