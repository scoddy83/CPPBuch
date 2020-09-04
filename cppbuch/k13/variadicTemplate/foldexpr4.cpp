/* cppbuch/k13/variadicTemplate/foldexpr4.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

template <typename... Args> int summe(Args&&... args) { return (... + args); }

int main() { std::cout << summe(1, 2, 3, 4, 5) << '\n'; }
