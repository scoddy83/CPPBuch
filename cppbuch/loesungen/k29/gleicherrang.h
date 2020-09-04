/* cppbuch/loesungen/k29/gleicherrang.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef GLEICHERRANG_H
#define GLEICHERRANG_H
#include <string>
#include <utility>

class GleicherRang {
public:
  GleicherRang(int r) : rang(r) {}
  bool
  operator()(const std::pair<int, std::string>& p) const {  // für count_if
    return p.first == rang;
  }

private:
  int rang;
};

#endif
