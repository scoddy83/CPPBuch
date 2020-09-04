/* cppbuch/k23/strings/split.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef SPLIT_H
#define SPLIT_H
#include <string>
#include <vector>

inline 
auto split(const std::string& s, const std::string& trenn) {
  std::vector<std::string> ergebnis;
  std::string::size_type start{0};
  std::string::size_type pos;
  do {
    pos = s.find_first_of(trenn, start);
    ergebnis.push_back(s.substr(start, pos - start));
    start = pos + 1;
  } while (pos != std::string::npos);
  return ergebnis;
}
#endif
