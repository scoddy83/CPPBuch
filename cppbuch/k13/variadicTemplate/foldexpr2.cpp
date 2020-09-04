/* cppbuch/k13/variadicTemplate/foldexpr2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

template <typename T, typename... Args>
int addiere_auf_anfangswert(T&& anfangswert, Args&&... args) {
  return (args + ... + anfangswert);
}

int main() { std::cout << addiere_auf_anfangswert(10, 1, 2, 3, 4) << '\n'; }
