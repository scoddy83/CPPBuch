/* cppbuch/k5/stack/simmain2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Anwendungsbeispiele für Stack-Template
#include "simstack2.t"
#include <iostream>
using namespace std;

int main() {
  // ein Stack für 100 int-Zahlen
  SimpleStack<int, 100> einIntStack;
  // Stack füllen
  int i = 100;
  while (!einIntStack.full()) {
    einIntStack.push(i++);
  }
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
}
