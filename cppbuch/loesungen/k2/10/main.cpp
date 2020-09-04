/* cppbuch/loesungen/k2/10/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "gettype.t"
#include <iostream>
// Die Wertzuweisungen dienen nur dazu, die Warnungen des Compilers
// auszuschalten.
int main() {
  int i = 0;
  std::cout << getType(i) << '\n';
  unsigned int ui = 0;
  std::cout << getType(ui) << '\n';
  float f = 0.0;  // nicht in getType() berücksichtigt!
  std::cout << getType(f) << '\n';
  double d = 0.0;
  std::cout << getType(d) << '\n';
  char c = 0;
  std::cout << getType(c) << '\n';
  bool b = true;
  std::cout << getType(b) << '\n';
}
