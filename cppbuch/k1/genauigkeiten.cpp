/* cppbuch/k1/genauigkeiten.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <limits>
using namespace std;

int main() {
  cout << "Die Genauigkeit von float beträgt etwa "
       << numeric_limits<float>::digits10 << " Dezimalstellen.\n";
  cout << "Die Genauigkeit von double beträgt etwa "
       << numeric_limits<double>::digits10 << " Dezimalstellen.\n";
  cout << "Die Genauigkeit von long double beträgt etwa "
       << numeric_limits<long double>::digits10 << " Dezimalstellen.\n";
}
