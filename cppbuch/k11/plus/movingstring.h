/* cppbuch/k11/plus/movingstring.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef MOVINGSTRING_H
#define MOVINGSTRING_H
#include <cstddef>   // size_t
#include <cstring>   // strlen()
#include <iostream>  // ostream
#include <utility>

// Hilfstyp zur Optimierung der Addition

class StringTyp;
using Plus = std::pair<const StringTyp&, const StringTyp&>;

// ggf auskommentieren
#define TEST

#ifdef TEST
namespace {
unsigned int anzahlNew = 0;
}
#define TESTAUSGABE_NEW(x) std::cout << #x << ' ' << ++anzahlNew << std::endl;
#define TESTAUSGABE(x) std::cout << #x << std::endl;
#else
#define TESTAUSGABE_NEW(x) /* nichts */
#define TESTAUSGABE(x)     /* nichts */
#endif

class StringTyp {
public:
  StringTyp(const char* s) : len{std::strlen(s)}, start{new char[len + 1]} {
    TESTAUSGABE_NEW(StringTyp(const char* s) : new)
    std::strcpy(start, s);
  }

  StringTyp(const StringTyp& s) : len{s.len}, start{new char[len + 1]} {
    TESTAUSGABE_NEW(StringTyp(const StringTyp& s) : new)
    std::strcpy(start, s.start);
  }

  // neu
  StringTyp(StringTyp&& s)  // bewegender Konstruktor (resource stealing)
      : len{s.len}, start{s.start} {  // Speicher übernehmen
    TESTAUSGABE(StringTyp(const StringTyp&& s) : move)
    s.start = nullptr;  // nicht vergessen (Destruktor)
  }

  ~StringTyp() { delete[] start; }

  // geändert: Übergabe per const&, andernfalls Zweideutigkeit
  StringTyp& operator=(const StringTyp& s) {
    TESTAUSGABE(= (const&)aufgerufen)
    StringTyp tmp(s);
    swap(tmp);
    return *this;
  }

  // neu
  StringTyp& operator=(StringTyp&& s) {  // bewegender Zuweisungsoperator
    TESTAUSGABE(= (&&)aufgerufen(move))
    delete[] start;
    start = s.start;  // resource stealing
    s.start = 0;
    len = s.len;
    return *this;
  }

  /*
  // alternativ:
  StringTyp& operator=(StringTyp&& s) { // bewegender
  Zuweisungsoperator
  TESTAUSGABE(=(&&) aufgerufen (move))
  swap(s);  // Ressourcen und Verwaltungsinformationen tauschen
  return *this;
  }
  */

  StringTyp& operator+=(const StringTyp& s) {
    char* temp = new char[len + s.len + 1];  // neuen Platz beschaffen
    TESTAUSGABE_NEW(operator+=(const StringTyp& s) : new)
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
    TESTAUSGABE_NEW(insert(std::size_t pos, const StringTyp& s) : new)
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

  // Zusatz für  Plus

  StringTyp(const Plus& pa)  // Konstruktor für Plus
      : len{pa.first.len + pa.second.len},
        start{new char[len + 1]} {                       //  Platz beschaffen
    std::strcpy(start, pa.first.start);                  // Teil 1 kopieren
    std::strcpy(start + pa.first.len, pa.second.start);  // Teil 2 kopieren
    TESTAUSGABE_NEW(StringTyp(const Plus& pa) new)
  }

  StringTyp& operator=(const Plus& pa) {  // Plus auswerten
    StringTyp temp(pa);  // Kopierkonstruktor für \tt{Plus}-Argument
    swap(temp);          // \tt{*this} mit \tt{temp} vertauschen
    TESTAUSGABE(StringTyp::operator=(const Plus& pa) swap)
    return *this;
  }

private:
  std::size_t len;  // Länge
  char* start;      // Zeiger auf den Anfang
};

inline std::ostream& operator<<(std::ostream& os, const StringTyp& s) {
  os << s.c_str();
  return os;
}

/* wird ersetzt
inline StringTyp operator+(const StringTyp& x, const StringTyp& y) {
...
}
*/

Plus operator+(const StringTyp& x, const StringTyp& y) {
  TESTAUSGABE(+(const&, const&)aufgerufen)
  return Plus(x, y);
}

// neu
inline StringTyp operator+(StringTyp&& x, const StringTyp& y) {
  TESTAUSGABE(+(&&, const&)aufgerufen(move))
  return std::move(x += y);
}

inline StringTyp operator+(const StringTyp& x, StringTyp&& y) {
  TESTAUSGABE(+(const&, &&)aufgerufen(move))
  // return std::move(StringTyp(x) += y);  besser, weil 1 new
  // weniger:
  return std::move(y.insert(0, x));
}

inline StringTyp operator+(StringTyp&& x, StringTyp&& y) {
  TESTAUSGABE(+(&&, &&)aufgerufen(move))
  return std::move(x += y);
}

#endif  // movingstring.h
