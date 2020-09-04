/* cppbuch/loesungen/k1/einausgabe/16.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Aufgabe: Datei hexadezimal ausgeben mit Erweiterung:
// Buchstaben und Hexcode nebeneinander
// Die Erweiterung kann gelöst werden, wenn das Ergebnis zeilenweise
// in  zwei string-Variablen zwischengespeichert wird.
#include <cstdlib>  // für exit()
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Dateiname :";
  string Quelldateiname;
  cin >> Quelldateiname;

  ifstream quelle(Quelldateiname, ios::binary);
  if (!quelle) {  // muss existieren
    cerr << Quelldateiname << " kann nicht geöffnet werden!\n";
    exit(-1);
  }

  unsigned int count = 0;
  // char ist notwendig, weil get(unsigned char&) nicht
  // implementiert ist (GNU C++)
  constexpr unsigned int ZEILENLAENGE = 16;
  string buchstaben;
  string hexcodes;
  char c;
  while (quelle.get(c)) {
    unsigned char uc = static_cast<unsigned char>(c);
    unsigned int zahl = static_cast<unsigned int>(uc);
    const string codierung{"0123456789ABCDEF"};
    hexcodes += codierung.at(zahl / 16);
    hexcodes += codierung.at(zahl % 16);
    hexcodes += ' ';
    if (c < ' ') {  // nicht druckbares Zeichen
      c = '.';
    }
    buchstaben += c;
    ++count;
    count %= ZEILENLAENGE;
    if (count == 0) {
      cout << buchstaben << "   " << hexcodes << '\n';
      buchstaben = "";
      hexcodes = "";
    }
  }
  if (count != 0) {  // Rest ausgeben
    cout << buchstaben;
    for (unsigned int i = 0; i < (ZEILENLAENGE - count); ++i) {
      cout << ' ';
    }
    cout << "   " << hexcodes << '\n';
  }
  cout << '\n';
}
