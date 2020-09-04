/* cppbuch/k8/new/zaehlend/ZaehlendesObjekt.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "ZaehlendesObjekt.h"

std::set<void*> ZaehlendesObjekt::objekte;
int ZaehlendesObjekt::gesamt{0};
