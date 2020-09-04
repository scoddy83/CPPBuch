/* cppbuch/k4/perzeigISO8859.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Diese Datei ist ISO 8859-1 codiert.
#include <iostream>
using namespace std;

void upcase(char*);  // Prototyp

int main() {
  char str[]{"gross 123 äöü"};  // siehe unten Kommentar zu Umlauten
  cout << str << '\n';
  upcase(str);
  cout << str << '\n';  // GROSS 123
}

void upcase(char* s) {
  constexpr int DIFFERENZ =
      'a' - 'A';  // In der ASCII-Tabelle sind die Platznummern
  // der Kleinbuchstaben um 'a'-'A' = 32 gegenüber den
  // Großbuchstaben
  // verschoben.

  while (*s) {
    if (*s >= 'a' && *s <= 'z') {
      *s -= DIFFERENZ;
    } else {
      // Lesbar, aber nicht auf jedem System: Umlaute sind nicht
      // portabel!
      // Der folgende Teil funktioniert nur dann, wenn dieses
      // Programm
      // vor
      // der Compilation dieselbe Zeichenkodierung hat wie das
      // Terminal und die Umlaute als ein Byte darstellbar sind, wie
      // etwa bei der
      // Zeichenkodierung ISO8859-1. Weitere Informationen finden
      // Sie
      // im Teil 5, Kapitel Nationale Besonderheiten.
      switch (*s) {
      case 'ä':
        *s = 'Ä';
        break;
      case 'ö':
        *s = 'Ö';
        break;
      case 'ü':
        *s = 'Ü';
        break;
      default:;
      }
    }
    ++s;
  }
}
