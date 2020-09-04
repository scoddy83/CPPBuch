/* cppbuch/k23/folgen/innerproduct.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  constexpr unsigned int DIMENSION = 4;
  vector<double> v(DIMENSION, 1.0);

  cout << "Länge des Vektors v = "
       << sqrt(inner_product(v.begin(), v.end(), v.begin(), 0.0)) << '\n';

  // Um die Anwendung anderer mathematischer Operatoren zu zeigen,
  // wird im Folgenden die Entfernung zwischen zwei Punkten
  // berechnet.

  // 2 Punkte  p1 und p2
  vector<double> p1(DIMENSION, 1.0);  // Einheitsvektor
  vector<double> p2(DIMENSION);
  iota(p2.begin(), p2.end(), 1.0);  // beliebiger Vektor
  cout << "Entfernung zwischen p1 und p2 = "
       << sqrt(inner_product(p1.begin(), p1.end(), p2.begin(), 0.0,
                             plus<double>(),
                             [](auto x, auto y) {
                               auto d = x - y;
                               return d * d;
                             }))
       << '\n';
}
