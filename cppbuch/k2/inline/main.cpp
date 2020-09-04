/* cppbuch/k2/inline/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Erste Übersetzungseinheit
#include "inline.h"
#include "prog.h"

int main() {
  globaleVariable = 42;  // Wert ändern
  prog();                // Aufruf einer Funktion einer anderen  Übersetzungseinheit
}

