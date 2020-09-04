/* cppbuch/k30/geld/Geld.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef GELD_H
#define GELD_H
#include <iostream>

class Geld {
public:
  Geld(long int b = 0L);
  long int getBetrag() const;

private:
  long int betrag;
};

std::istream& operator>>(std::istream& is, Geld& G);
std::ostream& operator<<(std::ostream& os, const Geld& G);
#endif
