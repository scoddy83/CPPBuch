/* cppbuch/k1/ungenau.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  float a{1.234567E-7f};
  float b{1.000000f};
  float c{-b};
  cout << "Ungenauigkeit bei float-Arithmetik:\n";
  cout << "(a+b)+c = " << (a+b)+c << '\n';  // 1.19209e-7
  cout << "a+(b+c) = " << a+(b+c) << '\n';  // 1.23457e-7
  cout << ( 2^3 ) << '\n';
}
