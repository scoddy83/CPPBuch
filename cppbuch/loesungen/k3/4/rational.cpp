/* cppbuch/loesungen/k3/4/rational.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "rational.h"

void Rational::set(long z, long n) {
  zaehler = z;
  nenner = n;
  assert(nenner != 0);
  kuerzen();
}

void Rational::kehrwert() {
  long temp = zaehler;
  zaehler = nenner;
  nenner = temp;
  assert(nenner != 0);
}

void eingabe(Rational& r) {
  long int z;
  long int n;
  std::cin >> z >> n;
  assert(n != 0);
  r.set(z, n);
  r.kuerzen();
}

void ausgabe(const Rational& r, std::ostream& os) {
  os << r.getZaehler() << "/" << r.getNenner() << '\n';
}
