/* cppbuch/k26/tuple/apply2tuple.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <string>
#include <tuple>
#include <utility>

void func(const std::string& s1, const std::string& s2, int z) {
  std::cout << s1 << ' ' << s2 << ' ' << z << '\n';
}

int main() {
  auto tupel = std::make_tuple("Donald", "Duck", 17);
  std::apply(func, tupel);

  // ohne  apply()
  func(std::get<0>(tupel), std::get<1>(tupel), std::get<2>(tupel));
}
