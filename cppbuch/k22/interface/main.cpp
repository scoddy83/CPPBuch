/* cppbuch/k22/interface/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Anbieter.h"
#include "Nutzer.h"
#include <iostream>

int main() {
  Anbieter anbieter;
  Nutzer nutzer(anbieter);
  std::cout << "Nutzerdaten = " << nutzer.getDaten() << '\n';
  nutzer.nutzen();
  std::cout << "Nutzerdaten nach Service des Anbieters= " << nutzer.getDaten()
            << '\n';
}
