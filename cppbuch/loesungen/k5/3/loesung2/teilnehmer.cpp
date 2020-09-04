/* cppbuch/loesungen/k5/3/loesung2/teilnehmer.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "teilnehmer.h"
#include <cstddef>
#include <iostream>

Teilnehmer::Teilnehmer(const std::string& n) : name{n} {}

Teilnehmer::~Teilnehmer() {
  for (auto bekannte : dieBekannten) {
    std::vector<Teilnehmer*>& zuModifizieren = bekannte->dieBekannten;
    for (std::size_t i = 0; i < zuModifizieren.size(); ++i) {
      if (zuModifizieren[i] == this) {  // gefunden
        // Löschen, indem der letzte Teilnehmer dort eingetragen wird .
        // Danach wird der Vektor um das letzte Element verkürzt.
        // (Iteratoren wurden noch nicht behandelt.)
        zuModifizieren[i] = zuModifizieren[zuModifizieren.size() - 1];
        zuModifizieren.pop_back();
        break;
      }
    }
  }
}

void Teilnehmer::lerntKennen(Teilnehmer& tn) {
  if (&tn != this       // 'sich selbst kennenlernen' ignorieren
      && !kennt(tn)) {  // wenn noch unbekannt, eintragen
    dieBekannten.push_back(&tn);
    tn.lerntKennen(*this);  // wechselseitig kennenlernen
  }
}

bool Teilnehmer::kennt(const Teilnehmer& tn) const {
  bool erg{false};
  for (auto bekannte : dieBekannten) {
    if (&tn == bekannte) {
      erg = true;
      break;
    }
  }
  return erg;
}

void Teilnehmer::druckeBekannte() const {
  for (auto bekannte : dieBekannten) {
    std::cout << "  " << bekannte->gibNamen();
  }
  std::cout << '\n';
}

const std::string& Teilnehmer::gibNamen() const { return name; }
