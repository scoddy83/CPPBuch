/* cppbuch/k13/variadicTemplate/ifconstexpr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

template <typename T, typename... Rest>
void verdoppeln(T&& obj, Rest&&... rest) {
  *obj *= 2;
  if
    constexpr(sizeof...(rest) > 0) { verdoppeln(rest...); }
}

template <typename... Args> void f3(Args&&... args) {
  verdoppeln(&args...);  // Expansion &p1, &p2, &p3
}

int main() {
  int i1 = 1;
  int i2 = 7;
  f3(i1, i2);
  std::cout << i1 << ' ' << i2 << '\n';  // 2 14
}
