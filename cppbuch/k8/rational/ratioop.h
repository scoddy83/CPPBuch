/* cppbuch/k8/rational/ratioop.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Klasse für rationale Zahlen mit überladenen Operatoren
#ifndef RATIOOP_H
#define RATIOOP_H
#include <iostream>

class Rational {
public:
  Rational(long z = 0L, long n = 1L);  // ersetzt Typumwandlungskonstruktor

  // Abfragen
  long getZaehler() const;
  long getNenner() const;

  // arithmetische Methoden
  Rational& operator+=(Rational);
  // weitere arithmetische Methoden weggelassen ...

  // weitere Methoden
  void set(long zaehler, long nenner);
  void kehrwert();
  void kuerzen();

private:
  long zaehler;
  long nenner;
};

// inline Methoden
inline long Rational::getZaehler() const { return zaehler; }
inline long Rational::getNenner() const { return nenner; }

// globaler Operator +.   -, * und / siehe Übungsaufgabe
Rational operator+(Rational, Rational);

// ******* weiterer globaler Operator
bool operator==(Rational, Rational);

// globale Funktionen zur Ein- und Ausgabe
std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif
