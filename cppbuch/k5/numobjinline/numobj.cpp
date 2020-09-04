/* cppbuch/k5/numobjinline/numobj.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Implementation der Klasse  NummeriertesObjekt
#include "numobj.h"
#include <cassert>
#include <iostream>

// Default-Konstruktor
NummeriertesObjekt::NummeriertesObjekt() : serienNr{++maxNummer} {
  ++anz;
  if (testmodus) {
    if (serienNr == 1) {
      std::cout << "Start der Objekterzeugung!\n";
    }
    std::cout << "  Objekt Nr. " << serienNr << " erzeugt\n";
  }
}
// Kopierkonstruktor
NummeriertesObjekt::NummeriertesObjekt(const NummeriertesObjekt& nobj)
    : serienNr{++maxNummer} {
  ++anz;

  if (testmodus) {
    std::cout << "  Objekt Nr. " << serienNr << " mit Nr. " << nobj.seriennummer()
              << " initialisiert\n";
  }
}

// Destruktor
NummeriertesObjekt::~NummeriertesObjekt() {
  anz--;
  if (testmodus) {
    std::cout << "  Objekt Nr. " << serienNr << " gelöscht\n";

    if (anz == 0) {
      std::cout << "letztes Objekt gelöscht!\n";
    }
    if (anz < 0) {
      std::cout << " FEHLER! zu oft delete aufgerufen!\n";
    }
  } else {
    assert(anz >= 0);
  }
}  // Ende von numobj.cpp
