/* cppbuch/k2/fakultaet.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
// Funktionsprototyp (Deklaration)
unsigned long fakultaet(unsigned int);

using namespace std;
int main() {
  int n;
  do {
    cout << "Fakultät berechnen. Zahl >= 0? :";
    cin >> n;
  } while (n < 0);

  cout << "Das Ergebnis ist " << fakultaet(n) << '\n';  // Aufruf

  // alternativ mit Zwischenablage des Ergebnisses:
  unsigned long erg = fakultaet(n);
  cout << "Das Ergebnis ist " << erg << '\n';
}

unsigned long
fakultaet(unsigned int zahl) {  // Funktionsimplementation (Definition)
  unsigned long fak = 1;
  for (unsigned int i = 2; i <= zahl; ++i) {
    fak *= i;
  }
  return fak;
}
