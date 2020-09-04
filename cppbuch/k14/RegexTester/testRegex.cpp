/* cppbuch/k14/RegexTester/testRegex.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "RegexTester.h"
#include <iostream>

void testfaelle() {
  const std::string testfaelle[][2] = {
      {"^\\D+([0-9]+) \\1", "Sommer 2018 2018"},
      {"[a-c]+", "zcbaaxcadey"},
      {"\\t", "enthält	Tabulator"},  // \Tab = Tabulator
      {"[a-c]*", "z"},                // greedy
      {"[^aeiou]+", "hallo"},
      {"/\\*.*\\*/", "xyz /* hallo */ abc */ 123"},  // greedy
      {"/\\*.*?\\*/", "xyz /* hallo */ abc */ 123"}  // nicht greedy
  };
  for (auto testfall : testfaelle) {
    RegexTester rt(testfall[0], testfall[1]);
    rt.run();
    std::cout << '\n';
  }
}

int main(int argc, char* argv[]) {
  if (3 != argc) {
    testfaelle();
    std::cout << "Gebrauch: testRegex.exe \"regex\" \"teststring\"\n"
                 "ansonsten werden eingebaute Testfälle ausgegeben.\n";
  } else {
    try {
      RegexTester rt(argv[1], argv[2]);
      rt.run();
    } catch (std::regex_error& re) {
      std::cerr << "Fehler: " << re.what() << '\n';
    }
  }
}
