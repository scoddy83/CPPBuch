/* cppbuch/loesungen/k4/7alternativ.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>  // enthält sort()
#include <cstring>
#include <iostream>
#include <string>
// Alternative Lösung mit der Standardfunktion std::sort():

// Vergleichsfunktion für C-String-Array-Elemente
bool scmp(const char* a, const char* b) { return strcmp(a, b) < 0; }

int main() {
  const char* sfeld[] = {"eins",  "zwei",   "drei", "vier", "fünf",
                         "sechs", "sieben", "acht", "neun", "zehn"};
  unsigned int anzahlElemente = sizeof(sfeld) / sizeof(sfeld[0]);
  std::sort(sfeld, sfeld + anzahlElemente, scmp);
  // ALPHABETISCHE Ausgabe des sortierten Feldes:
  for (const auto& str : sfeld) {
    std::cout << ' ' << str;
  }
  std::cout << '\n';

  // Entsprechend für C++-Strings
  std::string strings[] = {"eins",  "zwei",   "drei", "vier", "fünf",
                           "sechs", "sieben", "acht", "neun", "zehn"};
  unsigned int anzahl = sizeof(strings) / sizeof(strings[0]);
  // bei C++-Strings ist keine Vergleichsfunktion notwendig
  std::sort(strings, strings + anzahl);
  // ALPHABETISCHE Ausgabe des sortierten Feldes:
  for (const auto& str : strings) {
    std::cout << ' ' << str;
  }
  std::cout << '\n';
}
