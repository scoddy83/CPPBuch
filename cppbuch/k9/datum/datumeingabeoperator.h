/* cppbuch/k9/datum/datumeingabeoperator.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef DATUMEINGABEOPERATOR_H
#define DATUMEINGABEOPERATOR_H
#include <datum.h>
#include <iostream>

std::istream& operator>>(std::istream& eingabe, Datum& d);

#endif
