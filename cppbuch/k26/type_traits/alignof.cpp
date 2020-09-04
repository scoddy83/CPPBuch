/* cppbuch/k26/type_traits/alignof.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <type_traits>

struct AlignofTest {
  char x;
  double d;
};

int main() {
  std::cout << alignof(AlignofTest) << '\n';
  std::cout << std::alignment_of<AlignofTest>::value << '\n';
}
