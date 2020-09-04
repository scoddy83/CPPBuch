/* cppbuch/k1/vektor.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>  // enthält Sortierfunktion sort()
#include <cstddef>    //  size_t
#include <iostream>
#include <vector>  // Standard-Vektor einschließen
using namespace std;

int main() {                 // Programm mit typischen Vektor-Operationen
  vector<float> kosten(12);  // Tabelle mit 12 \tt{float}-Werten

  // Füllen der Tabelle mit beliebigen Daten, dabei
  // Typumwandlung \tt{int} $\rightarrow$ \tt{float}
  for (size_t i = 0; i < kosten.size(); ++i) {
    kosten[i] = static_cast<float>(150 - i * i) / 10.0f;
  }

  // Tabelle ausgeben
  for (size_t i = 0; i < kosten.size(); ++i) {
    cout << i << ": " << kosten[i] << '\n';
  }

  // Berechnung und Anzeige der Summe $\sum_{i=0}^{anzahl} kosten_i$
  float sum = 0.0;
  for (size_t i = 0; i < kosten.size(); ++i) {
    sum += kosten[i];
  }

  cout << "Summe = " << sum << '\n';

  // Mittelwert anzeigen
  cout << "Mittelwert = " << sum / kosten.size() << '\n';

  // Maximum anzeigen
  float maxi{kosten[0]};
  for (size_t i = 1; i < kosten.size(); ++i) {
    if (maxi < kosten[i]) {
      maxi = kosten[i];
    }
  }
  cout << "Maximum = " << maxi << '\n';

  // zweite Tabelle \tt{sortierteKosten} deklarieren und
  // mit der ersten initialisieren
  vector<float> sortierteKosten{kosten};

  // zweite Tabelle aufsteigend sortieren
  sort(sortierteKosten.begin(), sortierteKosten.end());

  // und mit der laufenden Nummer ausgeben
  for (size_t i = 0; i < sortierteKosten.size(); ++i) {
    cout << i << ": " << sortierteKosten[i] << '\n';
  }
  // Kurzform, wenn die lfd. Nummer nicht gebraucht wird
  for (auto diekosten : sortierteKosten) {
    cout << diekosten << '\n';
  }
}
