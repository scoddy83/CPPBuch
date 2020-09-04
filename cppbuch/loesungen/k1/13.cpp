/* cppbuch/loesungen/k1/13.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  constexpr int MINIMUM{-99};
  constexpr int MAXIMUM{100};
  constexpr int INTERVALLZAHL{10};
  constexpr int INTERVALLBREITE{(MAXIMUM - MINIMUM + 1) / INTERVALLZAHL};
  int eingabe;
  vector<int> intervalle(INTERVALLZAHL);

  cout << "Bitte Zahlen im Bereich " << MINIMUM << " bis " << MAXIMUM
       << " eingeben:\n";

  cin >> eingabe;
  while (eingabe >= MINIMUM && eingabe <= MAXIMUM) {
    intervalle[(eingabe - MINIMUM) / INTERVALLBREITE]++;
    cin >> eingabe;
  }
  for (int i = 0; i < INTERVALLZAHL; i++) {
    cout << "Intervall " << i * INTERVALLBREITE + MINIMUM << " .. "
         << (i + 1) * INTERVALLBREITE + MINIMUM - 1 << ": " << intervalle[i]
         << '\n';
  }
}
