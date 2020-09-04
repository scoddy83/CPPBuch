/* cppbuch/k23/folgen/statistik.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  vector<double> v(6);
  iota(v.begin(), v.end(), 1);  // Vektor füllen
  double summe =
      accumulate(v.begin(), v.end(), 0.0);  // 0.0 (double), nicht: 0
  // weil der Typ den Typ des Ergebnisses bestimmt (sonst
  // Genauigkeitsverlust).
  cout << "Summe             : " << summe << '\n';
  double mittelwert = summe / v.size();
  cout << "Mittelwert        : " << mittelwert << '\n';
  double varianz = accumulate(v.begin(), v.end(), 0.0,
                              [mittelwert](auto sum, auto w) {
                                auto diff = w - mittelwert;
                                return sum + diff * diff;
                              }) /
                   v.size();
  cout << "Varianz           : " << varianz
       << "\nStandardabweichung: " << sqrt(varianz) << '\n';
}
