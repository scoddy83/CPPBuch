/* cppbuch/k32/vektorUniquePtr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Beispiel: Vektor mit unique_ptr
#include "Ressource.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<std::unique_ptr<Ressource>> vpu(10);
  // Initialisierung aller Elemente:
  for (std::size_t i = 0; i < vpu.size(); ++i) {
    vpu[i] = std::make_unique<Ressource>(i);
    // statt vpu[i] = std::unique_ptr<Ressource>(new Ressource(i));
  }
  // Benutzung:
  std::cout << "Werte:\n";
  for (const auto& ptr : vpu) {  // Referenz, weil Kopie nicht erlaubt ist
    ptr->hi();
  }
  std::cout << '\n';
}  // Destruktoren werden automatisch aufgerufen
