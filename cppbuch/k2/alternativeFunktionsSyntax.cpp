/* cppbuch/k2/alternativeFunktionsSyntax.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

// Funktionsprototyp (Deklaration)
// unsigned long fakultaet(int); 'normale' Syntax
auto fakultaet(unsigned int) -> unsigned long;  // alternative Funktionssyntax

int main() {
  int n;
  do {
    cout << "Fakultät berechnen. Zahl >= 0? :";
    cin >> n;
  } while (n < 0);

  cout << "Das Ergebnis ist " << fakultaet(n) << '\n';  // Aufruf
}

// Funktionsimplementation (Definition)
// unsigned long fakultaet(int zahl) {   ODER wahlweise:
auto fakultaet(unsigned int zahl) -> unsigned long {
  unsigned long fak = 1;
  for (unsigned int i = 2; i <= zahl; ++i) {
    fak *= i;
  }
  return fak;
}
