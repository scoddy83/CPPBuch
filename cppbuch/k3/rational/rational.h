/* cppbuch/k3/rational/rational.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
public:
  Rational(long z = 0, long n = 1);  // allgemeiner Konstruktor

  // Abfragen
  long getZaehler() const;
  long getNenner() const;

  // arithmetische Methoden für \tt{+=}, \tt{-=}, \tt{*=}, \tt{/=},
  // (werden später durch überladene Operatoren ergänzt)
  void add(Rational r);
  void sub(Rational r);
  void mult(Rational r);
  void div(Rational r);

  // weitere Methoden
  void set(long zaehler, long nenner);
  void kehrwert();
  void kuerzen();

private:
  long zaehler, nenner;
};

// inline Methoden
inline Rational::Rational(long z, long n) : zaehler{z}, nenner{n} {}

inline long Rational::getZaehler() const { return zaehler; }
inline long Rational::getNenner() const { return nenner; }

// globale Funktionsprototypen
Rational add(Rational a, Rational b);
Rational sub(Rational a, Rational b);
Rational mult(Rational a, Rational b);
Rational div(Rational z, Rational n);

void eingabe(Rational& r);
void ausgabe(Rational r, std::ostream& = std::cout);

#endif
