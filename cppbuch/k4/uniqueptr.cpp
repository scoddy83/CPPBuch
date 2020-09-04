/* cppbuch/k4/uniqueptr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <memory>
#include <vector>
#include <ort.h>

void f(const std::unique_ptr<Ort>&  up) {       // per Referenz!
  std::cout << "f() aufgerufen: "
            << up->getX() << ' ' << up->getY() << '\n';
}

int main() {
  { // neuer Block
    auto uptr = std::make_unique<Ort>(1, 2);
    // Benutzung wie Zeiger
    std::cout << "(x, y) = " << uptr->getX() << ' ' << uptr->getY() << '\n';
    // Benutzung wie Referenz
    std::cout << "(x, y) = " << (*uptr).getX() << ' ' << (*uptr).getY() << '\n';
    // Kopie des Orts, nicht des Zeigers
    Ort einOrt = *uptr;
    std::cout << "x = " << einOrt.getX() << '\n';
  } // Blockende. Automatischer Destruktoraufruf!

  // Vektor 
  std::vector<std::unique_ptr<Ort>> vec(2); // 2 Elemente
  vec[0] = std::make_unique<Ort>(3, 4);     // initialisieren
  vec[1] = std::make_unique<Ort>(5, 6);     // initialisieren
  vec.push_back(std::make_unique<Ort>(7, 8));  // jetzt 3 Elemente
  // Alle anzeigen:
  for(const auto& ortptr : vec) {   // Referenz!
    std::cout << ortptr->getX() << ' ' << ortptr->getY() << '\n';
  }
  f(vec[2]); // oben definierte Funktion f() aufrufen
}

