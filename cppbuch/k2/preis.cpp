/* cppbuch/k2/preis.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <string>

// Funktionsprototyp,        2. Parameter mit Vorgabewert:
void preisAnzeige(double preis, const std::string& waehrung = "Euro");

// Hauptprogramm
int main() {
  // zwei Aufrufe mit unterschiedlicher Parameterzahl :
  preisAnzeige(12.35);  // vorgegebener Parameter wird eingesetzt
  preisAnzeige(99.99, "US-Dollar");
}

// Funktionsimplementation
void preisAnzeige(double preis, const std::string& waehrung) {
  std::cout << preis << ' ' << waehrung << '\n';
}
