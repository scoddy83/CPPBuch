/* cppbuch/k8/mathvek/mvektor.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef MVEKTOR_T
#define MVEKTOR_T
#include "../vektor/vektor.t"
#include <iostream>

template <typename T> class MathVektor : public Vektor<T> {
public:
  using super = Vektor<T>;  // Abkürzung für Oberklassentyp
  using Vektor<T>::Vektor;  // Konstruktoren erben
  void init(T);             // alle Elemente setzen

  // Operatoren
  MathVektor& operator*=(T);  // Operator \tt{*=}
  // weitere Operatoren und Funktionen ...
};

/*************** Implementation *********************/

template <typename T> void MathVektor<T>::init(T wert) {
  for (std::size_t i = 0; i < super::size(); ++i) {
    super::operator[](i) = wert;
  }
}

template <typename T> MathVektor<T>& MathVektor<T>::operator*=(T zahl) {
  for (std::size_t i = 0; i < super::size(); ++i) {
    super::operator[](i) *= zahl;  // elementweise Multiplikation
  }
  return *this;
}

// \tt{*} Operator für den Fall  \tt{v1 = zahl*v2;}
template <typename T> MathVektor<T> operator*(T zahl, MathVektor<T> mv) {
  return mv *= zahl;  // Aufruf von \tt{operator*=()}
}

// \tt{*} Operator für den Fall  \tt{v1 = v2*zahl;}
// (vertauschte Reihenfolge der Argumente)
template <typename T> MathVektor<T> operator*(MathVektor<T> mv, T zahl) {
  return mv *= zahl;  // Aufruf von \tt{operator*=()}
}

/* Weil MathVektor nur mit mathematisch sinnvolle Datentypen
instantiiert wird, für die der Standardausgabeoperator definiert
ist, ist es sinnvoll, einen Operator für die Ausgabe eines
MathVektor-Objekts zu definieren:
*/

template <typename T>
std::ostream& operator<<(std::ostream& os, const MathVektor<T>& v) {
  // Verbesserungen im Ausgabelayout sind möglich!
  for (std::size_t i = 0; i < v.size(); ++i) {
    os << v[i] << '\t';
    if ((i + 1) % 8 == 0 || i == v.size() - 1) {
      os << '\n';
    }
  }
  return os;
}
#endif
