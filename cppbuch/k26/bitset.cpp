/* cppbuch/k26/bitset.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <bitset>
#include <iostream>

int main() {
  std::bitset<17> einBitset;
  einBitset.set();      // alles 1
  einBitset[4].flip();  // Bit 4 wird 0
  std::cout << einBitset << '\n';
  einBitset >>= 4;  // Rechtsverschiebung um 4 Positionen
  std::cout << einBitset << '\n';
}
