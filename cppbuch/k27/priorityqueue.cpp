/* cppbuch/k27/priorityqueue.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  vector<int> zahlen {1, 5, 6, 0, 9, 1, 8, 7, 2};
  // Standard-Implementierung mit deque und less
  priority_queue<int> einePrioQueue;
  // ALTERNATIV
  // Implementierung der priority_queue mit vector
  // priority_queue<int, vector<int>, greater<int> > einePrioQueue;
  // greater: kleine Elemente zuerst (= hohe Priorität)
  // less:  große Elemente zuerst
  cout << "Zahlen in die Prioritäts-Warteschlange schreiben:\n";
  for (auto zahl : zahlen) {
    cout.width(6);
    cout << zahl;                           // protokollieren
    einePrioQueue.push(zahl);
  }
  cout << "\nZahlen aus der Prioritäts-Warteschlange holen, "
    "anzeigen und löschen:\n";
  while (!einePrioQueue.empty()) {
    cout.width(6);
    cout << einePrioQueue.top();            // 'wichtigsten' Wert anzeigen
    einePrioQueue.pop();                    // Wert löschen
  }
  cout << '\n';
}
