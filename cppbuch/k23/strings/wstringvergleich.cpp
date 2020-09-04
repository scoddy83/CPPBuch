/* cppbuch/k23/strings/wstringvergleich.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "localeutils.t"
#include <iostream>
using namespace std;

int main() {
  locale::global(locale("de_DE.utf-8"));  // deDE global setzen
  Stringvergleich<wchar_t> sv;
  wstring s1(L"ähnlich");
  wstring s2(L"bildschön");
  if (sv(s1, s2)) {
    wcout << s1 << " kommt vor " << s2 << '\n';
  } else {
    wcout << s2 << " kommt vor " << s1 << '\n';
  }
}
