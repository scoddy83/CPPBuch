/* cppbuch/loesungen/k5/1/meinstring.h
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
  std::size_t length() const {
    return daten.size() - 1;
  }                                                   // Anzahl der Zeichen
  const char* c_str() const { return daten.data(); }  // C-String zurückgeben
  void swap(MeinString&);                             // vertauschen
  // Zur Aufgabe:
  void insert(std::size_t pos, const MeinString& m);

private:
  std::vector<char> daten;
};

void anzeigen(std::ostream& os, const MeinString& m);

#endif
