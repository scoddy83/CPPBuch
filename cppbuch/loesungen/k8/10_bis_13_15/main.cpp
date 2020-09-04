/* cppbuch/loesungen/k8/10_bis_13_15/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "grossesSystemdatum.h"
#include <datum.h>
using namespace std;

int main() {
  Datum einDatum;
  cout << einDatum << '\n';
  ++einDatum;
  cout << einDatum << '\n';

  Datum irgendwann = maxDatumFuerAufgabe();  // maximales Systemdatum
                                             // lt. Aufgabe ermitteln
  cout << "Auf diesem System ist das maximale Datum entspr. der "
          "Aufgabe der ";
  cout << irgendwann << ".\n";
  Datum heute;
  cout << "Bis dahin sind es noch " << datumDifferenz(heute, irgendwann)
       << " Tage.\n";

  Datum zweitausend(1, 1, 2000);
  int diff = datumDifferenz(heute, zweitausend);
  if (diff > 0)
    cout << "Bis zum " << zweitausend << " sind es noch " << diff
         << " Tage.\n";
  else
    cout << "Seit dem " << zweitausend << " vergingen " << -diff
         << " Tage.\n";
}
