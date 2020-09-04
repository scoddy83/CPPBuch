/* cppbuch/k2/gccversion.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

#if __GNUG__
  #define COMPILER "GNU C++ Compiler"
#else
  #define COMPILER "anderer Compiler"
#endif

int main() {
  std::cout << COMPILER << '\n';
  #if __GNUC__ > 5
    std::cout << "Version >= 6: " << __VERSION__ << '\n';
  #endif
}
