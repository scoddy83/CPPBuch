/* cppbuch/k5/stringansicht/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "stringansicht.h"
using namespace std;

int main() {
  StringAnsicht leereStringAnsicht;
  cout << "leere StringAnsicht. Länge = " << leereStringAnsicht.length()
       << '\n';

  StringAnsicht eineStringAnsicht("Hallo");
  cout << "Hallo: Länge = " << eineStringAnsicht.length() << '\n';
  anzeigen(cout, eineStringAnsicht);
  cout << "\nzeichenweise Ausgabe:\n";
  for (size_t i = 0; i < eineStringAnsicht.length(); ++i) {
    cout << '*' << eineStringAnsicht.at(i);
  }
  cout << "*\n";
  for (auto c : eineStringAnsicht) {
    cout << '_' << c;
  }
  cout << "_\n";
  // Zuweisen
  StringAnsicht zweiteStringAnsicht;
  zweiteStringAnsicht = eineStringAnsicht;
  cout << "zugewiesene StringAnsicht: ";
  anzeigen(cout, zweiteStringAnsicht);
  cout << '\n';
}
