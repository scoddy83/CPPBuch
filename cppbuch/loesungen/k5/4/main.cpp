/* cppbuch/loesungen/k5/4/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Anwendungsbeispiele für Stack-Template
#include "meinstack.t"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
  MeinStack<int> einIntStack;  // ein Stack für int-Zahlen

  // Stack mit 10 Zahlen füllen
  int i = 100;
  while (einIntStack.size() < 10)
    einIntStack.push(i++);
  cout << "Anzahl : " << einIntStack.size() << '\n';

  // oberstes Element anzeigen
  cout << "oberstes Element: " << einIntStack.top() << '\n';

  cout << "alle Elemente entnehmen und anzeigen:\n";
  while (!einIntStack.empty()) {
    i = einIntStack.top();
    einIntStack.pop();
    cout << i << '\t';
  }
  cout << '\n';

  // ein Stack für double-Zahlen
  MeinStack<double> einDoubleStack;

  // Stack mit 7 (beliebigen) Werten füllen
  double d = 1.00234;
  while (einDoubleStack.size() < 7) {
    d = 1.1 * d;
    einDoubleStack.push(d);
    cout << einDoubleStack.top() << '\t';
  }

  // einDoubleStack.push(1099.986);  // Fehler, da Stack voll

  cout << "\n4 Elemente des Double-Stacks entnehmen:\n";
  for (i = 0; i < 4; ++i) {
    cout << einDoubleStack.top() << '\t';
    einDoubleStack.pop();
  }
  cout << '\n';

  cout << "Restliche Anzahl : " << einDoubleStack.size() << '\n';

  cout << "clear Stack\n";
  einDoubleStack.clear();
  cout << "Anzahl : " << einDoubleStack.size() << '\n';

  // einDoubleStack.pop();  // Fehler, da Stack leer
}
