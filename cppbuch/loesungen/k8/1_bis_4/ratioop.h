/* cppbuch/loesungen/k8/1_bis_4/ratioop.h
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
  Rational& operator-=(Rational);
  Rational& operator*=(Rational);
  Rational& operator/=(Rational);

  // weitere Methoden
  void set(long zaehler, long nenner);
  void kehrwert();
  void kuerzen();

private:
  long zaehler, nenner;
};

// inline Methoden
inline long Rational::getZaehler() const { return zaehler; }
inline long Rational::getNenner() const { return nenner; }

// globale Operatoren
Rational operator+(Rational, Rational);
Rational operator-(Rational, Rational);
Rational operator*(Rational, Rational);
Rational operator/(Rational, Rational);
bool operator==(Rational, Rational);

// freie Funktionen zur Ein- und Ausgabe
std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif
