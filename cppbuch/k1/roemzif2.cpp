/* cppbuch/k1/roemzif2.cpp
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
  case 'I':
    ziffer = 1;
    break;
  case 'V':
    ziffer = 5;
    break;
  case 'X':
    ziffer = 10;
    break;
  case 'L':
    ziffer = 50;
    break;
  case 'C':
    ziffer = 100;
    break;
  case 'D':
    ziffer = 500;
    break;
  case 'M':
    ziffer = 1000;
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
