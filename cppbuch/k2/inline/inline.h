/* cppbuch/k2/inline/inline.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef INLINE_H
#define INLINE_H
#include <iostream>

inline int globaleVariable = 3;

inline void ausgabe(int x) {
  std::cout << "inline-Funktion ausgabe(): " << x << '\n';
}

#endif
