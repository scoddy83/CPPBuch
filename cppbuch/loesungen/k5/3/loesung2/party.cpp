/* cppbuch/loesungen/k5/3/loesung2/party.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "teilnehmer.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  Teilnehmer otto("Otto");
  Teilnehmer andrea("Andrea");
  Teilnehmer jens("Jens");
  Teilnehmer silvana("Silvana");
  Teilnehmer miriam("Miriam");
  Teilnehmer paul("Paul");
  vector<Teilnehmer*> alle{&otto, &andrea, &jens, &silvana, &miriam, &paul};
  andrea.lerntKennen(jens);
  silvana.lerntKennen(otto);
  paul.lerntKennen(otto);
  paul.lerntKennen(silvana);
  miriam.lerntKennen(andrea);
  jens.lerntKennen(miriam);
  jens.lerntKennen(silvana);
  if (jens.kennt(andrea)) {
    cout << "Jens kennt Andrea\n";
  }
  // Ausgabe aller Teilnehmer mit Angabe, wer wen kennt:
  for (auto teilnehmerPtr : alle) {
    cout << teilnehmerPtr->gibNamen() << " kennt: ";
    teilnehmerPtr->druckeBekannte();
  }
  /***********/
  Teilnehmer dirac("Dirac");
  {
    dirac.lerntKennen(silvana);
    Teilnehmer pauli("Pauli");
    pauli.lerntKennen(dirac);
    cout << "Dirac kennt: ";
    dirac.druckeBekannte();
  }
  cout << "Dirac kennt: ";
  dirac.druckeBekannte();  // Pauli verschwunden
}
