/* cppbuch/k28/bezeichnerlesen/identifier.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef IDENTIFIER_H
#define IDENTIFIER_H
#include <cctype>
#include <iostream>
#include <string>

class Identifier : public std::string {};

inline std::istream& operator>>(std::istream& is, Identifier& identifier) {
  identifier.assign("");  // alten Inhalt löschen
  char c = '\0';
  while (is && !(isalpha(c) || '_' == c)) {  // Wortanfang finden
    is.get(c);
  }
  identifier += c;
  // Wenn der Anfang gefunden wurde, werden alle folgenden
  // Unterstriche und
  // alphanumerische Zeichen gesammelt. Whitespace oder
  // Sonderzeichen
  // beenden den Leseprozess.
  while (is && (isalnum(c) || '_' == c)) {
    is.get(c);
    if (isalnum(c) || '_' == c)
      identifier += c;
  }
  // Das letzte Zeichen gehört nicht zum Identifier und wird deshalb
  is.putback(c);  // in den Stream zurückgeschrieben.
  return is;
}

#endif
