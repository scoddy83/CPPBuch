/* cppbuch/k22/interface/Anbieter.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ANBIETER_H
#define ANBIETER_H
#include "SchnittstelleX.h"
#include <iostream>

class Anbieter : public SchnittstelleX {
public:
  void service(Daten& d) {
    // ... Implementation der Schnittstelle
    d.wert *= 2;
    std::cout << "Anbieter.service() wird ausgeführt (Daten "
                 "verdoppeln)\n";
  }
};

#endif
