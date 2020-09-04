/* cppbuch/k27/stack.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  vector<int> zahlen {1, 5, 6, 0, 9, 1, 8, 7, 2};
  stack<int> einStack;
  cout << "Zahlen auf dem Stack ablegen:\n";
  for (auto zahl : zahlen) {
    cout.width(6);
    cout << zahl;                           // protokollieren
    einStack.push(zahl);
  }
  cout << "\nZahlen vom Stack holen (umgekehrte Reihenfolge!),"
          " anzeigen und löschen:\n";
  while (!einStack.empty()) {
    cout.width(6);
    cout << einStack.top();                 // obersten Wert anzeigen
    einStack.pop();                         // Wert löschen
  }
  cout << '\n';
}
