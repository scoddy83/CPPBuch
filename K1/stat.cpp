//CPPBuch/K1/Übung stat.cpp
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string dateiname;
  cout << "Quelldatei? : ";
  cin >> dateiname;

  int anzZeichen {0};
  int anzWorter {1};
  int anzZeilen {1};
  int anzSatze {0};

  ifstream datei(dateiname, ios::binary);

  if(!datei.good()) {
    cerr << dateiname << " kann nicht geoeffnet werden!\n";
    exit(-1);
  }
  cout << "Ergebniss der Auswertung: \n\n";

  char c;     // evtl.  signet

  while (datei.get(c)) {
    anzZeichen++;
    switch (c) {
      case ' ':
        anzWorter++;
        break;
      case '.':
        anzSatze++;
        break;
      case '?':
        anzSatze++;
        break;
      case '!':
        anzSatze++;
        break;
      case '\n':
        anzZeilen++;
        anzWorter++;
        break;
    }
  }

  cout << "Anzahl der Zeichen: " << anzZeichen << '\n';
  cout << "Anzahl der Woerter: " << anzWorter << '\n';
  cout << "Anzahl der Saetze: " << anzSatze << '\n';
  cout << "Anzahl der Zeilen: " << anzZeilen << '\n';
}
