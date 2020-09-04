/* cppbuch/loesungen/k1/einausgabe/15_io_hex.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
//  Datei hexadezimal ausgeben
// Hilfsmittel: cout << hex
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

  char c;
  cout << hex;
  unsigned int count = 0;
  while (quelle.get(c)) {
    unsigned char uc = static_cast<unsigned char>(c);
    int zahl = static_cast<int>(uc);
    cout.width(2);
    cout.fill('0');
    cout << zahl << ' ';
    if (++count % 20 == 0) {
      cout << '\n';
    }
  }
  cout << '\n';
}
