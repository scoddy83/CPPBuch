/* cppbuch/k11/move/movingstring.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef MOVINGSTRING_H
#define MOVINGSTRING_H
#include <cstddef>   // size_t
#include <cstring>   // strlen()
#include <iostream>  // ostream, cout
#include <utility>   // swap

// ggf auskommentieren
#define STDMOVE  // return std::move() statt return bei op+(,), siehe unten
#define TEST

#ifdef TEST
namespace {
unsigned int anzahlNew = 0;
}
#define TESTAUSGABE(x) std::cout << #x << ' ' << ++anzahlNew << std::endl;
#define TESTAUSGABE_NEUTRAL(x) std::cout << #x << std::endl;
#else
#define TESTAUSGABE(x)         /* nichts */
#define TESTAUSGABE_NEUTRAL(x) /* nichts */
#endif

class StringTyp {
public:
  StringTyp(const char* s) : len{std::strlen(s)}, start{new char[len + 1]} {
    TESTAUSGABE(StringTyp(const char* s) : new)
    std::strcpy(start, s);
  }

  StringTyp(const StringTyp& s) : len{s.len}, start{new char[len + 1]} {
    TESTAUSGABE(StringTyp(const StringTyp& s) : new)
    std::strcpy(start, s.start);
  }

  // neu
  StringTyp(StringTyp&& s)  // bewegender Konstruktor (resource stealing)
      : len{s.len}, start{s.start} {  // Speicher übernehmen
    TESTAUSGABE_NEUTRAL(StringTyp(const StringTyp&& s) : move)
    s.start = nullptr;  // nicht vergessen (Destruktor)
  }

  ~StringTyp() { delete[] start; }

  // geändert: Übergabe per const&, andernfalls Zweideutigkeit
  StringTyp& operator=(const StringTyp& s) {
    TESTAUSGABE_NEUTRAL(= (const&)aufgerufen)
    StringTyp tmp(s);  // new wird hier hochgezählt
    swap(tmp);
    return *this;
  }

  // neu
  StringTyp& operator=(StringTyp&& s) {  // bewegender Zuweisungsoperator
    TESTAUSGABE_NEUTRAL(= (&&)aufgerufen(move))
    delete[] start;
    start = s.start;  // resource stealing
    s.start = nullptr;
    len = s.len;
    return *this;
  }

  /*
  // alternativ:
  StringTyp& operator=(StringTyp&& s) { // bewegender
  Zuweisungsoperator
  TESTAUSGABE_NEUTRAL(=(&&) aufgerufen (move))
  swap(s);  // Ressourcen und Verwaltungsinformationen tauschen
  return *this;
  }
  */

  StringTyp& operator+=(const StringTyp& s) {
    char* temp = new char[len + s.len + 1];  // neuen Platz beschaffen
    TESTAUSGABE(operator+=(const StringTyp& s) : new)
    std::strcpy(temp, start);          // Teil 1 kopieren
    std::strcpy(temp + len, s.start);  // Teil 2 kopieren
    delete[] start;                    // alten Platz freigeben
    len += s.len;                      // Verwaltungsinformation aktualisieren
    start = temp;
    return *this;
  }

  const char* c_str() const { return start; }  // C-String zurückgeben

  StringTyp& insert(std::size_t pos,
                    const StringTyp& s) {    // s vor Position pos einfügen
    char* temp = new char[len + s.len + 1];  // neuen Platz beschaffen
    TESTAUSGABE(insert(std::size_t pos, const StringTyp& s) : new)
    std::strncpy(temp, start, pos);  // die ersten pos Zeichen kopieren
    std::strncpy(temp + pos, s.start, s.len);      // s einfügen
    std::strcpy(temp + pos + s.len, start + pos);  // Rest kopieren
    delete[] start;                                // alten Platz freigeben
    start = temp;  // Verwaltungsinformation aktualisieren
    len += s.len;  // Verwaltungsinformation aktualisieren
    return *this;
  }
  void swap(StringTyp& m) {
    std::swap(start, m.start);
    std::swap(len, m.len);
  }

private:
  std::size_t len;  // Länge
  char* start;      // Zeiger auf den Anfang
};

inline std::ostream& operator<<(std::ostream& os, const StringTyp& s) {
  os << s.c_str();
  return os;
}

inline StringTyp operator+(const StringTyp& x, const StringTyp& y) {
  TESTAUSGABE_NEUTRAL(+(const&, const&)aufgerufen)
  StringTyp temp(x);
  temp += y;
  return temp;
}

#ifdef STDMOVE
// neu
// dito, wenn temporäre Objekte beteiligt sind.
inline StringTyp operator+(StringTyp&& x, const StringTyp& y) {
  TESTAUSGABE_NEUTRAL(Op2 : +(&&, const&)aufgerufen(move))
  return std::move(x += y);
}

inline StringTyp operator+(const StringTyp& x, StringTyp&& y) {
  TESTAUSGABE_NEUTRAL(Op3 : +(const&, &&)aufgerufen(move))
  // return std::move(StringTyp(x) += y);  besser, weil 1 new weniger:
  return std::move(y.insert(0, x));
}

inline StringTyp operator+(StringTyp&& x, StringTyp&& y) {
  TESTAUSGABE_NEUTRAL(Op4 : +(&&, &&)aufgerufen(move))
  return std::move(x += y);
}
#else
// neu
// dito, wenn temporäre Objekte beteiligt sind.
inline StringTyp operator+(StringTyp&& x, const StringTyp& y) {
  TESTAUSGABE_NEUTRAL(+(&&, const&)aufgerufen(move))
  return x += y;
}

inline StringTyp operator+(const StringTyp& x, StringTyp&& y) {
  TESTAUSGABE_NEUTRAL(+(const&, &&)aufgerufen(move))
  // return  StringTyp(x) += y; besser, weil 1 new weniger:
  return y.insert(0, x);
}

inline StringTyp operator+(StringTyp&& x, StringTyp&& y) {
  TESTAUSGABE_NEUTRAL(+(&&, &&)aufgerufen(move))
  return x += y;
}

#endif

#endif  // movingstring.h
