/* cppbuch/k7/logik/assertex.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ASSERTEX_H
#define ASSERTEX_H

#ifdef NDEBUG
#define Assert(bedingung, ausnahme) ;  // Leeranweisung
#else
#define Assert(bedingung, ausnahme)                                          \
  if (!(bedingung))                                                          \
  throw ausnahme
#endif
#endif
