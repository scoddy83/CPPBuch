/* cppbuch/k1/einausgabe/datcopy.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstdlib>  // für exit( )
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string dateiname;
  cout << "Quelldatei? ";
  cin >> dateiname;
  ifstream quelle(dateiname, ios::binary);  // Objekt für die Eingangsdatei
  // Zu \tt{ios::binary} siehe Text
  if (!quelle.good()) {  // Fehlerabfrage
    cerr << dateiname << " kann nicht geöffnet werden!\n";
    exit(-1);
  }

  cout << "Zieldatei? ";
  cin >> dateiname;
  // Definieren und Öffnen der Ausgabedatei
  ofstream ziel(dateiname, ios::binary);
  if (!ziel.good()) {  // Fehlerabfrage
    cerr << dateiname << " kann nicht geöffnet werden!\n";
    exit(-1);
  }

  char ch;
  while (quelle.get(ch)) {
    ziel.put(ch);  // zeichenweise kopieren
  }
}  // Dateien werden am Programmende automatisch geschlossen.
