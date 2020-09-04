/* cppbuch/loesungen/k2/13.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <vector>
using namespace std;

double polynom(const vector<double>& koeff, double x) {
  // koeff enthält die Koeffizienten des Polynoms
  // n = koeff.size()-1
  // ergebnis = koeff[0] + koeff[1]*x ++ koeff[2]*x*x + ...
  //     ... + koeff[n]*x^n
  int n = koeff.size() - 1;
  double ergebnis = koeff[n];
  for (int i = n - 1; i >= 0; --i) {
    ergebnis *= x;
    ergebnis += koeff[i];
  }
  return ergebnis;
}

int main() {
  vector<double> koeffizienten(3);
  koeffizienten[0] = 1.1;
  koeffizienten[1] = 2.22;
  koeffizienten[2] = 13.0;
  cout << polynom(koeffizienten, 2.04) << '\n';
  cout << polynom(koeffizienten, 3.033) << '\n';
}
