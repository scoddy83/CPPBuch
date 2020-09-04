/* cppbuch/loesungen/k4/5.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Die Funktion entspricht der Funktion strcpy() der
// C++-Standardbibliothek.
#include <cassert>
#include <cstring>
#include <iostream>

void strcopy(char* ziel, const char* quelle) {
  // kopiert den Inhalt von quelle in den String ziel (und
  // überschreibt den vorherigen Inhalt von ziel dabei).
  while ((*ziel++ = *quelle++))
    ;
}

int main() {
  const char* const original = "Alles Gute!";
  std::cout << original << '\n';
  char kopie[80];
  assert(sizeof kopie > strlen(original));
  strcopy(kopie, original);
  std::cout << kopie << '\n';
}
