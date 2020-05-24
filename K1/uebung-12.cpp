//CPPBuch/K1/Übung 1.12
#include <iostream>
#include <string>
using namespace std;



int main () {
  unsigned int zahl {};
  const string zeichenvorat {"IVXLCDM"};

  cout << "Bitte geben Sie eine beliebige Zahl ein: ";
  cin >> zahl;

  unsigned int zehner {1000}, pos{6};
  string ergebnis;
  // Evaluierung der 1000 für Römisch M
  while (zahl != 0) {
    auto ziffer = zahl / zehner;

    if((ziffer > 3 && zehner == 1000) || ziffer <= 3 ) {
      for(unsigned int i = 1; i <= ziffer; i++) {
        ergebnis += zeichenvorat.at(pos);
      }
    } else if (ziffer <= 4) {
      ergebnis += zeichenvorat.at(pos);
      ergebnis += zeichenvorat.at(pos+1);
    } else if (ziffer <= 8) {
      ergebnis += zeichenvorat.at(pos+1);
      for(unsigned int i = 1; i <= ziffer - 5; i++) {
        ergebnis += zeichenvorat.at(pos);
      }
    } else {
      ergebnis += zeichenvorat.at(pos);
      ergebnis += zeichenvorat.at(pos+2);
    }

    pos -= 2;
    zahl %= zehner;
    zehner /= 10;
  }

  cout << "\nDie Zahl " << zahl << " als roemische Zahl :  " << ergebnis << '\n';
}
