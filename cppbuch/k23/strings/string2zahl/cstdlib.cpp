/* cppbuch/k23/strings/string2zahl/cstdlib.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// C-String mit C-Funktionen in Zahl wandeln
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  cout << "Bitte Zeichenkette eingeben (z.B. 3.14 12345 0x78 FF "
          "0123): ";
  char eingabe[80]{};
  cin.get(eingabe, sizeof(eingabe));  // liest max. sizeof(eingabe)-1 Zeichen
  char* rest;
  int modus[]{-1, 0, 2, 8, 10, 16};
  string modusText[]{"double",      "Standard (0 okt/0x hex/dez)",
                     "Binärzahl",   "Oktalzahl",
                     "Dezimalzahl", "Hexadezimalzahl"};
  for (unsigned int i = 0; i < sizeof(modus) / sizeof(modus[0]); ++i) {
    cout << "Interpretation als " << modusText[i] << ": ";
    if (-1 == modus[i]) {  // double
      cout << strtod(eingabe, &rest);
    } else {  // long
      cout << strtol(eingabe, &rest, modus[i]);
    }
    if (*rest) {
      cout << " nicht ausgewertet:" << rest;
    }
    cout << '\n';
  }
}
