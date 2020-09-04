/* cppbuch/k1/overflow.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <limits>
using namespace std;

int main() {
  int ai{50000};      // Initialisierung mit 50000
  int bi{1'000'000};  // Initialisierung mit 1000000, mit Trennzeichen
  int ci{ai * bi};
  cout << "int-Zahlen haben auf Ihrem System " << 8 * sizeof(int)
       << " Bits\n";
  cout << "Rechnung mit int: ";
  cout << ai << " * " << bi << " = " << ci << '\n';
  // Ausgabe -1539607552 statt 50000000000 bei 32 Bit-int

  long al{50000L};  // L (oder l): Kennzeichnung als \tt{long}
  long bl{1000000L};
  long cl{al * bl};
  cout << "long-Zahlen haben auf Ihrem System " << 8 * sizeof(long)
       << " Bits\n";
  cout << "Rechnung mit long: ";
  cout << al << " * " << bl << " = " << cl << '\n';

  cout << "long-Overflow produzieren:\n";
  al = numeric_limits<long>::max() / 2 + 1000;
  cout << "2 * " << al << " = " << (2 * al) << " ?\n";
}
