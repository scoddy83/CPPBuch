/* cppbuch/k23/zufallszahlen/gleichverteilungInt.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <Random.h>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  constexpr int MIN = 10;
  constexpr int MAX = 20;
  static_assert(MAX > MIN, "MAX muss > MIN sein!");
  constexpr size_t ITERATIONEN = 100000;
  vector<size_t> haeufigkeit(MAX - MIN + 1, 0);
  Random zufall(MIN, MAX);
  random_device rd;
  // zufall.setSeed(rd()); // ohne '//': keine
  // Reproduzierbarkeit
  // Zufallszahl erzeugen, dabei die Häufigkeit hochzählen:
  for (size_t i = 0; i < ITERATIONEN; ++i) {
    ++haeufigkeit[zufall() - MIN];
  }
  // Häufigkeiten und Mittelwert ausgeben
  double summe = 0.0;
  for (size_t i = 0; i < haeufigkeit.size(); ++i) {
    int wert = i + MIN;
    cout << wert << ": " << haeufigkeit[i] << '\n';
    summe += wert * haeufigkeit[i];
  }
  cout << "Mittelwert: " << summe / ITERATIONEN << '\n';
}
