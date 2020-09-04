/* cppbuch/k1/auto.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <vector>                           // Standard-Vektor einschließen
using namespace std;

struct Punkt {
  int x;
  int y;
};

int main() {
  Punkt p1{100, 200};
  auto p2 = p1;  // \tt{p2} ist auch vom Typ \tt{Punkt}
  cout << "p2.x= " << p2.x << "  p2.y= " << p2.y << '\n';

  vector<double> v1{1.1, 2.2, 3.3, 4.4, 5.5};
  auto v2(v1);  // \tt{v2} ist auch vom Typ \tt{vector<double>}
  for (auto wert : v2) {
    cout << wert << ' ';                    // anzeigen
  }
  cout << '\n';
  // mit Referenz
  for (auto& wert : v2) {
    wert *= 2.0;                            // alle Elemente verdoppeln
  }
  for (auto wert : v2) {
    cout << wert << ' ';                    // anzeigen
  }
  cout << '\n';
}
