/* cppbuch/loesungen/k3/3/IntMenge.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "IntMenge.h"
#include <cassert>
#include <iostream>

IntMenge::IntMenge() : anzahl{0} {}

void IntMenge::hinzufuegen(int el) {
  if (!istMitglied(el)) {  // ansonsten ignorieren
    if (anzahl < vec.size()) {
      vec[anzahl] = el;
    } else {  // Platz reicht nicht
      vec.push_back(el);
    }
    ++anzahl;
  }
}

void IntMenge::entfernen(int el) {
  int wo = finden(el);
  if (wo > -1) {
    vec[wo] = vec[--anzahl];  // letztes Element umkopieren
  }
}

bool IntMenge::istMitglied(int el) const { return finden(el) > -1; }

std::size_t IntMenge::size() const { return anzahl; }

void IntMenge::anzeigen() const {
  for (std::size_t i = 0; i < anzahl; ++i) {
    std::cout << vec[i] << "   ";
  }
  std::cout << '\n';
}

void IntMenge::loeschen() { anzahl = 0; }

int IntMenge::finden(int el) const {
  for (std::size_t i = 0; i < anzahl; ++i) {
    if (vec[i] == el)
      return i;
  }
  return -1;  // nicht gefunden
}

int IntMenge::getMin() const {
  assert(anzahl > 0);
  int erg = vec[0];
  for (std::size_t i = 1; i < anzahl; ++i) {
    if (vec[i] < erg)
      erg = vec[i];
  }
  return erg;
}

int IntMenge::getMax() const {
  assert(anzahl > 0);
  int erg = vec[0];
  for (std::size_t i = 1; i < anzahl; ++i) {
    if (vec[i] > erg)
      erg = vec[i];
  }
  return erg;
}
