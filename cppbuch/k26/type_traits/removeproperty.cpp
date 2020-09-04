/* cppbuch/k26/type_traits/removeproperty.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <type_traits>
#include <vector>

class X {};

int main() {
  std::cout << std::boolalpha;
  std::cout << std::is_same<X, std::remove_reference<X&>::type>::value
            << '\n';  // true
  // std::remove_reference_t<X&> x; x ist vom Typ X

  std::cout << std::is_same<const int*,
                            std::remove_const<const int*>::type>::value
            << '\n';  // true
  std::cout << std::is_same<const int*,
                            std::remove_const<const int* const>::type>::value
            << '\n';  // true
  std::cout << std::is_same<int*,
                            std::remove_const<int* const>::type>::value
            << '\n';  // true

  std::cout << std::is_same<int, std::decay<int&>::type>::value
            << '\n';  // true
  std::cout << std::is_same<int, std::decay<const int>::type>::value
            << '\n';  // true

  std::cout << std::is_same<X, std::decay<const X&>::type>::value
            << '\n';  // true

  std::cout << std::is_same<X*, std::decay<X[]>::type>::value
            << '\n';  // true
}
