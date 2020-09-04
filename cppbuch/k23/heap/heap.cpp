/* cppbuch/k23/heap/heap.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  // Container für Heap
  showContainer(v);                                     //
  // gültigen Heap erzeugen
  make_heap(v.begin(), v.end());
  showContainer(v);  // 11 10 6 8 9 5 0 7 3 1 4 2
  // Die beiden Zahlen der höchsten Priorität anzeigen und
  // entfernen:
  auto last = v.end();
  cout << *v.begin() << '\n';  // 11
  pop_heap(v.begin(), last--);

  cout << *v.begin() << '\n';  // 10
  pop_heap(v.begin(), last--);

  /* Das Ende des Heaps wird nicht mehr durch \tt{v.end()} markiert,
  sondern
  durch den Iterator \tt{last}. Bezüglich der Heap-Eigenschaften von
  \tt{v}
  ist der Bereich dazwischen undefiniert. */

  // 'wichtige' Zahl einfügen (99)
  *last = 99;
  push_heap(v.begin(), ++last);

  // 'unwichtige' Zahl einfügen (-1)
  *last = -1;
  push_heap(v.begin(), ++last);

  // Anzeige des vollständigen Heaps (keine vollständige Sortierung,
  // nur
  // Heap-Bedingung!)
  showContainer(v);
  // Anzeige aller Zahlen nach Priorität
  while (last != v.begin()) {
    cout << *v.begin() << ' ';
    pop_heap(v.begin(), last--);
  }
  cout << '\n';
  // neuen gültigen Heap erzeugen
  make_heap(v.begin(), v.end());

  // und sortieren
  sort_heap(v.begin(), v.end());
  // Anzeigen der vollständig sortierten Folge
  showContainer(v);
}
