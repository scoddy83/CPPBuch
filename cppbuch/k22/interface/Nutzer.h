/* cppbuch/k22/interface/Nutzer.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef NUTZER_H
#define NUTZER_H
#include "Daten.h"
#include "SchnittstelleX.h"

class Nutzer {
public:
  Nutzer(SchnittstelleX& a) : anbieter(a) { daten.wert = 99; }
  void nutzen() { anbieter.service(daten); }
  int getDaten() const { return daten.wert; }

private:
  Daten daten;
  SchnittstelleX& anbieter;
};

#endif
