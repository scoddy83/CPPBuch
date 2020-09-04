/* cppbuch/k19/templateInst/extern/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "func01.h"
#include "func02.h"
#include <iostream>
int main() {
  std::cout << "Aufruf von func01(): ";
  func01();
  std::cout << "Aufruf von func02(): ";
  func02();
}
