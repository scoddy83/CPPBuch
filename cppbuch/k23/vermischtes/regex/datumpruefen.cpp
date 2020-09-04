/* cppbuch/k23/vermischtes/regex/datumpruefen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../../strings/split.h"
#include <algorithm>
#include <iostream>
#include <regex>

inline bool istSchaltjahr(unsigned int jahr) {
  return (jahr % 4 == 0 && jahr % 100) || jahr % 400 == 0;
}

bool istGueltigesDatum(unsigned int t, unsigned int m, unsigned int j) {
  // Tage pro Monat(static vermeidet Neuinitialisierung):
  static unsigned int tmp[] = {31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
  unsigned int letzterTagImMonat = tmp[m - 1];
  if (m == 2 && istSchaltjahr(j)) {
    letzterTagImMonat = 29;
  }
  return (m >= 1 && m <= 12 && j >= 1583 && j <= 2399  // oder mehr
          && t >= 1 && t <= letzterTagImMonat);
}

bool datumok(const std::string& eingabe) {
  std::regex datumregex("\\d\\d?\\.\\d\\d?\\.\\d\\d\\d\\d");
  bool ergebnis = std::regex_match(eingabe, datumregex);
  if (ergebnis) {  // Syntax ok, Inhalt prüfen
    std::vector<std::string> v = split(eingabe, ".");
    ergebnis =
        istGueltigesDatum(std::stoi(v[0]), std::stoi(v[1]), std::stoi(v[2]));
  }
  return ergebnis;
}

using namespace std;

int main(int argc, char* argv[]) {
  if (2 != argc) {
    cout << "Gebrauch: " << argv[0] << " \"Datumstring, z.B. tt.mm.jjjj\"\n";
  } else {
    try {
      if (datumok(argv[1])) {
        cout << argv[1] << " ist ein gültiges Datum.\n";
      } else {
        cout << argv[1] << " ist kein gültiges Datum.\n";
      }
    } catch (regex_error& re) {
      cerr << "Fehler: " << re.what() << '\n';
    }
  }
}
