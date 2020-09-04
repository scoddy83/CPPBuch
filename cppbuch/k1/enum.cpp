/* cppbuch/k1/enum.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

enum class Farbtyp :int { rot, gelb, gruen };
enum class RGB { rot = 'R', gruen = 'G', blau = 'B'};

int main() {
  Farbtyp farbe = Farbtyp::gelb;
  std::cout << "Farbtyp::gelb = " << static_cast<int>(farbe) << '\n';
  std::cout << "RGB::gruen = " << static_cast<char>(RGB::gruen) << '\n'; // G
  // verschiedene Initialisierungsmöglichkeiten
  RGB rgb1 {RGB::blau};                // richtig!
  std::cout << "rgb1 = " << static_cast<char>(rgb1) << '\n'; // B
  RGB rgb2 {'G'};                      // nicht empfohlen!
  // Grund: RGB rgb2 {'X'}; ist auch möglich OHNE Warnung durch den Compiler
  std::cout << "rgb2 = " << static_cast<char>(rgb2) << '\n'; // G
}
