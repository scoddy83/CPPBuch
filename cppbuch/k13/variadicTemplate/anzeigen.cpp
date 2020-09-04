/* cppbuch/k13/variadicTemplate/anzeigen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
// nach [GrJ]

void anzeigen() { std::cout << '\n'; }

template <typename T, typename... Rest>
void anzeigen(T&& obj, Rest&&... rest) {
  std::cout << obj << ' ';
  // Erweiterung Anfang
  // std::cout << " [" << sizeof...(Rest) << " Typ-Parameter] ";
  // std::cout << " [" << sizeof...(rest) << " Funktions-Parameter]\n";
  // Erweiterung Ende
  anzeigen(rest...);
}

int main() {
  anzeigen(1);
  anzeigen(2, "Hallo");
  anzeigen("Text", 7.978353, 3);
}
