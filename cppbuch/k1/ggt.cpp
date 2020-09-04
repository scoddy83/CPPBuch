/* cppbuch/k1/ggt.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  unsigned int x, y;
  cout << "2 Zahlen > 0 eingeben :";
  cin >> x >> y;
  cout << "Der GGT von " << x << " und " << y << " ist ";
  while (x != y) {
    if (x > y) {
      x -= y;
    } else {
      y -= x;
    }
  }
  cout << x << '\n';
}
