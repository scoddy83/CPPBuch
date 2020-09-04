/* cppbuch/k23/vermischtes/regex/IPv4adressepruefen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../../strings/split.h"
#include <cstddef>
#include <iostream>
#include <regex>

bool ip4ok(const std::string& eingabe) {
  std::regex datumregex("(?:\\d\\d?\\d?\\.){3}\\d\\d?\\d?");
  bool ergebnis = std::regex_match(eingabe, datumregex);
  if (ergebnis) {  // Syntax ok, Inhalt prüfen
    std::vector<std::string> v = split(eingabe, ".");
    for (std::size_t i = 0; i < v.size(); ++i) {
      ergebnis = ergebnis && std::stoi(v[i]) < 256;
    }
  }
  return ergebnis;
}

using namespace std;

int main(int argc, char* argv[]) {
  if (2 != argc) {
    cout << "Gebrauch: " << argv[0] << " \"IP-Adresse, z.B. 127.0.0.1\"\n";
  } else {
    try {
      if (ip4ok(argv[1])) {
        cout << argv[1] << " ist eine gültige IP-Adresse.\n";
      } else {
        cout << argv[1] << " ist keine gültige IP-Adresse.\n";
      }
    } catch (regex_error& re) {
      cerr << "Fehler: " << re.what() << '\n';
    }
  }
}
