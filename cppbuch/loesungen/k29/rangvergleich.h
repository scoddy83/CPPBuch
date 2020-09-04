/* cppbuch/loesungen/k29/rangvergleich.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef RANGVERGLEICH_H
#define RANGVERGLEICH_H
#include <string>
#include <utility>

class Rangvergleich {
public:
  bool operator()(
      const std::pair<int, std::string>& p1,
      const std::pair<int, std::string>& p2) const {  // für equal_range
    return p1.first > p2.first;
  }
};

#endif
