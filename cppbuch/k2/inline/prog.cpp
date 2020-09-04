/* cppbuch/k2/inline/prog.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Zweite Übersetzungseinheit
#include "prog.h"
#include "inline.h"

void prog() {
  std::cout << "inlineFunktion aus prog() aufgerufen: ";
  ausgabe(globaleVariable);
}

