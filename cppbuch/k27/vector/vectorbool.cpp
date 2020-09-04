/* cppbuch/k27/vector/vectorbool.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <vector>
#include <showContainer.h>

int main() {
  std::vector<bool> vecBool(4, true);  // alles true
  vecBool.flip();                 // alles false
  vecBool[1].flip();              // Bit 1 wird true
  std::cout.setf(std::ios_base::boolalpha);
  showContainer(vecBool);
}
