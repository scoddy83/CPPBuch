/* cppbuch/k8/new/waechter/ZaehlendesObjekt.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "ZaehlendesObjekt.h"
#include "Waechter.h"

std::set<void*> ZaehlendesObjekt::objekte;
int ZaehlendesObjekt::gesamt = 0;

Waechter w;
