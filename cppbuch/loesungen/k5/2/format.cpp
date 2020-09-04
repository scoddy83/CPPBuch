/* cppbuch/loesungen/k5/2/format.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "format.h"
#include <iostream>
using namespace std;

Format::Format(unsigned int w, unsigned int nk)
    : weite{w}, nachkommastellen{nk} {
  if (nachkommastellen > 16) {
    nachkommastellen = 16;
  }
  if (weite < nachkommastellen) {
    weite = nachkommastellen + 1;
  }
}

string Format::toString(double d) const {
  string ergebnis;
  bool negativ{false};
  if (d < 0.0) {
    negativ = true;
    d = -d;
  }
  // Rundung
  double rund{0.5};
  for (unsigned int i = 0; i < nachkommastellen; ++i) {
    rund /= 10.0;
  }
  d += rund;

  // Mit der folgenden Normierung (d.h. Zahl beginnt mit 0,..) wird
  // erreicht, dass die
  // Anzahl der Stellen vor dem Komma bekannt ist (Stellenwert).
  int stellenwert = 0;
  // Zahl normieren, falls >=1
  while (d >= 1.0) {
    ++stellenwert;
    d /= 10.0;
  }
  if (stellenwert == 0) {
    ergebnis += '0';  // wenigstens eine 0 vor dem Komma
  }

  // Die Zahl wird sukzessive mit 10 multipliziert, die jeweils
  // erste
  // Ziffer zunächst
  //  ermittelt (zif), dann abgetrennt und an den Ergebnis-String
  //  gehängt usw.
  // Zahl abarbeiten
  do {
    if (stellenwert == 0) {
      ergebnis += ',';  // Komma
    }
    d *= 10.0;
    int zif = static_cast<int>(d);
    d -= zif;
    ergebnis += zif + '0';
    --stellenwert;
  } while (static_cast<int>(nachkommastellen) + stellenwert > 0);

  if (negativ) {
    ergebnis = '-' + ergebnis;
    ;
  }
  int diff = weite - ergebnis.length();
  for (int i = 0; i < diff; ++i) {
    ergebnis = " " + ergebnis;
  }
  return ergebnis;
}
