/* cppbuch/k13/variadicTemplate/foldexpr1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <string_view>

template <typename... Args> 
void anzeigen(Args&&... args) {
  (std::cout << ... << args) << '\n';  // Fold Expression
}

int main() {
  std::string_view einString("String ");
  anzeigen(einString, "Textliteral ", 7.978353);
}
