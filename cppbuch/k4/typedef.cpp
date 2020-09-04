/* cppbuch/k4/typedef.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

typedef float real;   // neuer Name mit \tt{typedef}
using REAL = double;  // neuer Name mit \tt{using}

int main() {
  real zahl1{1.7353f};  // \tt{zahl1} ist vom Typ \tt{float}
  REAL zahl2{3.1415};   // \tt{zahl2} ist vom Typ \tt{double}
  std::cout << zahl1 << '\n';
  std::cout << zahl2 << '\n';
}
