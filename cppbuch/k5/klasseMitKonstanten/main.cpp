/* cppbuch/k5/klasseMitKonstanten/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "KlasseMitKonstanten.h"
#include <iostream>

void f(double x) { std::cout << "f(" << x << ") aufgerufen!\n"; }

void g(const double& x) { std::cout << "g(" << x << ") aufgerufen!\n"; }

const std::string problem = ">" + KlasseMitKonstanten::CONST_STR1 + "<";

int main() {
  std::cout << problem << '\n';             // obige Konstante ausgeben
  // Ausgabe der Klassenkonstanten
  std::cout << KlasseMitKonstanten::drei << '\n';
  std::cout << static_cast<int>(KlasseMitKonstanten::RGB::blau) << '\n';
  std::cout << KlasseMitKonstanten::CONST_DOUBLE << '\n';
  std::cout << KlasseMitKonstanten::CONST_INT << '\n';
  std::cout << KlasseMitKonstanten::CONST_STR1 << '\n';
  std::cout << KlasseMitKonstanten::CONST_STR2 << '\n';

  // Übergabe an Funktionen
  f(KlasseMitKonstanten::drei);  // ok, implizite Umwandlung
  g(KlasseMitKonstanten::drei);  // ok, implizite Umwandlung
  g(static_cast<double>(KlasseMitKonstanten::RGB::blau));  // ok

  f(KlasseMitKonstanten::CONST_DOUBLE);  // ok
  g(KlasseMitKonstanten::CONST_DOUBLE);  // ok nur mit externer
                                         // Definition
}
