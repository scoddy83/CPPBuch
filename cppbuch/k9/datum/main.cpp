/* cppbuch/k9/datum/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "datumeingabeoperator.h"

using namespace std;

int main() {
  Datum einDatum;
  try {
    cout << "Bitte Datum eingeben: ";
    cin >> einDatum;
    cout << "Eingegeben wurde der " << einDatum << ".\n";
  } catch (const char* e) {
    cerr << e << " Abbruch!" << '\n';
  }
}
