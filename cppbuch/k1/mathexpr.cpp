/* cppbuch/k1/mathexpr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Berechnung mathematischer Ausdrücke

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  float x;
  cout << "x eingeben:";
  cin >> x;
  cout << " x       = " << x << '\n';
  cout << " fabs(x) = " << fabs(x) << '\n';
  cout << " sqrt(x) = " << sqrt(x) << '\n';
  cout << " sin(x)  = " << sin(x) << '\n';  // x im Bogenmaß
  cout << " exp(x)  = " << exp(x) << '\n';
  cout << " log(x)  = " << log(x) << '\n';
}
