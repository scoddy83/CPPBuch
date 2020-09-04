/* cppbuch/k9/datum/datumeingabeoperator.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "datumeingabeoperator.h"

std::istream& operator>>(std::istream& eingabe, Datum& d) {
  // Einlese-Operator für ein Datum
  // erlaubte Formate: Tag.Monat.Jahr oder Tag/Monat/Jahr
  char c = {'\0'};
  std::size_t tag;
  eingabe >> tag >> c;  // Tag und 1. Trennzeichen
  if (c != '.' && c != '/') {
    eingabe.setstate(std::ios::failbit);  // Status setzen
  } else {
    std::size_t monat = 0;
    std::size_t jahr = 0;
    eingabe >> monat >> c;  // Monat und 2. Trennzeichen
    if (c != '.' && c != '/') {
      eingabe.setstate(std::ios::failbit);  // Status setzen
    } else {
      eingabe >> jahr;
    }
    if (jahr < 100) {
      jahr += 2000;
    }
    if (istGueltigesDatum(tag, monat, jahr)) {  // nur dann ändern
      d.set(tag, monat, jahr);
    } else {
      eingabe.setstate(std::ios::failbit);
    }
  }
  if (!eingabe.good()) {
    throw "kein gültiges Datum!";
  }
  return eingabe;
}
