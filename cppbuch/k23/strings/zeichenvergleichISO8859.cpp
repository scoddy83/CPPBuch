/* cppbuch/k23/strings/zeichenvergleichISO8859.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "localeutils.t"
#include <cstddef>
#include <iostream>
using namespace std;

int main() {
  locale::global(locale("de_DE"));  // deDE global setzen
  string s1("ähnlich_x");           // 1-char-Zeichen, hier ISO8859-1 codiert
  string s2("ÄHNLICH_Y");
  for (size_t i = 0; i < s1.length() && i < s2.length(); ++i) {
    cout << "Die Zeichen Nr. " << i << " (" << s1[i] << ", " << s2[i]
         << ") werden als ";
    if (!equalIgnoreCase(s1[i], s2[i])) {
      cout << "un";
    }
    cout << "gleich gewertet.\n";
  }
}
