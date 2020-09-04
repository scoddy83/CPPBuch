/* cppbuch/k12/lambdafunktion.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

//constexpr // ist möglich 
auto lambdafunktion = [](int a, int b) { return a + b; };

int (*funktionszeiger)(int, int) = [](int a, int b) { return a + b; };
// alternativ: int (*funktionszeiger) (int, int) = lambdafunktion;

int main() {
  // Aufruf mit Lambda-Funktion
  std::cout << lambdafunktion(1, 99) << '\n';  // 100
  // Aufruf über Funktionszeiger
  std::cout << funktionszeiger(1, 99) << '\n';  // 100
}
