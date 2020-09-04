/* cppbuch/include/ungueltigesdatumexception.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef UNGUELTIGESDATUMEXCEPTION_H
#define UNGUELTIGESDATUMEXCEPTION_H
#include <stdexcept>
#include <string>

class UngueltigesDatumException : public std::runtime_error {
public:
  UngueltigesDatumException(std::size_t t, std::size_t m, std::size_t j)
      : std::runtime_error(toString(t, m, j)) {}

private:
  static std::string toString(std::size_t tag, std::size_t monat,
                              std::size_t jahr) {
    std::string meldung = std::to_string(tag) + "." + std::to_string(monat) +
                          "." + std::to_string(jahr) +
                          " ist ein ungueltiges Datum!";
    return meldung;
  }
};
#endif
