/* cppbuch/k19/templateInst/extern/func01.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "func01.h"
#include "meintyp.t"
#include <iostream>
#include <string>
extern template class MeinTyp<std::string>;
void func01() {
  MeinTyp<std::string> mt("func01");
  std::cout << mt.get() << '\n';
}
