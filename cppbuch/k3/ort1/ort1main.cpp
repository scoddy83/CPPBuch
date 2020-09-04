/* cppbuch/k3/ort1/ort1main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "ort1.h"  // Definition der Klasse einlesen
#include <iostream>

int main() {     // Anwendung der \tt{Ort1}-Klasse
  Ort1 einOrt1;  // Objekt erzeugen
  einOrt1.aendern(100, 200);
  std::cout << "Der Ort hat die Koordinaten x = " << einOrt1.getX()
            << " und y = " << einOrt1.getY() << '\n';
  const Ort1 co = einOrt1;  // konstantes Objekt
  int x = co.getX();
  std::cout << x << '\n';
}
