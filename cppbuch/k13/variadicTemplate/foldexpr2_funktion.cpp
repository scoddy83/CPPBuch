/* cppbuch/k13/variadicTemplate/foldexpr2_funktion.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
// mit zusätzlicher Funktion, die auf jeden Parameter angewendet wird

int verdoppeln(int x) { return x *= 2; }

template <typename T, typename... Args>
int addiere_auf_anfangswert(T&& anfangswert, Args&&... args) {
  return (verdoppeln(args) + ... + anfangswert);
}

int main() { std::cout << addiere_auf_anfangswert(10, 1, 2, 3, 4) << '\n'; }
