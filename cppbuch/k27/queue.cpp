/* cppbuch/k27/queue.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  vector<int> zahlen {1, 5, 6, 0, 9, 1, 8, 7, 2};
  queue<int> eineQueue;
  cout << "Zahlen in die Warteschlange schreiben:\n";
  for (auto zahl : zahlen) {
    cout.width(6);
    cout << zahl;                           // protokollieren
    eineQueue.push(zahl);
  }
  cout << "\nZahlen aus der Warteschlange holen, "
    "anzeigen und löschen:\n";
  while (!eineQueue.empty()) {
    cout.width(6);
    cout << eineQueue.front();  // ersten Wert anzeigen
    eineQueue.pop();            // Wert löschen
  }
  cout << '\n';
}
