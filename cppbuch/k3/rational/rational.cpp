/* cppbuch/k3/rational/rational.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// (Definition der Methoden)
#include "rational.h"
#include <cassert>

namespace {
// Die  Funktion ggt() wird zum Kürzen benötigt. Sie berechnet den größten
// gemeinsamen Teiler. Verwendet wird ein modifizierter Euklid-Algorithmus,
// in dem Subtraktionen durch die schnellere Restbildung ersetzt werden.
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

void Rational::add(Rational r) {
  zaehler = zaehler * r.nenner + r.zaehler * nenner;
  nenner = nenner * r.nenner;
  kuerzen();
}

void Rational::sub(Rational r) {
  zaehler = zaehler * r.nenner - r.zaehler * nenner;
  nenner = nenner * r.nenner;
  kuerzen();
}

void Rational::mult(Rational r) {
  zaehler = zaehler * r.zaehler;
  nenner = nenner * r.nenner;
  kuerzen();
}

void Rational::div(Rational r) {
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

// Es folgen die globalen arithmetischen Funktionen für die
// Operationen mit 2 Parametern (binäre Operationen)

Rational add(Rational a, Rational b) {
  // Die eigentliche Berechnung muss hier nicht wiederholt werden, sondern
  // die bereits vorhandenen  Funktionen für die Kurzformen  der Addition usw.
  // können vorteilhaft wiederverwendet werden. Dazu wird auf \tt{a}, dass per
  // Wert übergeben wird und daher eine Kopie darstellt, das Argument \tt{b}
  // addiert. Das Ergebnis wird zurückgegeben.
  a.add(b);
  return a;
}

Rational sub(Rational a, Rational b) {
  a.sub(b);  // siehe Diskussion bei \tt{add()}
  return a;
}

Rational mult(Rational a, Rational b) {
  a.mult(b);  // siehe Diskussion bei \tt{add()}
  return a;
}

Rational div(Rational z, Rational n) {
  z.div(n);  // siehe Diskussion bei \tt{add()}
  return z;
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

void ausgabe(Rational r, std::ostream& os) {
  os << r.getZaehler() << "/" << r.getNenner() << '\n';
}
