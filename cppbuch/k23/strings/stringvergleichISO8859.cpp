/* cppbuch/k23/strings/stringvergleichISO8859.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "localeutils.t"
#include <iostream>
using namespace std;

int main() {
  locale loc("de_DE");
  Stringvergleich<char> stringvergleich(loc);
  string s1("ähnlich");
  string s2("bildschön");
  cout.imbue(loc);
  if (stringvergleich(s1, s2)) {
    cout << s1 << " kommt vor " << s2 << '\n';
  } else {
    cout << s2 << " kommt vor " << s1 << '\n';
  }
}
