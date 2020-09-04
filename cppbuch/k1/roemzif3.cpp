/* cppbuch/k1/roemzif3.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  int ziffer{-1};
  char zeichen;
  cout << "Zeichen ?";
  cin >> zeichen;
  switch (zeichen) {
  case 'i':
    [[fallthrough]]; case 'I' : ziffer = 1;
    break;
  case 'v':
    [[fallthrough]]; case 'V' : ziffer = 5;
    break;
  case 'x':
    [[fallthrough]]; case 'X' : ziffer = 10;
    break;
  case 'l':
    [[fallthrough]]; case 'L' : ziffer = 50;
    break;
  case 'c':
    [[fallthrough]]; case 'C' : ziffer = 100;
    break;
  case 'd':
    [[fallthrough]]; case 'D' : ziffer = 500;
    break;
  case 'm':
    [[fallthrough]]; case 'M' : ziffer = 1000;
    break;
  default:
    ziffer = 0;
  }
  if (ziffer > 0) {
    cout << "Ziffer = " << ziffer;
  } else {
    cout << "keine römische Ziffer!";
  }
  cout << '\n';
}
