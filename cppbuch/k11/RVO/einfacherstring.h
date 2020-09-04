/* cppbuch/k11/RVO/einfacherstring.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef EINFACHERSTRING_H
#define EINFACHERSTRING_H
#include <cstddef>   // \tt{size\_t}
#include <cstring>   // \tt{strlen()}
#include <iostream>  // \tt{ostream}

class StringTyp {
public:
  StringTyp(const char* s) : len(std::strlen(s)), start(new char[len + 1]) {
    std::strcpy(start, s);
  }
  StringTyp(const StringTyp& s) : len(s.len), start(new char[len + 1]) {
    std::strcpy(start, s.start);
    static std::size_t anzahlAufrufe = 0;
    std::cout << ++anzahlAufrufe
              << ". Aufruf des Kopierkonstruktors. Quelle= " << s.start
              << '\n';
  }
  ~StringTyp() { delete[] start; }
  StringTyp& operator=(StringTyp s) {
    swap(s);
    return *this;
  }
  StringTyp& operator+=(const StringTyp& s) {
    char* temp = new char[len + s.len + 1];  // neuen Platz beschaffen
    std::strcpy(temp, start);                // Teil 1 kopieren
    std::strcpy(temp + len, s.start);        // Teil 2 kopieren
    delete[] start;                          // alten Platz freigeben
    len += s.len;  // Verwaltungsinformation aktualisieren
    start = temp;
    return *this;
  }

  const char* c_str() const { return start; }  // C-String zurückgeben

private:
  std::size_t len;  // Länge
  char* start;      // Zeiger auf den Anfang
  void swap(StringTyp& m) {
    std::swap(start, m.start);
    std::swap(len, m.len);
  }
};

/* alt
inline StringTyp operator+(const StringTyp& a, const StringTyp& b) {
return StringTyp(a) += b;
}
*/
// neu
inline StringTyp operator+(StringTyp a, const StringTyp& b) { return a += b; }

#endif
