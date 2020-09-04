/* cppbuch/k12/lambda2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cmath>
#include <iostream>
#include <vector>

// Funktion zum Summieren. Tatsächlich hängen die Details von der übergebenen Funktion
// f ab. Es wäre z.B. möglich, statt der Summe das Produkt aller Elemente zu berechnen.
template <class Container, typename T, typename Function>
T berechne(Container& cont, T anfangswert, Function f) {
  T ergebnis = anfangswert;
  for (auto wert : cont) {
    ergebnis = f(ergebnis, wert);
  }
  return ergebnis;
}

int main() {
  std::vector<double> v{3.1, 0.2, 22.0, 3.5, 8.99};
  // Berechnung der Summe mit einer generischen Lambda-Funktion
  auto summe = berechne(v, 0.0, [](auto sum, auto w) { return sum + w; });

  // Initialisierung des Mittelwerts mit summe/v.size() in der Lambda-Funktion
  auto varianz = berechne(v, 0.0,
                          [mittelwert = summe / v.size()](auto sum, auto w) {
                            auto diff = w - mittelwert;
                            return sum + diff * diff;
                          }) /
                 v.size();
  std::cout << "\nStandardabweichung = " << std::sqrt(varianz) << '\n';

  // Variante  mit verschachtelter Lambda-Funktion
  auto varianz2 =
      berechne(
          v, 0.0,
          [mittelwert =
               berechne(v, 0.0, [](auto sum, auto w) { return sum + w; }) /
               v.size()](auto sum, auto w) {
            auto diff = w - mittelwert;
            return sum + diff * diff;
          }) /
      v.size();
  std::cout << "\nStandardabweichung = " << std::sqrt(varianz2) << '\n';
}
