/* cppbuch/k27/set.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <set>
#include <showContainer.h>
using namespace std;

int main() {
  set<int> einSet;  //  vordefinierter Vergleich: less<int>()

  for (int i = 0; i < 10; ++i)
    einSet.insert(i);
  for (int i = 0; i < 10; ++i)
    einSet.insert(i);     // keine Wirkung
  showContainer(einSet);  // 0 1 2 3 4 5 6 7 8 9

  /* Die Ausgabe zeigt, dass die Elemente trotz zweifachen
  insert()-Aufrufs
  nur einmal vorkommen. Im nächsten Teil wird ein Element gelöscht,
  einmal über einen Iterator, und einmal über seinen Wert.*/

  cout << "Löschen mit Iterator\nWelches Element? (0..9)";
  int i;
  cin >> i;
  auto iter = einSet.find(i);
  if (iter == einSet.end()) {
    cout << i << " nicht gefunden!\n";
  } else {
    // count() kann nur 0 oder 1 ergeben.
    cout << "Das Element " << i  // 1
         << " existiert " << einSet.count(i) << " mal.\n";
    einSet.erase(iter);
    cout << i << " gelöscht!\n";
    cout << "Das Element " << i  // 0
         << " existiert " << einSet.count(i) << " mal.\n";
  }
  showContainer(einSet);

  cout << "Löschen durch Suche nach dem Wert\n"
          "Welches Element? (0..9)";
  cin >> i;
  auto anzahl = einSet.erase(i);
  if (anzahl == 0) {
    cout << i << "  nicht gefunden!\n";
  }
  showContainer(einSet);

  cout << "Konstruktor mit Iterator-Bereich\n";

  // 2 und 1 zweimal!
  int tabelle[]{1, 2, 2, 3, 4, 9, 13, 1, 0, 5};
  set<int> zahlenSet(tabelle, tabelle + size(tabelle));
  showContainer(zahlenSet);  // 0 1 2 3 4 5 9 13
}
