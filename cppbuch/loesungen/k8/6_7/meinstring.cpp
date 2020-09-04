/* cppbuch/loesungen/k8/6_7/meinstring.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "meinstring.h"
#include <cassert>
#include <cstring>  // strlen()

/* Der allgemeine Konstruktor erzeugt aus einem klassischen C-String
ein
\tt{MeinString}-Objekt.
*/
MeinString::MeinString(const char* s)  // allg. Konstruktor
    : daten(std::strlen(s) + 1) {
  daten.assign(s, s + daten.size());
}

MeinString&
MeinString::assign(const char* s) {  // Zuweisung eines \tt{char*}
  std::size_t neueLaenge = strlen(s) + 1;
  if (length() >= neueLaenge) {       // genug Platz vorhanden
    daten.assign(s, s + neueLaenge);  // zuweisen
    daten.resize(neueLaenge);         // Länge anpassen (verkürzen))
  } else {
    MeinString temp(s);  // Objekt ausreichender Größe schaffen
    swap(temp);          // vertauschen
  }
  return *this;
}

char& MeinString::at(std::size_t position) {  // Zeichen per Referenz holen
  assert(position < length());  // Nullbyte lesen ist nicht erlaubt
  return daten[position];
}

const char& MeinString::at(std::size_t position) const {  // Zeichen holen
  assert(position < length());  // Nullbyte lesen ist nicht erlaubt
  return daten[position];
}

void MeinString::swap(MeinString& mString) {
  std::swap(daten, mString.daten);  // Bibliotheksfunktion
}

MeinString& MeinString::operator+=(const MeinString& m) {
  std::vector<char> temp(length() + m.length() + 1);  // Platz besorgen
  // Daten von *this OHNE Nullbyte kopieren:
  for (std::size_t i = 0; i < length(); ++i) {
    temp[i] = daten[i];
  }
  // Daten von m MIT abschließendem Nullbyte kopieren:
  for (std::size_t i = 0; i <= m.length(); ++i) {  // <= !
    temp[i + length()] = m.daten[i];
  }
  std::swap(temp, daten);
  return *this;
}

void anzeigen(std::ostream& os, const MeinString& m) { os << m.c_str(); }

const char& MeinString::
operator[](std::size_t position) const {  // Zeichen holen
  return daten[position];
}
char& MeinString::
operator[](std::size_t position) {  // Zeichen per Referenz holen
  return daten[position];
}

std::ostream& operator<<(std::ostream& os, const MeinString& m) {
  os << m.c_str();
  return os;
}

MeinString operator+(MeinString m1, const MeinString& m2) { return m1 += m2; }
