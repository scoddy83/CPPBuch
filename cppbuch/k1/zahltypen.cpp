/* cppbuch/k1/zahltypen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  int i1 = 1000000;
  // mit Trennzeichen
  int i2 = 0xabc'def;
  int i3 = 1'048'576;
  double d1 = 1'000'345.789;
  cout << i1 << '\n' << i2 << '\n' << i3 << '\n' << d1 << '\n';
}
