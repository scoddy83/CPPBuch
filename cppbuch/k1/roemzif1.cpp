/* cppbuch/k1/roemzif1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Umwandlung römischer Ziffern
#include <iostream>
using namespace std;

int main() {
  int ziffer = 0;
  char zeichen;
  cout << "Zeichen ?";
  cin >> zeichen;

  if (zeichen == 'I') {
    ziffer = 1;
  } else if (zeichen == 'V') {
    ziffer = 5;
  } else if (zeichen == 'X') {
    ziffer = 10;
  } else if (zeichen == 'L') {
    ziffer = 50;
  } else if (zeichen == 'C') {
    ziffer = 100;
  } else if (zeichen == 'D') {
    ziffer = 500;
  } else if (zeichen == 'M') {
    ziffer = 1000;
  }
  if (ziffer == 0) {
    cout << "keine römische Ziffer!\n";
  } else {
    cout << ziffer << '\n';
  }
}
