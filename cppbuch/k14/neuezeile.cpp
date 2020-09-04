/* cppbuch/k14/neuezeile.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <regex>
#include <string>

int main(int argc, char* argv[]) {
  std::string teststring("Jetzt kommt eine\nneue Zeile.\n");
  std::cout << "Teststring: " << teststring;
  std::regex gesucht("(\n)");
  std::string ersatz("\n\n");
  if (argc > 1) {      // Aufruf mit Argument(en)
    ersatz = argv[1];  // 1. Argument
  }
  std::string ergebnis = std::regex_replace(teststring, gesucht, ersatz);
  std::cout << "Ergebnis: " << ergebnis;
}
