/* cppbuch/k1/structured_binding.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

struct Punkt {
  int x;
  int y;
};

int main() {
  Punkt p1{100, 200};
  auto [a, b] = p1;                          // Kopie
  std::cout << "a= " << a << "  b= " << b << '\n';
  auto& [c, d] = p1;                         // Referenz
  c += 50;                                   // ändert \tt{p1.x}
  d += 50;                                   // ändert \tt{p1.y}
  std::cout << "p1.x= " << p1.x << "  p1.y= " << p1.y << '\n';
}
