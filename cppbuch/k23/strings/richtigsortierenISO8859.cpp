/* cppbuch/k23/strings/richtigsortierenISO8859.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<string> v;
  v.push_back("Maße");
  v.push_back("Masse");
  v.push_back("Ähnlich");
  v.push_back("Alphabet");
  v.push_back("aal");
  v.push_back("ähnlich");
  v.push_back("alphabet");
  v.push_back("Aal");
  cout << "vorher:";
  showContainer(v);
  sort(v.begin(), v.end());
  cout << "nach Sortieren ohne Compare-Objekt:\n";
  showContainer(v);
  locale deutsch("de_DE");
  sort(v.begin(), v.end(), deutsch);
  cout << "nach Sortieren (locale de_DE):\n";
  showContainer(v);
}
