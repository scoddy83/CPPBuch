/* cppbuch/include/datum.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef DATUM_H
#define DATUM_H
#include <cstddef>
#include <ctime>
#include <iostream>
#include <string>
#include <ungueltigesdatumexception.h>

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
  Datum() {  // Standardkonstruktor
    aktuell();
  }
  constexpr Datum(std::size_t t, std::size_t m,
                  std::size_t j)  // allgemeiner Konstruktor
      : tag_(t), monat_(m), jahr_(j) {
    if (!istGueltigesDatum(t, m, j)) {
      throw UngueltigesDatumException(t, m, j);
    }
  }
  constexpr std::size_t tag() const { return tag_; }
  constexpr std::size_t monat() const { return monat_; }
  constexpr std::size_t jahr() const { return jahr_; }
  constexpr bool istSchaltjahr() const {
    return ::istSchaltjahr(jahr_);  // globale Funktion mit \tt{::}-Operator
  }

  void set(std::size_t t, std::size_t m, std::size_t j) {
    if (!istGueltigesDatum(t, m, j)) {
      throw UngueltigesDatumException(t, m, j);
    }
    tag_ = t;
    monat_ = m;
    jahr_ = j;
  }

  void aktuell() {  // Systemdatum setzen
    // \tt{time\_t, time(), tm, localtime()} sind in <ctime>
    // deklariert
    std::time_t now{std::time(NULL)};  // aktuelle Zeit in s seit 1.1.1970
    std::tm* z{
        std::localtime(&now)};  // Zeiger auf eine vordefinierte Struktur des
    // Typs \tt{tm}.
    jahr_ = z->tm_year + 1900;
    monat_ = z->tm_mon + 1;  // \tt{localtime} liefert 0..11
    tag_ = z->tm_mday;
  }

  Datum& operator++() {  // Tag hochzählen, präfix
    ++tag_;
    if (!istGueltigesDatum(tag_, monat_, jahr_)) {  // Monatsende erreicht?
      tag_ = 1;
      if (++monat_ > 12) {  // Jahresende erreicht?
        monat_ = 1;
        ++jahr_;
      }
    }
    return *this;
  }

  Datum operator++(int) {  // Tag hochzählen, postfix
    Datum temp = *this;
    ++*this;  // Präfix ++ aufrufen
    return temp;
  }

  // alternativ: durch Methode string toString() ersetzen (siehe
  // Übungsaufgabe)
  explicit operator std::string() const {  // Typumwandlungsoperator
    std::string temp("tt.mm.jjjj");
    // implizite Umwandlung in char
    temp[0] = tag_ / 10 + '0';
    temp[1] = tag_ % 10 + '0';
    temp[3] = monat_ / 10 + '0';
    temp[4] = monat_ % 10 + '0';
    std::size_t pos = 9;  // letzte Jahresziffer
    std::size_t j = jahr_;
    while (j > 0) {
      temp[pos] = j % 10 + '0';  // letzte Ziffer
      j = j / 10;                // letzte Ziffer abtrennen
      --pos;
    }
    return temp;
  }

private:
  std::size_t tag_;
  std::size_t monat_;
  std::size_t jahr_;
};

inline std::ostream& operator<<(std::ostream& os, const Datum& d) {
  os << d.tag() << '.' << d.monat() << '.' << d.jahr();
  return os;
}

constexpr bool operator==(const Datum& a, const Datum& b) {
  return a.tag() == b.tag() && a.monat() == b.monat() && a.jahr() == b.jahr();
}

constexpr bool operator!=(const Datum& a, const Datum& b) {
  return !(a == b);
}

constexpr bool operator<(const Datum& a, const Datum& b) {
  return a.jahr() < b.jahr() ||
         (a.jahr() == b.jahr() && a.monat() < b.monat()) ||
         (a.jahr() == b.jahr() && a.monat() == b.monat() &&
          a.tag() < b.tag());
}

inline int datumDifferenz(const Datum& a, const Datum& b) {
  if (a == b)  // kurzer Prozeß bei Gleichheit
    return 0;
  bool richtigeReihenfolge{a < b};
  Datum frueher{a};
  Datum spaeter{b};
  if (!richtigeReihenfolge) {  // ggf. vertauschen
    frueher = b;
    spaeter = a;
  }
  int differenz{0};
  // Achtung! nicht optimiert! (tageweises Hochzählen)
  while (frueher != spaeter) {
    ++differenz;
    ++frueher;
  }
  return richtigeReihenfolge ? differenz : -differenz;
}

#endif
