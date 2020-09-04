/* cppbuch/k30/datum/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "datumlocale.h"
using namespace std;

int main() {
  Datum einDatum;
  einDatum.set(1, 10, 1970);
  locale deDE("de_DE");
  cout << " bitte Datum im Format tt.mm.yyyy eingeben:\n";
  cin.imbue(deDE);
  cin >> einDatum;
  cout.imbue(deDE);
  cout << "deutsches Format :" << einDatum << '\n';
  locale enUS("en_US");
  cout.imbue(enUS);
  cout << "US Format        :" << einDatum << '\n';
  cout << "toString() mit Standard-Locale deDE:" << einDatum.toString()
       << '\n';
  cout << "toString() mit Locale enUS         :" << einDatum.toString(enUS)
       << '\n';
}
