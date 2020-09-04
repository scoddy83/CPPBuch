/* cppbuch/k23/strings/richtigsortierenwchar.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Diese Datei ist UTF-8 codiert
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void printWstringVector(const std::vector<std::wstring>& v) {
  for(const auto& ws : v) {
    std::wcout << ws << ' ';
  }
  std::wcout << '\n';
}

using namespace std;

int main() {
  locale::global(locale("de_DE.utf-8"));  // deDE global setzen
  vector<wstring> v;
  v.push_back(L"Maße");
  v.push_back(L"Masse");
  v.push_back(L"Ähnlich");
  v.push_back(L"Alphabet");
  v.push_back(L"aal");
  v.push_back(L"ähnlich");
  v.push_back(L"alphabet");
  v.push_back(L"Aal");
  wcout << "vorher:\n";
  printWstringVector(v);
  sort(v.begin(), v.end());
  wcout << "nach Sortieren ohne Compare-Objekt:\n";
  printWstringVector(v);
  locale deutsch("de_DE.utf-8");
  sort(v.begin(), v.end(), deutsch);
  wcout << "nach Sortieren (locale de_DE):\n";
  printWstringVector(v);
}
