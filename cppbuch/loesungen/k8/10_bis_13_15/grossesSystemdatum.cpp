/* cppbuch/loesungen/k8/10_bis_13_15/grossesSystemdatum.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "grossesSystemdatum.h"
#include <cstddef>
#include <ctime>
#include <limits>

Datum maxDatumFuerAufgabe() {  // maximales Systemdatum lt. Aufgabe
                               // ermitteln
  std::time_t maxSekunden = std::numeric_limits<int>::max();
  // std::numeric_limits<time_t>::max(); ist bei 64-Bit Systemen zu
  // groß fuer tm!
  std::tm* z = localtime(&maxSekunden);
  std::size_t jahr = z->tm_year + 1900;
  std::size_t monat = z->tm_mon + 1;  // localtime liefert 0..11
  std::size_t tag = z->tm_mday;
  return Datum(tag, monat, jahr);
}
