/* cppbuch/k23/vermischtes/clamp.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>


int main() {
  std::vector<int> werte { -300, 200, -50, -1, 0, 1, 50, 200, 300};
  std::cout << "Wert   -128 ..127   0..255\n";
  for(int w : werte) {
    std::cout << std::setw(4) << w << 
      std::setw(13) << std::clamp(w, -128, 127) << 
      std::setw(9) << std::clamp(w, 0, 255) << '\n';
  } 
}
