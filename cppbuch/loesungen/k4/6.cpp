/* cppbuch/loesungen/k4/6.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Die Funktion entspricht der Funktion strdup() der
// C++-Standardbibliothek.
#include <cstring>
#include <iostream>

char* strduplikat(const char* s) {
  // liefert einen Zeiger auf den neu erzeugten String.
  // ACHTUNG: Der Aufrufer ist für das delete [] verantwortlich!
  char* neu = new char[strlen(s) + 1];
  std::strcpy(neu, s);  // wie strcopy() aus Aufgabe 5
  return neu;
}

int main() {
  const char* const original = "Alles Gute!";
  std::cout << original << '\n';
  char* kopie = strduplikat(original);
  std::cout << kopie << '\n';
  delete[] kopie;  // nicht vergessen
}
