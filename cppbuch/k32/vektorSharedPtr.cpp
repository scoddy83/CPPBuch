/* cppbuch/k32/vektorSharedPtr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Beispiel: Vektor mit shared_ptr
#include "Ressource.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<std::shared_ptr<Ressource>> vps(10);
  // Initialisierung aller Elemente:
  for (std::size_t i = 0; i < vps.size(); ++i) {
    vps[i] = std::make_shared<Ressource>(i);
    // statt vps[i] = std::shared_ptr<Ressource>(new Ressource(i));
  }
  // Benutzung:
  std::cout << "Werte:\n";
  for (auto ptr : vps) {
    ptr->hi();
  }
  std::cout << '\n';
}  // Destruktoren werden automatisch aufgerufen
