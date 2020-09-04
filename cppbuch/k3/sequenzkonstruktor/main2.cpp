/* cppbuch/k3/sequenzkonstruktor/main2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "zahlenfolge2.h"

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
  Zahlenfolge z4{4, 5, 6};  // äußere Klammern weggelassen
  z4.print();
  Zahlenfolge z5{{7, 8, 9}};  // mit Klammern 
  z5.print();
}
