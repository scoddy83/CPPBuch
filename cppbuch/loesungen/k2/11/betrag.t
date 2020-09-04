/* cppbuch/loesungen/k2/11/betrag.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef BETRAG_T
#define BETRAG_T
#include <cstdlib>  // für exit()
#include <iostream>

// Das Template setzt voraus, dass die arithmetische Operation
// - (unäres Minus) für den Datentyp T definiert und sinnvoll ist.
// Für den Datentyp complex (für komplexe Zahlen) ist das nicht
// ausreichend.
template <typename T> T betrag(T t) { return (t < 0) ? -t : t; }

// Template-Spezialisierung
template <> char betrag(char c) {
  std::cerr << "Betrag von 'char' ist undefiniert\n";
  exit(1);
  return c;  // damit der Compiler zufrieden ist (wg. exit nicht
             // erreichbar)
}

// Template-Spezialisierung
template <> bool betrag(bool b) {
  std::cerr << "Betrag von 'bool' ist undefiniert\n";
  exit(1);
  return b;  // damit der Compiler zufrieden ist (wg. exit nicht
             // erreichbar)
}
#endif
