/* cppbuch/k30/datum/datumlocale.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "datumlocale.h"
#include <sstream>

// neu:
std::ostream& operator<<(std::ostream& os, const Datum& d) {
  std::ostream::sentry s(os);
  if (s) {
    struct std::tm t;
    t.tm_mday = d.tag();
    t.tm_mon = d.monat() - 1;
    t.tm_year = d.jahr() - 1900;
    std::use_facet<std::time_put<char>>(os.getloc())
        .put(os, os, ' ', &t, 'x');  // x : siehe strftime :locale~s
    // appropriate date representation
  }
  return os;
}

// neu
std::string Datum::toString(const std::locale& loc) const {
  std::ostringstream oss;
  oss.imbue(loc);
  oss << *this;  // Benutzung des obigen operator<<()
  return oss.str();
}

// neu:
std::istream& operator>>(std::istream& is, Datum& d) {
  std::istream::sentry s(is);
  if (s) {
    std::ios_base::iostate fehler = std::ios_base::goodbit;
    struct std::tm t;
    std::use_facet<std::time_get<char>>(is.getloc())
        .get_date(is, 0, is, fehler, &t);
    if (!fehler) {
      d = Datum(t.tm_mday, t.tm_mon + 1, t.tm_year + 1900);
    }
    is.setstate(fehler);
  }
  return is;
}
