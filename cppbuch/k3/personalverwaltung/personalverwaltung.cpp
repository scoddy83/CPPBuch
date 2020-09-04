/* cppbuch/k3/personalverwaltung/personalverwaltung.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "personalverwaltung.h"
#include <fstream>
#include <iostream>

Personalverwaltung::Personalverwaltung(const std::string& dateiname) {
  std::ifstream daten(dateiname);
  while (daten) {
    std::string zeile;
    std::getline(daten, zeile);
    if (zeile == "#") {  // Endekennung gefunden
      break;
    }
    std::string name = zeile;
    std::getline(daten, zeile);
    // zeile enthaelt die personalnummer
    personal.push_back(Person(name, zeile));
  }
  daten.close();
}

void Personalverwaltung::ausgeben() const {
  if (personal.empty()) {
    std::cout << "keine Daten vorhanden!\n";
  } else {
    for (const auto& person : personal) {
      std::cout << person.getName() << " \t" << person.getPersonalnummer()
                << '\n';
    }
  }
}

void Personalverwaltung::dialog() const {
  while (true) {
    std::cout << "Personalnummer? (X = Ende):";
    std::string gesuchtePersonalNr;
    std::cin >> gesuchtePersonalNr;
    if (gesuchtePersonalNr == "X" || gesuchtePersonalNr == "x") {
      break;
    }
    bool gefunden = false;
    for (const auto& person : personal) {
      if (gesuchtePersonalNr == person.getPersonalnummer()) {
        std::cout << person.getName() << " gefunden.\n";
        gefunden = true;
        break;
      }
    }
    if (!gefunden) {
      std::cout << "nicht gefunden!\n";
    }
  }
}
