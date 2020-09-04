/* cppbuch/loesungen/k23/2/quadglcmplx.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Beispiel quadratische Gleichung \tt{x*x+p*x+q = 0}
// \tt{x1 = -p/2 + sqrt(p*p/4-q), x2 = -p/2 - sqrt(p*p/4-q)}
#include <cmath>
#include <complex>
#include <iostream>
using namespace std;

int main() {
  cout << "Quadratische Gleichung x*x+p*x+q = 0\n"
       << "Koeffizienten p, q eingeben:";
  double p, q;
  cin >> p >> q;
  double Diskriminante = p * p / 4.0 - q;

  cout << "Lösung :\n";
  if (Diskriminante >= 0.0) {
    double x1 = -p / 2.0 + sqrt(Diskriminante);
    double x2 = -p / 2.0 - sqrt(Diskriminante);
    cout << "x1= " << x1 << "   x2= " << x2 << '\n';
  } else {
    complex<double> ergebnis(-p / 2, sqrt(-Diskriminante));
    cout << "x1 = " << ergebnis;
    cout << "\nx2 = " << conj(ergebnis) << '\n';
  }
}
