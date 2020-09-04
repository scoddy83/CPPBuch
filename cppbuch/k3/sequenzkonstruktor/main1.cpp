/* cppbuch/k3/sequenzkonstruktor/main1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "zahlenfolge1.h"

int main() {
  Zahlenfolge z0;
  z0.print();
  Zahlenfolge z1{};
  z1.print();
  Zahlenfolge z2{1};
  z2.print();
  Zahlenfolge z3{2, 3};
  z3.print();
  Zahlenfolge z3a(2, 3);
  z3a.print();
}
