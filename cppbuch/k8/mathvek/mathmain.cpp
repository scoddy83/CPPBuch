/* cppbuch/k8/mathvek/mathmain.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "mvektor.t"
using namespace std;

int main() {
  MathVektor<double> v1(4, 1.0), v2(10, 2.0);
  cout << "v1 = " << v1;
  cout << "v2 = " << v2;

  v1 *= 1.234567;  // alle Elemente von \tt{v1} multiplizieren
  cout << "v1 = " << v1;

  v1 = v2 * 1.234567;
  cout << "v1 = v2 * 1.234567      :\n" << v1;

  v1 = 1.234567 * v2;
  cout << "ist gleich 1.234567 * v2:\n" << v1;

  MathVektor<double> v3 = {1.1, 2.2, 3.3};
  cout << "v3 = " << v3;
}
