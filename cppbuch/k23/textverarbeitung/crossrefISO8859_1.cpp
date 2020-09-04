/* cppbuch/k23/textverarbeitung/crossrefISO8859_1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cctype>
#include <fstream>
#include <iostream>
#include <locale>
#include <map>
#include <set>
#include <showContainer.h>
#include <string>
// Test für Locale de_DE: Mucke Mücke Maße Masse

/* Diese Datei ist im ISO 8859-1 Format abgespeichert, sodass
Umlaute nur einem Byte entsprechen.
Konvertierung nach UTF-8 bewirkt, dass der obige Test fehlschlägt!
Zur korrekten Darstellung muss das Terminal auch auf ISO 8859-1
eingestellt sein.
*/
// Um eine unterschiedliche Sortierung für Groß- und Kleinschreibung
// zu vermeiden, wird die Klasse \tt{Vergleich} eingesetzt, die die
// zu
// vergleichenden Strings vorher auf Kleinschreibung normiert.

struct Vergleich {
  bool operator()(std::string a, std::string b) const {  // per Wert
    for (auto& c : a) {
      c = std::tolower(c);
    }
    for (auto& c : b) {
      c = std::tolower(c);
    }
    return a < b;  // Stringvergleich berücksichtigt Locale
  }
};

using namespace std;
int main(int argc, char* argv[]) {
  if (argc == 1) {
    cout << "Gebrauch: " << argv[0] << " Dateiname [locale]\n"
                                       " Beispiele (vorgegebene Locale: C)\n"
         << argv[0] << " datei de_DE\n"
         << argv[0] << " datei\n";
    return 0;
  }
  ifstream quelle(argv[1]);
  if (!quelle.good()) {
    cout << argv[1] << " nicht gefunden!\n";
    return 1;
  }

  if (argc == 3) {
    locale::global(locale(argv[2]));  // ggf. global setzen
  }

  map<string, set<size_t>, Vergleich> bezeichnerZeilenMap;

  size_t zeilennr{1};
  while (quelle.good()) {
    char c{'\0'};
    // Anfang des Bezeichners finden
    while (quelle.good() && !(isalpha(c) || '_' == c)) {
      quelle.get(c);
      if (c == '\n') {
        ++zeilennr;
      }
    }
    if (quelle.good()) {
      string bezeichner(1, c);
      // Rest des Bezeichners einsammeln
      while (quelle.good() && (isalnum(c) || '_' == c)) {
        quelle.get(c);
        if (isalnum(c) || '_' == c)
          bezeichner += c;
      }
      quelle.putback(c);  // zurück an den Eingabestrom
      if (c) {            // Bezeichner gefunden?
        bezeichnerZeilenMap[bezeichner].insert(zeilennr);  // Eintrag
      }
    }
  }

  for (const auto& mapEintrag : bezeichnerZeilenMap) {
    cout << mapEintrag.first;                    // Bezeichner
    cout.width(20 - mapEintrag.first.length());  // Position bis : einstellen
    cout << ": ";
    showContainer(mapEintrag.second);  // Zeilennummern
  }
}
