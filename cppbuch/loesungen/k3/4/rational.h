/* cppbuch/loesungen/k3/4/rational.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef RATIONAL_H
#define RATIONAL_H
#include <cassert>
#include <iostream>

constexpr long ggt(long x, long y) {
  long rest = 0;
  while (y > 0) {
    rest = x % y;
    x = y;
    y = rest;
  }
  return x;
}

class Rational {
public:
  constexpr Rational(long z = 0, long n = 1) : zaehler{z}, nenner{n} {}

  // Abfragen
  constexpr long getZaehler() const { return zaehler; }
  constexpr long getNenner() const { return nenner; }

  // arithmetische Methoden für \tt{+=}, \tt{-=}, \tt{*=}, \tt{/=},
  // (werden später durch überladene Operatoren ergänzt)
  constexpr void add(const Rational& r) {
    zaehler = zaehler * r.nenner + r.zaehler * nenner;
    nenner = nenner * r.nenner;
    kuerzen();
  }
  constexpr void sub(const Rational& r) {
    zaehler = zaehler * r.nenner - r.zaehler * nenner;
    nenner = nenner * r.nenner;
    kuerzen();
  }

  constexpr void mult(const Rational& r) {
    zaehler = zaehler * r.zaehler;
    nenner = nenner * r.nenner;
    kuerzen();
  }

  constexpr void div(const Rational& r) {
    zaehler = zaehler * r.nenner;
    nenner = nenner * r.zaehler;
    kuerzen();
  }

  constexpr void kuerzen() {
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

  // nicht-constexpr Methoden
  void set(long z, long n);
  void kehrwert();

private:
  long zaehler, nenner;
};

// globale Funktionen
constexpr Rational add(const Rational& a, const Rational& b) {
  Rational r = a;
  r.add(b);
  return r;
}

constexpr Rational sub(const Rational& a, const Rational& b) {
  Rational r = a;  // siehe Diskussion bei \tt{add()}
  r.sub(b);
  return r;
}

constexpr Rational mult(const Rational& a, const Rational& b) {
  Rational r = a;  // siehe Diskussion bei \tt{add()}
  r.mult(b);
  return r;
}

constexpr Rational div(const Rational& z, const Rational& n) {
  Rational r = z;  // siehe Diskussion bei \tt{add()}
  r.div(n);
  return r;
}

void eingabe(Rational& r);
void ausgabe(const Rational& r, std::ostream& = std::cout);

#endif
