/* cppbuch/k26/type_traits/typrelation.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <type_traits>  // \tt{is\_class}
#include <vector>

class Basis {};

class Abgeleitet : public Basis {};

int main() {
  std::cout << std::boolalpha;
  std::cout << std::is_same<Basis, int>::value << '\n';           // false
  std::cout << std::is_same<Basis, Basis>::value << '\n';         // true
  std::cout << std::is_same<Abgeleitet, Basis>::value << "\n\n";  // false

  std::cout << std::is_base_of<Abgeleitet, Basis>::value << '\n';    // false
  std::cout << std::is_base_of<Basis, const Basis>::value << '\n';   // true
  std::cout << std::is_base_of<Basis, Abgeleitet>::value << "\n\n";  // true

  std::cout << std::is_convertible<Abgeleitet, Basis>::value << '\n';  // true
  std::cout << std::is_convertible<Basis, Abgeleitet>::value
            << '\n';                                             // false
  std::cout << std::is_convertible<int*, void*>::value << '\n';  // true
  std::cout << std::is_convertible<void*, int*>::value << '\n';  // false
}
