/* cppbuch/loesungen/k1/11.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  const string str{"17462309"};  // aus Aufgabentext
  long int z = 0L;
  for (auto zeichen : str) {
    z *= 10;
    z += static_cast<int>(zeichen) - static_cast<int>('0');
  }
  cout << "z = " << z;
  int quersumme{};
  while (z > 0) {
    quersumme += z % 10;
    z /= 10;
  }
  cout << "   Quersumme = " << quersumme << '\n';
  return 0;
}
