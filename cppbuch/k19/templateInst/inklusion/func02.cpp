/* cppbuch/k19/templateInst/inklusion/func02.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "func02.h"
#include "meintyp.t"
#include <iostream>
void func02() {
  MeinTyp<double> mt(3.1415926);
  std::cout << mt.get() << '\n';
}
