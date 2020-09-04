/* cppbuch/k23/textverarbeitung/regex/finde.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  regex_constants::syntax_option_type syntaxoption =
      regex_constants::ECMAScript;
  string gebrauch("Gebrauch: finde.exe [-i] \"regex\" \"dateiname\"");
  string option;
  int start{1};
  // Ist die Option -i gesetzt?
  if (4 == argc) {
    option = argv[1];
    if (option != "-i") {
      cerr << "Falsche Option: " << gebrauch << '\n';
      return 1;  // EXIT
    }
    ++start;
    syntaxoption |= regex::icase;  // Klein-/Großschreibung ignorieren
  } else if (3 != argc) {
    cout << gebrauch << '\n';
    return 2;  // EXIT
  }
  // Datei durchsuchen
  try {
    // \tt{syntaxoption} transportiert die Einstellungen egrep und
    // icase
    regex gesucht(argv[start], syntaxoption);
    ifstream quelle(argv[start + 1]);
    if (!quelle.good()) {
      throw ios::failure("Dateifehler");
    }
    unsigned int zeilennr{0};
    cout << "regex= : " << argv[start] << '\n';
    while (quelle.good()) {
      string zeile;
      getline(quelle, zeile);
      ++zeilennr;
      if (regex_search(zeile, gesucht)) {
        cout << zeilennr << ": " << zeile << '\n';
      }
    }
  } catch (regex_error& re) {
    cerr << "Regex-Fehler: " << re.what() << '\n';
  } catch (ios::failure& e) {
    cerr << e.what() << '\n';
  }
}
