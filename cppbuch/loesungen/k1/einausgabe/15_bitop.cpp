/* cppbuch/loesungen/k1/einausgabe/15_bitop.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
//  Datei hexadezimal ausgeben
// Hilfsmittel: Bitoperationen
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
    unsigned char uc = static_cast<unsigned char>(c);  // unsigned!
    unsigned int low = static_cast<unsigned int>(uc) & 15;
    unsigned int hi = static_cast<unsigned int>(uc) >> 4;
    // Umsetzung der Werte 0..15 auf ASCII-Zeichen:
    if (low < 10) {
      low += 48;  // '0'...'9'
    } else {
      low += 55;  // 'A'...'F'
    }
    if (hi < 10) {
      hi += 48;
    } else {
      hi += 55;
    }
    cout << static_cast<char>(hi) << static_cast<char>(low) << ' ';
    if (++count % 20 == 0) {
      cout << '\n';
    }
  }
  cout << '\n';
}
