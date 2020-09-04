/* cppbuch/k8/datum/datum.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// NOCH NICHT VOLLSTÄNDIG (s. Übungsaufgaben)
#ifndef DATUM_H
#define DATUM_H
#include "ungueltigesdatumexception.h"
#include <cstddef>
#include <string>

constexpr bool istSchaltjahr(std::size_t jahr) {
  return (jahr % 4 == 0 && jahr % 100) || jahr % 400 == 0;
}

constexpr bool istGueltigesDatum(std::size_t tag, std::size_t monat,
                                 std::size_t jahr) {
  bool ergebnis = false;
  if ((monat >= 1 && monat <= 12) &&
      (jahr > 1582      // 1582: Beginn des  gregorianischen Kalenders
       && jahr < 2400)  // Plausibilitätskontrolle
      ) {
    std::size_t letzterTagImMonat = 29;        // nur Februar im Schaltjahr
    if (monat != 2 || !istSchaltjahr(jahr)) {  // sonst
      constexpr std::size_t tageImMonat[]{31, 28, 31, 30, 31, 30,
                                          31, 31, 30, 31, 30, 31};
      letzterTagImMonat = tageImMonat[monat - 1];
    }
    ergebnis = (tag >= 1 && tag <= letzterTagImMonat);
  }
  return ergebnis;
}

class Datum {
public:
  Datum();  // Standardkonstruktor
  constexpr Datum(std::size_t t, std::size_t m,
                  std::size_t j)  // allgemeiner Konstruktor
      : tag_(t), monat_(m), jahr_(j) {
    if (!istGueltigesDatum(t, m, j)) {
      throw UngueltigesDatumException(t, m, j);
    }
  }
  constexpr auto tag()   const { return tag_; }
  constexpr auto monat() const { return monat_; }
  constexpr auto jahr()  const { return jahr_; }
  constexpr bool istSchaltjahr() const {
    return ::istSchaltjahr(jahr_);  // globale Funktion mit \tt{::}-Operator
  }

  void set(std::size_t t, std::size_t m, std::size_t j);  // Datum setzen
  void aktuell();  // Systemdatum setzen

  Datum& operator++();    // Tag hochzählen, präfix
  Datum operator++(int);  // Tag hochzählen, postfix
  // alternativ: durch Methode string toString() ersetzen (siehe
  // Übungsaufgabe)
  explicit operator std::string() const;  // Typumwandlungsoperator
private:
  std::size_t tag_;
  std::size_t monat_;
  std::size_t jahr_;
};

#endif
