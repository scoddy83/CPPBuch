/* cppbuch/loesungen/k1/einausgabe/15.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
//  Datei hexadezimal ausgeben
// Hilfsmittel: Zeichen mit String ermitteln
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

  // char ist notwendig, weil get(unsigned char&) nicht
  // implementiert ist (GNU C++)
  char c;  // signed!
  unsigned int count = 0;
  while (quelle.get(c)) {
    unsigned char uc = static_cast<unsigned char>(c);
    unsigned int zahl = static_cast<unsigned int>(uc);
    const string codierung{"0123456789ABCDEF"};
    // 2 stellig ausgeben
    cout << codierung.at(zahl / 16) << codierung.at(zahl % 16) << ' ';
    if (++count % 20 == 0) {
      cout << '\n';
    }
  }
  cout << '\n';
}
