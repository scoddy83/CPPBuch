/* cppbuch/k8/literale/intLiteral.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <stdexcept>

constexpr auto operator"" _b(const char* bits) {
  unsigned long long ergebnis = 0ull;
  auto anzahl = 0u;
  while (*bits) {
    if (*bits != '0' && *bits != '1') {
      throw std::runtime_error("unerlaubtes Zeichen im Bitstring");
    }
    ergebnis = (ergebnis << 1) + static_cast<unsigned long long>(*bits - '0');  // ASCII '0' wird 0 usw.
    ++bits;
    ++anzahl;
    if (anzahl > 8 * sizeof(unsigned long long)) {
      throw std::runtime_error("Bitstring zu lang");
    }
  }
  return ergebnis;
}

int main() {
  constexpr auto b = 1001_b;  // Suffix _b
  std::cout << b << '\n';     // 9 (dezimal)
}
