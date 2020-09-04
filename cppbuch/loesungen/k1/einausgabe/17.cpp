/* cppbuch/loesungen/k1/einausgabe/17.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
//  Datei-Statistik
#include <cstdlib>  // für exit()
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Dateiname :";
  string Quelldateiname;
  cin >> Quelldateiname;
  ifstream quelle(Quelldateiname);
  if (!quelle) {  // muss existieren
    cerr << Quelldateiname << " kann nicht geöffnet werden!\n";
    exit(-1);
  }

  char c = '\n';  // wegen der Abfrage in Zeile 38, falls die Datei
                  // leer ist
  unsigned long zeichenzahl = 0, wortzahl = 0, zeilenzahl = 0;
  bool istWort = false;

  while (quelle.get(c)) {
    if (c == '\n') {
      ++zeilenzahl;
    } else {
      ++zeichenzahl;
    }
    // Anpassung auf Umlaute fehlt!
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      istWort = true;  // Wortanfang, oder \tt{c} ist in einem Wort
    } else {
      if (istWort) {
        ++wortzahl;  // Wortende überschritten
      }
      istWort = false;
    }
  }
  if (c != '\n') {  // Die letzte Zeile enthält kein abschließendes \n.
    ++zeilenzahl;   // trotzdem mitzählen
  }
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
    // das letzte Zeichen ist in einem Wort, das noch nicht
    // mitgezählt wurde
    ++wortzahl;
  }
  cout << "Anzahl der Zeichen (ohne Zeilenendekennung) = " << zeichenzahl
       << '\n';
  cout << "Anzahl der Worte   = " << wortzahl << '\n';
  cout << "Anzahl der Zeilen  = " << zeilenzahl << '\n';
}
