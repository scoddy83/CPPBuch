/* cppbuch/loesungen/k5/3/loesung1/teilnehmer.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "teilnehmer.h"
#include <iostream>

Teilnehmer::Teilnehmer(const std::string& n) : name{n} {}

void Teilnehmer::lerntKennen(Teilnehmer& tn) {
  if (&tn != this       // 'sich selbst kennenlernen' ignorieren
      && !kennt(tn)) {  // wenn noch unbekannt, eintragen
    dieBekannten.push_back(tn.gibNamen());
    tn.lerntKennen(*this);  // wechselseitig kennenlernen
  }
}

bool Teilnehmer::kennt(const Teilnehmer& tn) const {
  bool erg{false};
  for (const auto& bekannte : dieBekannten) {
    if (tn.gibNamen() == bekannte) {
      erg = true;
      break;
    }
  }
  return erg;
}

void Teilnehmer::druckeBekannte() const {
  for (const auto& bekannte : dieBekannten) {
    std::cout << "  " << bekannte;
  }
  std::cout << '\n';
}

const std::string& Teilnehmer::gibNamen() const { return name; }
