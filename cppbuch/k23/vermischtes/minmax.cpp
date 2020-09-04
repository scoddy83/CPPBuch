/* cppbuch/k23/vermischtes/minmax.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  cout << "Das Minimum der Zahlen 1 und 2 ist " << min(1, 2)
       << ".\nDas Maximum der Zahlen 3.4 und -2.2 ist " << max(3.4, -2.2)
       << ".\nVon den Zahlen 100 und 700 ist" << minmax(100, 700).first
       << " die kleinere und " << minmax(100, 700).second
       << " die größere.\nMit initializer_list:\nDas Minimum der Zahlen "
    "{6,-8,1,2,3} ist "  << min({6, -8, 1, 2, 3})
       << ".\nDas Maximum der Zahlen {6,-8,1,2,3} ist " 
       << max({6, -8, 1, 2, 3});
  cout << "\nVon den Zahlen {6,-8,1,2,3} ist "
       << minmax({6, -8, 1, 2, 3}).first << " die kleinste und "
       << minmax({6, -8, 1, 2, 3}).second 
       << " die größte.\nWenn das Vorzeichen ignoriert werden soll "
          "(Absolutbetrag):\nVon den Zahlen {6,-8,1,2,3} ist ";
  auto ergebnis =  minmax({6, -8, 1, 2, 3},
                          [](int x, int y) { return abs(x) < abs(y); });
  cout << ergebnis.first  << " die kleinste und " << ergebnis.second
       << " die größte.\n";
}
