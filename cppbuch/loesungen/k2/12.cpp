/* cppbuch/loesungen/k2/12.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Welche Fehler hat die untenstehende Funktion?
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

/*** Achtung, fehlerhaft! ***/
void bubblesort(vector<int>& feld) {
  /* Diese Prozedur vergleicht ein Vektor-Element mit dem
  vorhergehenden und vertauscht die Elemente, sofern
  das Element kleiner als der Vorgänger ist.
  Dieser Vorgang wird solange wiederholt, bis das Element {\tt
  temp} unverändert bleibt, also nichts mehr zu sortieren ist.
  Dadurch bedingt, ist dieser Bubble-Sort bei teilweise
  vorsortierten Feldern im Mittel etwas schneller als eine Variante
  mit zwei geschachtelten Schleifen fixer Durchlaufanzahl. */
  int temp;
  do {
    temp = feld[0];
    for (std::size_t j = 1; j < feld.size(); j++) {
      if (feld[j] < feld[j - 1]) {  // vertauschen
        temp = feld[j - 1];
        feld[j - 1] = feld[j];
        feld[j] = temp;
      }
    }
  } while (temp != feld[0]);  // keine Vertauschung mehr
}

int main() {
  vector<int> v(9);  // vector<int> v; // zeigt Fehler 1
  if (v.size() > 8) {
    v[0] = 8;
    v[1] = 101;
    v[2] = 38;
    v[3] = 1;
    v[4] = 0;
    v[5] = -3;
    v[6] = 99;
    v[7] = 1010;
    v[8] = 4000;
  }
  // v[0]=1200; v[1]=1200; // zeigt Fehler 2
  cout << "unsortiert:\n";
  for (std::size_t i = 0; i < v.size(); i++)
    cout << ' ' << v[i];
  cout << '\n';
  bubblesort(v);
  cout << "sortiert:\n";
  for (std::size_t i = 0; i < v.size(); i++)
    cout << ' ' << v[i];
  cout << '\n';
}
