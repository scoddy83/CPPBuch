//CPPBuch/K1/Übung 1.16
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string dateiname;
  cout << "Quelldatei? : ";
  cin >> dateiname;
  string hexhasugabe {};

  ifstream datei(dateiname, ios::binary);

  if(!datei.good()) {
    cerr << dateiname << " kann nicht geoeffnet werden!\n";
    exit(-1);
  }
  cout << "Der Inhalt der Datei in hexadezimal Werten: \n\n";

  char c;     // evtl.  signet
  unsigned int count = 0;
  while (datei.get(c)) {
    if (count < 16) {
      unsigned char uc = static_cast<unsigned char>(c);
      unsigned int zahl = static_cast<unsigned int>(uc);
      const string codierung{"0123456789ABCDEF"};
      // 2 stellig ausgeben
      cout << c;
      hexhasugabe += codierung.at(zahl / 16);
      hexhasugabe += codierung.at(zahl % 16);
      hexhasugabe += ' ';
    }
    if(c == '\n') {
      cout << '\n' << hexhasugabe;
      cout << '\n';
      hexhasugabe = "";
      count = 0;
    }
    count++;
  }
  cout << '\n' << hexhasugabe;
  cout << '\n';
  cout << "\nEnde!";
}
