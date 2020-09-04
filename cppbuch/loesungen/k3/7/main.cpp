/* cppbuch/loesungen/k3/7/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
/** @file
* main()-Datei fuer ein Taschenrechner-Programm.
* Beispiel fuer die Nutzung der Taschenrechner-Klasse.
* @author    U. Breymann
* $Revision: 1.2 $
* @date      12.9.2014
*/
#include "taschenrechner.h"
#include <iostream>

using namespace std;
/** main()-Funktion.
* Parameter werden nicht benoetigt.
* main() erwartet nach dem Start eine Eingabe, mit der
* ein Taschenrechnerobjekt initialisiert wird.
*/
int main() {
  while (true) {  // Abbruch mit break
    cout << "\nBitte einen mathematischen Ausdruck eingeben, "
            "z.B. 4*(12+3)\n(Abbruch durch Eingabe einer Leerzeile) "
            ": ";
    string anfrage;
    getline(cin, anfrage);
    if (anfrage.length() > 0) {
      Taschenrechner tr(anfrage);
      cout << "Das Ergebnis der Anfrage '" << tr.getAnfrage() << "' ist "
           << tr.getErgebnis() << '\n';
    } else
      break;
  }
}
