/* cppbuch/k7/logik/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstdlib>
#include <iostream>
//#define NDEBUG 1       // ggf. Abschalten der Zusicherungen mit NDEBUG
#include "assertex.h"

class GleichNull {       // Exception-Klasse ohne Konstruktor-Parameter
public:
  auto what() const { return "Fehler GleichNull entdeckt"; }
};

class UngleichEins {     // Exception-Klasse mit Konstruktor-Parameter
public:
  UngleichEins(int i) : zahl{i} {
  }

  auto what() const { 
    return "Fehler UngleichEins entdeckt"; 
  }

  auto wieviel() const { 
    return zahl; 
  }

private:
  int zahl;
};

using namespace std;

int main() {
  int i;
  cout << "0            : GleichNull-Fehler\n"
       << "1            : normales Ende\n"
       << "!= 1         : UngleichEins-Fehler\n i = ?";
  cin >> i;

  try {
    Assert(i, GleichNull());
    Assert(i == 1, UngleichEins(i));
  }
  catch (const GleichNull& fehlerObjekt) {
    cerr << fehlerObjekt.what() << "\n keine weitere Fehlerbehandlung\n";
  }
  catch (const UngleichEins& fehlerObjekt) {
    cerr << fehlerObjekt.what() << '\n'
         << fehlerObjekt.wieviel() << "! Abbruch\n";
    exit(1);  // Programmabbruch
  }
  cout << "normales Programmende mit i =" << i << '\n';
#ifdef NDEBUG
  cout << "NDEBUG ist gesetzt: Assert ist abgeschaltet.\n";
#endif
}
