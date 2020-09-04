/* cppbuch/k9/tabelle/tabelle.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cmath>  //  cos(),sin()
#include <iostream>
#include <pi.h>  //  pi
using namespace std;

int main() {
  cout << "Grad      sin(x)      cos(x)\n";
  cout.setf(ios::showpoint | ios::fixed, ios::floatfield);
  cout.precision(6);

  for (int grad = 0; grad <= 90; grad += 10) {
    // Grad in Bogenmaß umwandeln
    const double rad = static_cast<double>(grad) / 180.0 * pi<double>;
    cout.width(4);
    cout << grad;
    cout.width(12);
    cout << sin(rad);
    cout.width(12);
    cout << cos(rad) << '\n';
  }
}
