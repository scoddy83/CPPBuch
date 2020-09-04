/* cppbuch/k8/datum/datum.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "datum.h"
#include <ctime>

Datum::Datum() { aktuell(); }

void Datum::set(std::size_t t, std::size_t m, std::size_t j) {
  if (!istGueltigesDatum(t, m, j)) {
    throw UngueltigesDatumException(t, m, j);
  }
  tag_ = t;
  monat_ = m;
  jahr_ = j;
}

void Datum::aktuell() {  // Systemdatum eintragen
  // \tt{time\_t, time(), tm, localtime()} sind in <ctime>
  // deklariert
  time_t now{time(NULL)};  // aktuelle Zeit in s seit 1.1.1970
  tm* z{localtime(&now)};  // Zeiger auf eine vordefinierte Struktur des Typs \tt{tm}.
  jahr_ = static_cast<std::size_t>(z->tm_year + 1900);
  monat_ = static_cast<std::size_t>(z->tm_mon + 1);  // \tt{localtime} liefert 0..11
  tag_ = static_cast<std::size_t>(z->tm_mday);
}

Datum& Datum::operator++() {  // Tag hochzählen, präfix
  ++tag_;
  if (!istGueltigesDatum(tag_, monat_, jahr_)) {  // Monatsende erreicht?
    tag_ = 1;
    if (++monat_ > 12) {  // Jahresende erreicht?
      monat_ = 1;
      ++jahr_;
    }
  }
  return *this;
}

Datum Datum::operator++(int) {  // Datum um 1 Tag erhöhen
  Datum temp = *this;
  ++*this;  // Präfix ++ aufrufen
  return temp;
}

Datum::operator std::string() const {
  std::string temp("tt.mm.jjjj");
  temp[0] = static_cast<char>(tag_ / 10 + '0');
  temp[1] = static_cast<char>(tag_ % 10 + '0');
  temp[3] = static_cast<char>(monat_ / 10 + '0');
  temp[4] = static_cast<char>(monat_ % 10 + '0');
  std::size_t pos = 9;  // letzte Jahresziffer
  std::size_t j = jahr_;
  while (j > 0) {
    temp[pos] = j % 10 + '0';  // letzte Ziffer
    j = j / 10;                // letzte Ziffer abtrennen
    --pos;
  }
  return temp;
}
