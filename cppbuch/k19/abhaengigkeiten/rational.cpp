/* cppbuch/k19/abhaengigkeiten/rational.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// (Definition der Methoden)
#include "rational.h"
#include <cassert>

namespace {
// Die  Funktion ggt() wird zum Kürzen benötigt. Sie berechnet den
// größten
// gemeinsamen Teiler. Verwendet wird ein modifizierter
// Euklid-Algorithmus, in dem
// Subtraktionen durch die schnellere Restbildung ersetzt werden.
long ggt(long x, long y) {
  long rest;
  while (y > 0) {
    rest = x % y;
    x = y;
    y = rest;
  }
  return x;
}
}

// Elementfunktionen

void Rational::add(const Rational& r) {
  zaehler = zaehler * r.nenner + r.zaehler * nenner;
  nenner = nenner * r.nenner;
  kuerzen();
}

void Rational::sub(const Rational& r) {
  zaehler = zaehler * r.nenner - r.zaehler * nenner;
  nenner = nenner * r.nenner;
  kuerzen();
}

void Rational::mult(const Rational& r) {
  zaehler = zaehler * r.zaehler;
  nenner = nenner * r.nenner;
  kuerzen();
}

void Rational::div(const Rational& r) {
  zaehler = zaehler * r.nenner;
  nenner = nenner * r.zaehler;
  kuerzen();
}

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

void Rational::kuerzen() {
  // Vorzeichen merken und Betrag bilden
  int sign = 1;
  if (zaehler < 0) {
    sign = -sign;
    zaehler = -zaehler;
  }
  if (nenner < 0) {
    sign = -sign;
    nenner = -nenner;
  }
  long teiler = ggt(zaehler, nenner);  // siehe oben
  zaehler = sign * zaehler / teiler;   // Vorzeichen restaurieren
  nenner = nenner / teiler;
}

// Es folgen die globalen arithmetische Funktionen für die
// Operationen mit 2 Argumenten (binäre Operationen)

const Rational add(const Rational& a, const Rational& b) {
  //  Die eigentliche Berechnung muss hier nicht wiederholt werden,
  //  sondern die bereits
  //  vorhandenen  Funktionen für die Kurzformen  der Addition usw.
  //  können vorteilhaft
  //  wiederverwendet werden. Dazu wird ein mit \tt{a}
  //  initialisiertes
  //  temporäres Objekt
  // erzeugt, auf das das Argument \tt{b} addiert und das dann als
  // Ergebnis
  //  zurückgegeben wird.
  Rational r = a;
  //  Das temporäre Objekt \tt{r} wird benötigt, weil \tt{a} wegen
  //  der
  //  const-Eigenschaft
  //  nicht verändert werden kann (und darf). Die eigentlich bessere
  //  Alternative wäre
  //  die Übergabe per Wert -- dann könnte mit der lokalen Kopie
  //  gearbeitet werden
  //  (Begründung siehe Text).
  r.add(b);
  return r;
}

const Rational sub(const Rational& a, const Rational& b) {
  Rational r = a;  // siehe Diskussion bei \tt{add()}
  r.sub(b);
  return r;
}

const Rational mult(const Rational& a, const Rational& b) {
  Rational r = a;  // siehe Diskussion bei \tt{add()}
  r.mult(b);
  return r;
}

const Rational div(const Rational& z, const Rational& n) {
  Rational r = z;  // siehe Diskussion bei \tt{add()}
  r.div(n);
  return r;
}

// Funktionen für Ein- und Ausgabe

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
