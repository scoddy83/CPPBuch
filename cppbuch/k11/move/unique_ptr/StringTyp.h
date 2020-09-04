/* cppbuch/k11/move/unique_ptr/StringTyp.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef STRINGTYP_H
#define STRINGTYP_H
#include <cstddef>   // size_t
#include <cstring>   // strlen()
#include <iostream>  // ostream, cout
#include <memory>    // unique_ptr
#include <utility>   // swap

class StringTyp {
public:
  StringTyp(const char* s)
      : len{std::strlen(s)}, start{std::make_unique<char[]>(len + 1)} {
    std::strcpy(start.get(), s);
  }

  StringTyp(const StringTyp& s)
      : len{s.len}, start{std::make_unique<char[]>(len + 1)} {
    std::strcpy(start.get(), s.start.get());
  }

  StringTyp(StringTyp&& s) =
      default;  // bewegender Konstruktor (resource stealing)

  StringTyp& operator=(const StringTyp& s) {
    StringTyp tmp(s);
    swap(tmp);
    return *this;
  }

  StringTyp&
  operator=(StringTyp&& s) = default;  // bewegender Zuweisungsoperator

  StringTyp& operator+=(const StringTyp& s) {
    std::unique_ptr<char[]> temp = std::make_unique<char[]>(len + s.len + 1);
    std::strcpy(temp.get(), start.get());          // Teil 1 kopieren
    std::strcpy(temp.get() + len, s.start.get());  // Teil 2 kopieren
    len += s.len;            // Verwaltungsinformation aktualisieren
    std::swap(start, temp);  // Verwaltungsinformation aktualisieren
    return *this;
  }

  const char* c_str() const { return start.get(); }  // C-String zurückgeben

  StringTyp& insert(std::size_t pos,
                    const StringTyp& s) {  // s vor Position pos einfügen
    std::unique_ptr<char[]> temp = std::make_unique<char[]>(len + s.len + 1);
    std::strncpy(temp.get(), start.get(),
                 pos);  // die ersten pos Zeichen kopieren
    std::strncpy(temp.get() + pos, s.start.get(), s.len);  // s einfügen
    std::strcpy(temp.get() + pos + s.len,
                start.get() + pos);  // Rest kopieren
    len += s.len;                    // Verwaltungsinformation aktualisieren
    std::swap(start, temp);          // Verwaltungsinformation aktualisieren
    return *this;
  }

  void swap(StringTyp& m) {
    std::swap(start, m.start);
    std::swap(len, m.len);
  }

private:
  std::size_t len;                // Länge
  std::unique_ptr<char[]> start;  // Zeiger auf den Anfang
};

inline std::ostream& operator<<(std::ostream& os, const StringTyp& s) {
  os << s.c_str();
  return os;
}

inline StringTyp operator+(const StringTyp& x, const StringTyp& y) {
  StringTyp temp(x);
  temp += y;
  return temp;
}

// dito, wenn temporäre Objekte beteiligt sind.
inline StringTyp operator+(StringTyp&& x, const StringTyp& y) {
  return std::move(x += y);
}

inline StringTyp operator+(const StringTyp& x, StringTyp&& y) {
  return std::move(y.insert(0, x));
}

inline StringTyp operator+(StringTyp&& x, StringTyp&& y) {
  return std::move(x += y);
}

#endif
