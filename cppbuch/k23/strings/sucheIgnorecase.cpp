/* cppbuch/k23/strings/sucheIgnorecase.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "localeutils.t"
#include <iostream>

using namespace std;

int main() {
  locale::global(locale("de_DE.utf-8"));  // deDE global setzen
  wstring text(L"Quer über den großen Sylter Deich");
  wstring suchstring(L"Über");
  auto pos = findeSuchstringIgnoreCase(text, suchstring);
  if (pos != wstring::npos) {
    wcout << suchstring << " ist ab Position " << pos << " in " << text
          << L" enthalten (Groß-/Kleinschreibung ignoriert).\n";
  } else {
    wcout << suchstring << " ist nicht in " << text << " enthalten.\n";
  }
}
