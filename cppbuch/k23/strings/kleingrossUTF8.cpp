/* cppbuch/k23/strings/kleingrossUTF8.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "localeutils.t"
#include <iostream>
using namespace std;
// ACHTUNG: nur wcout verwenden!
// Bei GNU C++  ändert die Benutzung von cout die internen
// Einstellungen für wcout

int main() {
  locale::global(locale("de_DE.utf-8"));  // deDE global setzen
  wstring text(L"Falsches Üben von Xylophonmusik quält jeden "
               L"größeren Zwerg.");
  wcout << "anfangs:" << text << '\n';
  gross(text);
  wcout << "gross: " << text << '\n';
  klein(text);
  wcout << "klein: " << text << '\n';
}
