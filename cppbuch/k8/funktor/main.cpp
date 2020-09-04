/* cppbuch/k8/funktor/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "sinus.h"
#include <iostream>

template <typename Funktor>
void funktorErgebnisAnzeigen(double arg, const Funktor& funktor) {
  std::cout << funktor(arg) << '\n';
}

int main() {
  Sinus sinrad;
  Sinus sinGrad(Sinus::Modus::grad);

  // Aufruf der Objekte wie eine Funktion
  std::cout << "sin( pi/4 [rad]) = " << sinrad(pi<double> / 4.0) 
            << ". sin(45 Grad)    = " << sinGrad(45.0) << '\n';

  // Übergabe eines Funktors an eine Funktion
  funktorErgebnisAnzeigen(45.0, sinGrad);

  // Lambda-Äquivalent für sinGrad:
  funktorErgebnisAnzeigen(45.0, [](auto arg) { return std::sin(arg / 180.0 * pi<double>); });
}
