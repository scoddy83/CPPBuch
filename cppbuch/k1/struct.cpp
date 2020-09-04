/* cppbuch/k1/struct.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

enum class Farbtyp { rot, gelb, gruen };

struct Punkt {
  int x;
  int y;
  bool istSichtbar;
  Farbtyp dieFarbe;
};

int main() {
  Punkt p1{100, 200, false, Farbtyp::gelb};  // direkte Initialisierung

  cout << "p1.x = " << p1.x << "  p1.y = " << p1.y
       << "  p1.istSichtbar= " << p1.istSichtbar
       << "  p1.dieFarbe= " << static_cast<int>(p1.dieFarbe) << '\n';
}
