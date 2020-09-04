/* cppbuch/k23/strings/richtigsortierenu8.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Diese Datei ist UTF-8 codiert
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <showContainer.h>
using namespace std;

int main() {
  locale::global(locale("de_DE.utf-8"));  // deDE global setzen
  vector<string> v;
  v.push_back(u8"Maße");
  v.push_back(u8"Masse");
  v.push_back(u8"Ähnlich");
  v.push_back(u8"Alphabet");
  v.push_back(u8"aal");
  v.push_back(u8"ähnlich");
  v.push_back(u8"alphabet");
  v.push_back(u8"Aal");
  cout << "\nvorher:\n";
  showContainer(v);
  sort(v.begin(), v.end());
  cout << "nach Sortieren ohne Compare-Objekt:\n";
  showContainer(v);
  locale deutsch("de_DE.utf-8");
  sort(v.begin(), v.end(), deutsch);
  cout << "nach Sortieren (locale de_DE.utf-8):\n";
  showContainer(v);
}
