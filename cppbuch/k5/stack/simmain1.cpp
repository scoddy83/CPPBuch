/* cppbuch/k5/stack/simmain1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Anwendungsbeispiele für Stack-Template
#include "simstack1.t"
#include <iostream>
using namespace std;

int main() {
  SimpleStack<int> einIntStack;  // ein Stack für int-Zahlen

  // Stack füllen
  int i{100};
  while (!einIntStack.full()) {
    einIntStack.push(i++);
  }
  cout << "Anzahl : " << einIntStack.size() << '\n';

  // oberstes Element anzeigen
  cout << "oberstes Element: " << einIntStack.top() << '\n';

  cout << "alle Elemente entnehmen und anzeigen: \n";
  while (!einIntStack.empty()) {
    i = einIntStack.top();
    einIntStack.pop();
    cout << i << '\t';
  }
  cout << '\n';

  SimpleStack<double> einDoubleStack;       // ein Stack für double-Zahlen

  // Stack mit (beliebigen) Werten füllen
  double d{1.00234};
  while (!einDoubleStack.full()) {
    d = 1.1 * d;
    einDoubleStack.push(d);
    cout << einDoubleStack.top() << '\t';
  }

  // einDoubleStack.push(1099.986);  // Fehler, da Stack voll

  cout << "\n4 Elemente des Double-Stacks entnehmen:\n";
  for (unsigned int j = 0; j < 4; ++j) {
    cout << einDoubleStack.top() << '\t';
    einDoubleStack.pop();
  }
  cout << '\n';

  cout << "Restliche Anzahl : " << einDoubleStack.size() << '\n';
  cout << "clear Stack\n";
  einDoubleStack.clear();
  cout << "Anzahl : " << einDoubleStack.size() << '\n';

  //  einDoubleStack.pop();  // Fehler, da Stack leer
}
