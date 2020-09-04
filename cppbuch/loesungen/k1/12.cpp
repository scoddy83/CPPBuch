/* cppbuch/loesungen/k1/12.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  cout << "Umwandlung einer natürlichen(!) dezimalen Ganzzahl in "
          "eine römische Zahl.\n Dezimalzahl eingeben:";
  unsigned int dezimalzahl;
  cin >> dezimalzahl;
  // Position                  0123456
  const string ZEICHENVORRAT{"IVXLCDM"};
  unsigned int zehner{1000}, n{6};  // Start mit M=1000 (Pos. 6)
  string ergebnis;

  while (dezimalzahl != 0) {  // Ziffern sukzessive abtrennen
    auto ziffer = dezimalzahl / zehner;

    if ((ziffer > 3 && zehner == 1000)  // Tausender
        || ziffer <= 3) {               // oder 0,1,2,3
      for (unsigned int i = 1; i <= ziffer; i++) {
        ergebnis += ZEICHENVORRAT.at(n);
      }
    } else if (ziffer <= 4) {  // 4
      ergebnis += ZEICHENVORRAT.at(n);
      ergebnis += ZEICHENVORRAT.at(n + 1);
    } else if (ziffer <= 8) {  // 5,6,7,8
      ergebnis += ZEICHENVORRAT.at(n + 1);
      for (unsigned int i = 1; i <= ziffer - 5; i++) {
        ergebnis += ZEICHENVORRAT.at(n);
      }
    } else {
      ergebnis += ZEICHENVORRAT.at(n);  // 9
      ergebnis += ZEICHENVORRAT.at(n + 2);
    }
    n -= 2;
    dezimalzahl %= zehner;
    zehner /= 10;
  }
  cout << "Ergebnis: " << ergebnis << '\n';
}
