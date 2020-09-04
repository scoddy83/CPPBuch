/* cppbuch/loesungen/k5/1/meinstring.cpp
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
    daten.resize(neueLaenge);         // Länge anpassen
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

void MeinString::insert(std::size_t pos, const MeinString& m) {
  std::size_t len = length();  // alten Wert von length() retten
  if (pos > len) {             // zu groß
    pos = len;                 // begrenzen, d.h. am Ende einfügen
  }
  std::size_t neuesende = len + m.length();
  daten.resize(neuesende + 1);  // Platz schaffen und mit Nullbytes
                                // auffüllen, falls notwendig,
  // Auf pos folgende Zeichen verschieben, um Platz zu schaffen:
  for (std::size_t anz = 0; anz <= len - pos; ++anz) {
    daten[neuesende] = daten[neuesende - m.length()];
    --neuesende;
  }
  // m einfügen
  for (std::size_t i = 0; i < m.length(); ++i) {
    daten[pos + i] = m.at(i);
  }
  // alternativ: copy() mit #include<algorithm>, siehe ggf Register:
  // std::copy(m.c_str(), m.c_str() + m.length(), daten.begin() +
  // pos);
}

void anzeigen(std::ostream& os, const MeinString& m) { os << m.c_str(); }
