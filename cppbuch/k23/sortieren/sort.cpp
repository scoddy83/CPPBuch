/* cppbuch/k23/sortieren/sort.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <Random.h>
#include <algorithm>
#include <showContainer.h>
#include <vector>

bool intVergleich(double x, double y) {
  return static_cast<long>(x) < static_cast<long>(y);
}
using namespace std;

int main() {
  vector<double> v(17);
  Random zufallg(v.size() / 3);             // ganzzahliger Anteil, siehe unten
  Random zufallRest(1000);
  // Vektor mit Zufallswerten initialisieren. Dabei sollen einige Werte
  // denselben ganzzahligen Anteil haben, um den Unterschied von stabiler und
  // nicht-stabiler Sortierung sehen zu können.
  for (auto& wert : v) {
    wert = zufallg() + double(zufallRest() / 1000.0);
  }
  vector<double> unstable = v;              // Hilfsvektoren
  vector<double> stable = v;
  cout << "Vektor             :\n";
  showContainer(v);

  // Sortierung mit < Operator:
  cout << "Kein Unterschied, weil double-Zahlen als Key genommen "
          "werden\n"
          "stabile Sortierung   :\n";
  stable_sort(stable.begin(), stable.end());
  showContainer(stable);

  cout << "unstabile Sortierung :\n";
  sort(unstable.begin(), unstable.end());
  showContainer(unstable);

  //  Sortierung mit Funktion statt <
  unstable = v;
  stable = v;
  cout << "Unterschied, weil nur der int-Teil Sortierkriterium "
          "ist\n";

  cout << "stabile Sortierung (int-Kriterium)  :\n";
  stable_sort(stable.begin(), stable.end(), intVergleich);
  showContainer(stable);

  cout << "unstabile Sortierung (int-Kriterium)  :\n";
  sort(unstable.begin(), unstable.end(), intVergleich);
  showContainer(unstable);
}
