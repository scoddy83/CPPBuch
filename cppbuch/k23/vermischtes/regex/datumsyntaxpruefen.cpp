/* cppbuch/k23/vermischtes/regex/datumsyntaxpruefen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <regex>
#include <string>

bool datumok(const std::string& eingabe) {
  std::regex datumregex("\\d\\d?\\.\\d\\d?\\.\\d\\d\\d\\d");
  return std::regex_match(eingabe, datumregex);
}

using namespace std;

int main(int argc, char* argv[]) {
  if (2 != argc) {
    cout << "Gebrauch: datumsyntaxpruefen.exe \"Datum, z.B. "
            "tt.mm.jjjj\"\n";
  } else {
    try {
      if (datumok(argv[1])) {
        cout << argv[1] << " ist ein syntaktisch gültiges Datum.\n";
      } else {
        cout << argv[1] << " ist kein gültiges Datum.\n";
      }
    } catch (regex_error& re) {
      cerr << "Fehler: " << re.what() << '\n';
    }
  }
}
