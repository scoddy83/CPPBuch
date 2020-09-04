/* cppbuch/k23/textverarbeitung/regex/loc.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

unsigned int zaehleLOC(const char* dateiname) {
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
  // Zeilenendekennung vereinheitlichen
  alles = std::regex_replace(alles, std::regex("(\r\n)"), "\n");
  // Leer- und Tabulatorzeichen entfernen
  alles = std::regex_replace(alles, std::regex("( |\t)"), "");
  // Escape-Zeichen loeschen
  alles = std::regex_replace(alles, std::regex("\\\\."), "");
  // Alle Strings durch "" nicht-greedy ersetzen
  alles = std::regex_replace(alles, std::regex("\".*?\""), "\"\"");
  // alle // Kommentare loeschen
  alles = std::regex_replace(alles, std::regex("//[^\n]*"), "");
  /* So  beginnende Kommentare zeilenübergreifend löschen.
     Im folgenden regulären Ausdruck bedeutet das erste ?, dass
     der Inhalt der Capturing Group nicht gespeichert werden
     muss. Das zweite ? bedeutet 'nicht-greedy'. Ohne das würde bis
     zum Ende des letzten zeilenübergreifenden Kommentars gelöscht
     werden.
  */
  alles = std::regex_replace(alles, std::regex("/\\*(?:.|\n)*?\\*/"), "");
  // Leerzeilen entfernen
  alles = std::regex_replace(alles, std::regex("(\\n)+"), "$1");
  // Anzahl der Zeilen zurückgeben
  return 1 + std::count(alles.begin(), alles.end(), '\n');
}

int main(int argc, char* argv[]) {
  std::string gebrauch("Gebrauch: loc.exe dateiname");
  if (2 != argc) {
    std::cout << gebrauch << '\n';
    return 1;  // EXIT
  }
  // Datei analysieren
  try {
    std::cout << "Die Datei " << argv[1] << " hat " << zaehleLOC(argv[1])
              << " Lines of Code (LOC).\n";
  } catch (std::regex_error& re) {
    std::cerr << "Regex-Fehler: " << re.what() << '\n';
  } catch (std::ios::failure& e) {
    std::cerr << e.what() << '\n';
  }
}
