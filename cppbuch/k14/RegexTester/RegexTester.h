/* cppbuch/k14/RegexTester/RegexTester.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef REGEX_TESTER
#define REGEX_TESTER
#include <regex>
#include <string>

class RegexTester {
public:
  RegexTester(const std::string& regEx, const std::string& teststr);
  void run();

private:
  std::regex rgx;
  std::string rgxstring;
  std::string teststring;
};
#endif
