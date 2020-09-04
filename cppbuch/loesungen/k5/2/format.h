/* cppbuch/loesungen/k5/2/format.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef FORMAT_H
#define FORMAT_H
#include <string>

class Format {
public:
  Format(unsigned int weite, unsigned int nachk);
  std::string toString(double d) const;

private:
  unsigned int weite;
  unsigned int nachkommastellen;
};
#endif
