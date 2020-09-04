/* cppbuch/k11/move/einfacherstring.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef EINFACHERSTRING_H
#define EINFACHERSTRING_H
#include <cstddef>   // size_t
#include <cstring>   // strlen()
#include <iostream>  // ostream

// ggf auskommentieren
#define TEST

#ifdef TEST
namespace {
unsigned int anzahlNew = 0;
}
#define TESTAUSGABE(x) std::cout << #x << ' ' << ++anzahlNew << std::endl;
#else
#define TESTAUSGABE(x) /* nichts */
#endif

class StringTyp {
public:
  StringTyp(const char* s)                     // Konstruktor
    : len{std::strlen(s)}, start{new char[len+1]} {
      TESTAUSGABE(StringTyp(const char* s) : new)
      std::strcpy(start, s);
    }

  StringTyp(const StringTyp& s)                // Kopierkonstruktor
    : len{s.len}, start{new char[len+1]} {
      TESTAUSGABE(StringTyp(const StringTyp& s) : new)
      std::strcpy(start, s.start);
    }

  ~StringTyp() {                               // Destruktor
    delete [] start;
  }

  StringTyp& operator=(StringTyp s) {          // Zuweisungsoperator
    swap(s);
    return *this;
  }

  StringTyp& operator+=(const StringTyp& s) {  // Verkettungsoperator
    TESTAUSGABE(operator+=(const StringTyp& s) : new)
    char* temp {new char[len + s.len +1]};    // neuen Platz beschaffen
    std::strcpy(temp, start);                 // Teil 1 kopieren
    std::strcpy(temp + len, s.start);         // Teil 2 kopieren
    delete [] start;                          // alten Platz freigeben
    len += s.len;                             // Verwaltungsinformation aktualisieren
    start = temp;
    return *this;
  }

  const char* c_str() const { return start;}   // C-String zurückgeben

  void swap(StringTyp& m) {                    // vertauschen
    std::swap(start, m.start);
    std::swap(len, m.len);
  }
private:
  std::size_t len;                             // Länge
  char *start;                                 // Zeiger auf den Anfang
};

// Ausgabeoperator
inline std::ostream& operator<<(std::ostream &os, const StringTyp& s) {
  os << s.c_str();
  return os;
}

// binärer Verkettungsoperator
inline StringTyp operator+(StringTyp a, const StringTyp& b) {
  return a += b;
}
#endif
