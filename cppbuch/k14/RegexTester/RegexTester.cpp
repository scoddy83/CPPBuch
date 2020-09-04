/* cppbuch/k14/RegexTester/RegexTester.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "RegexTester.h"
#include <iostream>

RegexTester::RegexTester(const std::string& regEx, const std::string& teststr)
    : rgx{regEx}, rgxstring{regEx}, teststring{teststr} {}

void RegexTester::run() {
  std::sregex_iterator erster(teststring.begin(), teststring.end(), rgx);
  std::sregex_iterator letzter;
  std::cout << "Regex: " << rgxstring << "  Teststring: " << teststring
            << '\n';
  if (erster == letzter) {
    std::cout << "nichts gefunden\n";
  } else {
    while (erster != letzter) {
      auto ergebnis = *erster++;  // gut, dass es \tt{auto} gibt...
      // \tt{auto} = \tt{std::match\_results<std::string::const\_iterator>}
      for (unsigned int i = 0; i < ergebnis.size(); ++i) {
        if (i > 0) {
          std::cout << "Capturing Group " << i << ": ";
        }
        std::cout << "\"" << ergebnis.str(i) << "\" gefunden. Position "
                  << ergebnis.position(i);
        if (ergebnis.length(i) > 1) {
          std::cout << " bis "
                    << ergebnis.position(i) + ergebnis.length(i) - 1;
        }
        std::cout << '\n';
      }
    }
  }
}
