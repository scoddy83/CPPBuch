/* cppbuch/k8/new/waechter/Waechter.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef WAECHTER_H
#define WAECHTER_H
#include "ZaehlendesObjekt.h"

class Waechter {
public:
  Waechter() = default;
  ~Waechter() {
    if (ZaehlendesObjekt::objekte.size() > 0) {
      std::cerr << "Es fehlen " << ZaehlendesObjekt::objekte.size()
                << " delete-Anweisungen!\n";
    }
  }
  Waechter(const Waechter&) = delete;  // Kopie nicht gewünscht
  Waechter& operator=(const Waechter&) = delete;  // Zuweisung nicht gewünscht
};

#endif
