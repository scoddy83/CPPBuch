/* cppbuch/k8/rational/ratioop.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "ratioop.h"
#include <stdexcept>

namespace {
void pruefeUngleichNull(long nenner) {
  if (nenner == 0) {
    throw std::invalid_argument("Nenner darf nicht null sein!");
  }
}
}
// globale Hilfsfunktion (größter gemeinsamer Teiler)
long ggt(long x, long y) {
  long rest;
  while (y) {
    rest = x % y;
    x = y;
    y = rest;
  }
  return x;
}

// ******+ Methodenimplementation ********

Rational::Rational(long z, long n) : zaehler{z}, nenner{n} {
  pruefeUngleichNull(nenner);
  kuerzen();
}

void Rational::set(long z, long n) {
  zaehler = z;
  nenner = n;
  pruefeUngleichNull(nenner);
  kuerzen();
}

void Rational::kehrwert() {
  long temp = zaehler;
  zaehler = nenner;
  nenner = temp;
  pruefeUngleichNull(nenner);
}

void Rational::kuerzen() {
  int sign = 1;
  if (zaehler < 0) {
    sign = -sign;
    zaehler = -zaehler;
  }
  if (nenner < 0) {
    sign = -sign;
    nenner = -nenner;
  }
  long teiler = ggt(zaehler, nenner);
  zaehler = sign * zaehler / teiler;
  nenner = nenner / teiler;
}

Rational& Rational::operator+=(Rational b) {
  zaehler = zaehler * b.nenner + b.zaehler * nenner;
  nenner = nenner * b.nenner;
  kuerzen();
  return *this;
}

// ******* globale Operator + ******** -, * und / siehe
// Übungsaufgabe

Rational operator+(Rational a, Rational b) {
  return a += b;  // Rückgabe von \tt{a.operator+=(b)}
}

// ******* weiterer globaler Operator
bool operator==(Rational a, Rational b) {
  return a.getZaehler() == b.getZaehler() && a.getNenner() == b.getNenner();
}

std::ostream& operator<<(std::ostream& ausgabe, Rational r) {
  ausgabe << r.getZaehler() << "/" << r.getNenner();
  return ausgabe;
}

std::istream& operator>>(std::istream& eingabe, Rational& r) {
  long int z;
  long int n;
  eingabe >> z >> n;
  pruefeUngleichNull(n);
  r.set(z, n);
  r.kuerzen();
  return eingabe;
}
