/* cppbuch/loesungen/k5/1/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "meinstring.h"
#include <iostream>
using namespace std;

int main() {
  MeinString a("Guten ");
  MeinString b("Tag");
  cout << "Test von insert()\nPos:\n";
  for (size_t i = 0; i < b.length() + 2; ++i) {
    MeinString c(b);
    cout << i << "   ";
    anzeigen(cout, c);
    cout << " wird: ";
    c.insert(i, a);
    anzeigen(cout, c);
    if (i > b.length()) {
      cout << "  Begrenzung";
    }
    cout << '\n';
  }
}
