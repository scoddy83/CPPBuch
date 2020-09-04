/* cppbuch/k30/narrow.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <locale>
#include <string>
#include <type_traits>  // is_signed
using namespace std;

int main() {
  locale loc;
  cout << "loc.name()= " << loc.name() << '\n';
  locale dt("de_DE");
  cout << "dt.name()= " << dt.name() << '\n';
  locale vorher = locale::global(dt);  // dt für alles setzen

  string s("ÄÖÜäöüß");
  cout.imbue(dt);
  if (s.length() > 7) {
    cerr << "FEHLER: DIESES PROGRAMM IST NICHT in ISO 8859 "
            "gespeichert"
            " und wird nicht wie beabsichtigt funktionieren! "
            "Abbruch!\n";
    return 1;
  }
  cout << "\nProgramm funktioniert nur richtig bei auf ISO 8859"
          " eingestellter Konsole! \n";
  for (unsigned int i = 0; i < s.length(); ++i) {
    cout << "Zeichen " << i << ": " << s[i] << "   ";
    int intwert = static_cast<int>(s[i]);
    if (is_signed<char>::value) {  // ggf. Korrektur für signed char
      intwert += 256;
    }
    cout << intwert << '\n';
  }
  for (auto c : s) {
    cout << toupper(c, dt) << tolower(c, dt) << " ";
  }
  for (auto& c : s) {
    c = toupper(c, dt);
  }
  cout << "\nNach toupper: " << s << '\n';
  // Andere Möglichkeit, jetzt mit tolower:
  use_facet<ctype<char>>(dt).tolower(&s[0], s.c_str() + s.length());
  cout << "Nach tolower: " << s << '\n';
}

/*
ISO 8859-1: Bits 0-127 wie ASCII
reicht für sehr viele Sprachen aus, hat aber kein Euro- Symbol
Ae  196 0xC4
Oe  214 0xD6
Ue  220 0xDC
ae  228 0xE4
oe  246 0xF6
ue  252 0xFC
sz  223 0xDF
Euro ist 164 0xA4 bei ISO 8859-15

*/
