/* cppbuch/k13/variadicTemplate/param_expansion.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

void intanzeigen() { std::cout << '\n'; }

template <typename T, typename... Rest>
void intanzeigen(T&& obj, Rest&&... rest) {
  std::cout << obj << ' ';
  intanzeigen(rest...);
}

template <typename... Args> void f1(Args&&... args) {
  intanzeigen(args...);  // Expansion p1, p2, p3
}

template <typename... Args> void f2(Args&&... args) {
  intanzeigen(++args...);  // Expansion ++p1, ++p2, ++p3
}

int main() {
  f1(1, 2, 3);  // 1 2 3
  f2(1, 2, 3);  // 2 3 4
}
