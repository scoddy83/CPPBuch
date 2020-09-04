/* cppbuch/k12/lambda1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cmath>  // abs()
#include <iostream>
#include <vector>

template <typename T, typename Funktor>
void vektorVerarbeiten(const std::vector<T>& v, const Funktor& funktor) {
  for (const auto& el : v) {
    funktor(el);
  }
}

using namespace std;

int main() {
  vector<double> v{-11.0, 3.2, 4.1, -7.0, 8.0, 1.5, 2.7, -4.4};
  for (auto wert : v) {
    cout << wert << ' ';
  }
  cout << '\n';
  sort(v.begin(), v.end(), [](auto x, auto y) { return x > y; });
  cout << "umgekehrt sortiert:\n";
  for (auto wert : v) {
    cout << wert << ' ';
  }
  cout << '\n';
  sort(v.begin(), v.end(), [](auto x, auto y) { return abs(x) < abs(y); });
  cout << "Nach Absolutbetrag sortiert:\n";
  for (auto wert : v) {
    cout << wert << ' ';
  }
  cout << '\n';

  double summe{0.0};
  vektorVerarbeiten(v, [&summe](auto el) { summe += el; });
  cout << "Summe = " << summe << '\n';

  // Berechnung der Summe aller Werte, die über einem Schwellwert
  // liegen:
  summe = 0.0;
  double schwellwert = -1.2;
  vektorVerarbeiten(v, [=, &summe](auto el) {
    if (el > schwellwert) {  // schwellwert ist hier const
      summe += el;
    }
  });
  cout << "Summe aller Werte > " << schwellwert << " = " << summe << '\n';
}
