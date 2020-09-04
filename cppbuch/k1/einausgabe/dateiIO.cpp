/* cppbuch/k1/einausgabe/dateiIO.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string dateiname;
  cout << "Dateiname? ";
  cin >> dateiname;  // darf wegen \tt{cin} keine Leerzeichen enthalten!
  // Datei schreiben
  ofstream datei(dateiname);  // Objekt für Ausgabestrom
  if (!datei.good()) {        // Fehlerabfrage
    cerr << dateiname << " kann nicht beschrieben werden!\n";
  } else {
    datei << "geschriebener Text.\nZweite Zeile!\n";
    datei.close();  // Schließen der Datei, damit sie gelesen werden
                    // kann
  }
  // Lesen derselben Datei und Anzeige der Zeilen
  ifstream quelle(dateiname);  // Objekt für Eingabestrom
  cout << "Der Inhalt von " << dateiname << " ist:\n";
  while (quelle.good()) {
    string zeile;
    getline(quelle, zeile);  // Zeile lesen
    cout << zeile << '\n';
  }
}  // Datei wird am Programmende automatisch geschlossen.
