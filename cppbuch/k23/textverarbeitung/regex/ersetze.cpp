/* cppbuch/k23/textverarbeitung/regex/ersetze.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>

namespace {

std::string ersetzeInDatei(const std::regex& gesucht,
                           const std::string& ersatz, const char* dateiname) {
  std::ifstream quelle(dateiname, std::ios::binary);
  if (!quelle.good()) {
    throw std::ios::failure("Dateifehler");
  }
  std::string alles;
  while (quelle.good()) {
    char c = static_cast<char>(quelle.get());
    if (!quelle.fail()) {
      alles += c;
    }
  }
  return std::regex_replace(alles, gesucht, ersatz);
}
}  // anonymer Namespace

using namespace std;

int main(int argc, char* argv[]) {
  const string gebrauch("Gebrauch: ersetze.exe [-i] \"regex\" \"ersatz\" "
                        "\"dateiname\"");
  auto syntaxoption = regex_constants::ECMAScript;  // Voreinstellung,
  // siehe auch unten \tt{icase}, falls  gefordert
  int start = 1;
  if (5 == argc) {  // Ist evtl. die Option -i gesetzt?
    string option = argv[1];
    if (option != "-i") {
      cerr << "Falsche Option: " << gebrauch << '\n';
      return 1;  // EXIT
    }
    ++start;
    syntaxoption |=
        regex_constants::icase;  // Klein-/Großschreibung ignorieren
  } else if (4 != argc) {
    cout << gebrauch << '\n';
    return 2;  // EXIT
  }
  // Datei durchsuchen
  try {
    regex gesucht(argv[start], syntaxoption);
    string ersatz(argv[start + 1]);
    string ergebnis = ersetzeInDatei(gesucht, ersatz, argv[start + 2]);
    cout << ergebnis;
  } catch (regex_error& re) {
    cerr << "Regex-Fehler: " << re.what() << '\n';
  } catch (ios::failure& e) {
    cerr << e.what() << '\n';
  }
}
