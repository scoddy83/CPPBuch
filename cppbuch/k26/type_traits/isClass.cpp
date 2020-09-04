/* cppbuch/k26/type_traits/isClass.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <type_traits>  // \tt{is\_class}
#include <vector>

class X {};

int main() {
  std::cout << std::boolalpha;
  std::cout << std::is_class<int>::value << '\n';
  std::cout << std::is_class<X>::value << '\n';
  std::cout << std::is_class<std::vector<double>>::value << '\n';
}
