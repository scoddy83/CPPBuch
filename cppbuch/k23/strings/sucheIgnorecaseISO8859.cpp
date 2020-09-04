/* cppbuch/k23/strings/sucheIgnorecaseISO8859.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "localeutils.t"
#include <iostream>

using namespace std;

int main() {
  locale::global(locale("de_DE"));  // deDE global setzen
  string text("Quer über den großen Sylter Deich");
  string suchstring("Über");
  auto pos = findeSuchstringIgnoreCase(text, suchstring);
  if (pos != string::npos) {
    cout << suchstring << " ist ab Position " << pos << " in " << text
         << " enthalten (Groß-/Kleinschreibung ignoriert).\n";
  } else {
    cout << suchstring << " ist nicht in " << text << " enthalten.\n";
  }
}
