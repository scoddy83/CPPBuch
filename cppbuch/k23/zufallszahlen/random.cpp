/* cppbuch/k23/zufallszahlen/random.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(time(NULL));  // damit bei jedem Programmstart andere
                           // Zufallszahlen ausgegeben werden
  for (unsigned int i = 0; i < 5; ++i) {
    // rand() ist "deprecated" (d.h. wird nicht empfohlen)
    std::cout << std::rand() << '\n';
  }
}
