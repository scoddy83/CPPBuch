/* cppbuch/k4/qsort.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstdlib>  // enthält Prototyp von qsort()
#include <cstring>
#include <iostream>
using namespace std;

// Definition der Vergleichsfunktion
int icmp(const void* a, const void* b) {
  // Typumwandlung der Zeiger auf \tt{void} in Zeiger auf \tt{int}
  // und anschließende Dereferenzierung (von rechts lesen)
  // Die Typumwandlung meint, dass der Speicherinhalt,
  // auf den \tt{a} und  \tt{b} verweisen, als \tt{int} zu
  // interpretieren ist.
  int ia{*static_cast<const int*>(a)};
  int ib{*static_cast<const int*>(b)};

  // Vergleich und Ergebnisrückgabe ( > 0, = 0, oder < 0)
  if (ia == ib)
    return 0;
  return ia > ib ? 1 : -1;
}

int main() {
  int ifeld[]{100, 22, 3, 44, 6, 9, 2, 1, 8, 9};
  constexpr auto anzahlElemente = size(ifeld);
  qsort(ifeld, anzahlElemente, sizeof(ifeld[0]), icmp);  // sortieren
  for (unsigned int i = 0; i < anzahlElemente;
       ++i) {  // Ausgabe des sortierten Feldes
    cout << " " << ifeld[i];
  }
  cout << '\n';
}
