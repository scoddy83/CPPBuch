/* cppbuch/k2/per_ref.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

void addiere_7(int& aufDieseZahl);  //   int& = Referenz auf int

int main() {
  int i{0};
  cout << i << " = alter Wert von i\n";
  addiere_7(i);  // Syntax wie bei Übergabe per Wert
  cout << i << " = neuer Wert von i nach addiere_7\n";
}

void addiere_7(int& x) {
  x += 7;  // Original des Aufrufers wird geändert!
}
