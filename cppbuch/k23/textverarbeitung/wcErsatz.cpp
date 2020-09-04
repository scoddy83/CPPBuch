/* cppbuch/k23/textverarbeitung/wcErsatz.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
//  Datei-Statistik
#include <cstdlib>  //  exit()
#include <cstring>
#include <fstream>
#include <iostream>
#include <locale>
using namespace std;

void zaehlen(const char* dateiname, size_t& zeilenzahl, size_t& wortzahl,
             size_t& zeichenzahl) {
  ifstream quelle(dateiname);
  if (!quelle) {  // muss existieren
    throw exception();
  }
  char c;
  zeichenzahl = wortzahl = zeilenzahl = 0;
  bool wort = false;

  while (quelle.good() && quelle.get(c)) {
    if (c == '\n') {
      ++zeilenzahl;
    } else {
      ++zeichenzahl;
    }
    if (isalpha(c)) {  // eingestellte locale wird beruecksichtigt
      wort = true;     // Wortanfang, oder  c ist in einem Wort
    } else {
      if (wort) {
        ++wortzahl;  // Wortende ueberschritten
      }
      wort = false;
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Gebrauch: wcErsatz.exe eingabe.txt\n";
    return 1;
  }
  locale::global(locale("de_DE"));  //  Umlaute beruecksichtigen

  size_t zeilenzahl = 0;
  size_t wortzahl = 0;
  size_t zeichenzahl = 0;
  try {
    zaehlen(argv[1], zeilenzahl, wortzahl, zeichenzahl);
  } catch (...) {
    cerr << "Fehler beim Öffnen der Datei!\n";
  }
  cout << "Anzahl der Zeichen (ohne Zeilenendekennung) = " << zeichenzahl
       << '\n';
  cout << "Anzahl der Worte   = " << wortzahl << '\n';
  cout << "Anzahl der Zeilen  = " << zeilenzahl << '\n';
}
