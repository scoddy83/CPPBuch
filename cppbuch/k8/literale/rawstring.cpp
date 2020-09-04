/* cppbuch/k8/literale/rawstring.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cassert>
#include <string>

int main() {
  std::string anfuehrungszeichen{"\"\"\"\"\"\""};
  std::string rawanfuehrungszeichen{R"("""""")"};
  assert(anfuehrungszeichen == rawanfuehrungszeichen);

  std::string regex{"/\\*.*?\\*/"};
  std::string rawregex1{R"(/\*.*?\*/)"};
  assert(regex == rawregex1);

  std::string regexMitKlammern{"^\\D+([0-9]+) \\1"};
  std::string rawregexMitKlammern{R"=(^\D+([0-9]+) \1)="};
  assert(regexMitKlammern == rawregexMitKlammern);

  // Ein raw string kann über Zeilen gehen:
  std::string zeilen{"text\n\nneueZeile"};
  std::string rawzeilen{R"(text

neueZeile)"};
  assert(zeilen == rawzeilen);

  // Kombination mit U
  std::u32string u{U"\"UTF-32\""};
  std::u32string rawu{UR"("UTF-32")"};
  assert(u == rawu);
}
