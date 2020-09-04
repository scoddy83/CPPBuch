/* cppbuch/k26/funktionsobjekt/function.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <functional>
#include <iostream>
#include <showContainer.h>  // cppbuch/include
#include <vector>

void berechnung(const std::vector<double>& v1, const std::vector<double>& v2,
                std::vector<double>& ergebnis,
                const std::function<double(double, double)>& f) {
  assert((v1.size() == v2.size()) && (v1.size() == ergebnis.size()));
  for (std::size_t i = 0; i < v1.size(); ++i) {
    ergebnis[i] = f(v1[i], v2[i]);  // Funktionsaufruf
  }
}

double differenzquadrat(double arg1, double arg2) {
  return (arg1 - arg2) * (arg1 - arg2);
}

int main() {
  // als Variable verwenden
  std::function<double(double, double)> malnehmen = std::multiplies<double>();
  std::cout << malnehmen(4, 42) << '\n';

  std::vector<double> a{1.00, 2.00, 3.00, 4.00, 5.00};
  std::vector<double> b{1.01, 2.02, 3.03, 4.04, 5.05};
  std::vector<double> erg(b.size());

  // Tabelle mit Funktionen
  std::vector<std::function<double(double, double)>> funktionen;
  funktionen.push_back(std::plus<double>());    // \tt{std::}-Funktor
  funktionen.push_back(differenzquadrat);       // Funktion
  double (*fptr)(double, double) = differenzquadrat;
  funktionen.push_back(fptr);                   // Funktionszeiger

  // Zugriff auf die Funktionen
  for (auto f : funktionen) {
    berechnung(a, b, erg, f);
    showContainer(erg);
  }
  // Zugriff auf verschiedene Funktionen per Index i
  for (size_t i = 0; i < funktionen.size(); ++i) {
    berechnung(a, b, erg, funktionen[i]);
    showContainer(erg);
  }
}
