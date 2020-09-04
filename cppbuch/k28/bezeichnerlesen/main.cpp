/* cppbuch/k28/bezeichnerlesen/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "identifier.h"
#include <fstream>
#include <iterator>

int main() {
  std::ifstream datei("main.cpp");  // Eingabedatei öffnen
  std::istream_iterator<Identifier> iter(datei);
  std::istream_iterator<Identifier> end;
  while (iter != end) {
    std::cout << *iter++ << '\n';  // lesen, ausgeben und weiterschalten
  }
}
