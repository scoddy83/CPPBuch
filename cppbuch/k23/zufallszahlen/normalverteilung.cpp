/* cppbuch/k23/zufallszahlen/normalverteilung.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main() {
  constexpr double MIN = -3.0;  // darzustellender Bereich
  constexpr double MAX = 3.0;
  constexpr size_t INTERVALLE = 80;  // Auflösung der Ausgabe (Spalten)
  constexpr size_t ZEILEN = 20;      // Auflösung der Ausgabe (Zeilen)
  constexpr double INTERVALLBREITE = (MAX - MIN) / INTERVALLE;
  constexpr size_t ITERATIONEN = 1000000;

  vector<size_t> haeufigkeit(INTERVALLE, 0);
  normal_distribution<> gauss(0.0, 1.0);  // Mittelwert, Standardabweichung
  mt19937 generator;
  random_device rd;
  generator.seed(rd());  // jedesmal neue Werte
  // Zufallszahl erzeugen, dabei die Häufigkeit hochzählen
  for (size_t i = 0; i < ITERATIONEN; ++i) {
    double wert = gauss(generator);
    if (wert > MIN && wert < MAX) {
      ++haeufigkeit[static_cast<size_t>((wert - MIN) / INTERVALLBREITE)];
    }  // else.. Außenbereiche ignorieren
  }
  // Darstellung der Glockenkurve auf der Konsole
  size_t max = *max_element(haeufigkeit.begin(), haeufigkeit.end());
  for (size_t i = 0; i < ZEILEN; ++i) {
    for (size_t j = 1; j < INTERVALLE; ++j) {
      double grenze =
          static_cast<double>(haeufigkeit[j]) * ZEILEN / max + 0.5;
      cout << (grenze <= (ZEILEN - i) ? ' ' : '*');
    }
    cout << '\n';
  }
}
