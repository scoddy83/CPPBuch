/* cppbuch/k9/fstream2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <fstream>
#include <iostream>

using namespace std;

// Lesen und Schreiben auf *einer* Datei

int main() {
  // Datei anlegen
  fstream filestream("fstream2.dat", ios::out | ios::trunc);
  filestream.close();  // leere Datei existiert jetzt

  // Datei zum Lesen und Schreiben öffnen
  filestream.open("fstream2.dat", ios::in | ios::out);
  // schreiben
  for (int i = 0; i < 20; ++i) {
    filestream << i << ' ';  // kein EOF direkt nach der letzten Zahl
  }
  filestream << '\n';

  // lesen
  filestream.seekg(0);  // Anfang suchen
  while (filestream.good()) {
    int i;            // Hilfsvariable
    filestream >> i;  // lesen
    if (filestream.good()) {
      cout << i << ' ';  // Kontrollausgabe
    } else {
      cout << "\nDateiende erreicht (oder Lesefehler)";
    }
  }
  cout << '\n';
  filestream.clear();   // EOF-Status löschen
  filestream.seekp(5);  // Position 5 suchen

  filestream << "neuer Text ";  // ab Pos. 5 überschreiben
  filestream.seekg(0);          // Anfang suchen
  char buf[100];
  filestream.getline(buf, 100);  // Zeile lesen
  cout << buf << '\n';           // Kontrollausgabe
}
