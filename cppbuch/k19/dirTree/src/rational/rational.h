/* cppbuch/k19/dirTree/src/rational/rational.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Klasse für rationale Zahlen
#ifndef PROJEKT_RATIONAL_H
#define PROJEKT_RATIONAL_H
#include <iostream>

namespace projekt {
namespace rational {

class Rational {
public:
  Rational(long z = 0, long n = 1);  // allgemeiner Konstruktor

  // Abfragen
  long getZaehler() const;
  long getNenner() const;

  // arithmetische Methoden für \tt{+=}, \tt{-=}, \tt{*=}, \tt{/=},
  // (werden später durch überladene Operatoren ergänzt)
  void add(const Rational& r);
  void sub(const Rational& r);
  void mult(const Rational& r);
  void div(const Rational& r);

  // weitere Methoden
  void set(long zaehler, long nenner);
  void kehrwert();
  void kuerzen();

private:
  long zaehler, nenner;
};

// inline Methoden
inline Rational::Rational(long z, long n) : zaehler(z), nenner(n) {}

inline long Rational::getZaehler() const { return zaehler; }
inline long Rational::getNenner() const { return nenner; }

// globale Funktionsprototypen
const Rational add(const Rational& a, const Rational& b);
const Rational sub(const Rational& a, const Rational& b);
const Rational mult(const Rational& a, const Rational& b);
const Rational div(const Rational& z, const Rational& n);

void eingabe(Rational& r);
void ausgabe(const Rational& r, std::ostream& = std::cout);
}
}  // namespaces
#endif
