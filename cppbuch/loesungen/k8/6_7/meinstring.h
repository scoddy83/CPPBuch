/* cppbuch/loesungen/k8/6_7/meinstring.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef MEINSTRING_H
#define MEINSTRING_H
#include <cstddef>   // \tt{size\_t}
#include <iostream>  // \tt{ostream}
#include <vector>

class MeinString {
public:
  MeinString(const char* str = "");            // allg. Konstruktor
  MeinString& assign(const char*);             // Zuweisung eines \tt{char*}
  const char& at(std::size_t position) const;  // Zeichen holen
  char& at(std::size_t position);              // Zeichen holen
  // Wegen des Rückgabetyps Referenz kann das Zeichen geändert
  // werden.
  std::size_t length() const {
    return daten.size() - 1;
  }                                                   // Anzahl der Zeichen
  const char* c_str() const { return daten.data(); }  // C-String zurückgeben
  void swap(MeinString&);                             // vertauschen
  const char& operator[](std::size_t position) const;  // Zeichen holen
  char& operator[](std::size_t position);              // Zeichen holen
  MeinString& operator+=(const MeinString& m);

private:
  std::vector<char> daten;
};

void anzeigen(std::ostream& os, const MeinString& m);

std::ostream& operator<<(std::ostream& os, const MeinString& m);

MeinString operator+(MeinString m1, const MeinString& m2);
#endif
